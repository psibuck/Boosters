#include "dealer.h"

#include "card.h"
#include "card_utilities.h"
#include "player.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include <windows.h>

// --------------------------------------------------------------------------
//! Constructor
// --------------------------------------------------------------------------
DEALER::DEALER()
{
	m_deck = std::make_unique<DECK>();
}

// --------------------------------------------------------------------------
//! Draw the top n cards
// --------------------------------------------------------------------------
void DEALER::draw( const int number_to_draw )
{
	int num_drawn = 0;
	while ( num_drawn < number_to_draw )
	{
		m_deck->at( num_drawn ).get()->print();
		num_drawn++;
	}
}

// --------------------------------------------------------------------------
//! Deals cards to the players
// --------------------------------------------------------------------------
void DEALER::deal_hand( std::vector<std::unique_ptr<PLAYER>>& players )
{
	shuffle();
	discard( m_deck->draw() );
	discard( m_deck->draw() );

	const int num_of_players = static_cast<int>( players.size() );
	for ( auto ite = 0; ite < num_of_players * HAND_SIZE; ite++ )
	{
		auto player = players.at( ite % num_of_players ).get();
		player->deal( m_deck->draw() );
	}
}

// --------------------------------------------------------------------------
//! Iterates through the players and scores their hands
// --------------------------------------------------------------------------
void DEALER::score_hand( const std::vector<std::unique_ptr<PLAYER>>& players ) const
{
	HAND_STRENGTH best_hand = HAND_STRENGTH::HIGH_CARD;
	PLAYER* winner = nullptr;
	bool split = false;
	for ( auto player_ite = players.begin(); player_ite != players.end(); ++player_ite )
	{
		const PLAYER* player = player_ite->get();
		const PLAYER_HAND& player_hand = player->get_hand();
		const HAND_STRENGTH player_hand_strength = card_utilities::get_hand_strength( player_hand );
		
		player->print();
		if ( player_hand_strength > best_hand )
		{
			winner = player_ite->get();
			best_hand = player_hand_strength;
			split = false;
		}
		else if ( winner && player_hand_strength == best_hand )
		{
			split = true;
		}
	}

	if ( split )
	{
		std::cout << "Split Pot!: " << card_utilities::get_hand_description( best_hand ) << std::endl;
	}
	else if ( winner )
	{
		std::cout << std::endl << winner->get_name() << " wins with " << card_utilities::calculate_hand_description( winner->get_hand() ) << std::endl;
	}
}

// --------------------------------------------------------------------------
//! Retrieves the cards back from the players
// --------------------------------------------------------------------------
void DEALER::collect_cards( std::vector<std::unique_ptr<PLAYER>>& players )
{
	for ( auto player_ite = players.begin(); player_ite != players.end(); ++player_ite )
	{
		PLAYER* player = player_ite->get();
		PLAYER_HAND& players_hand = player->muck_cards();
		for ( auto& card : players_hand )
		{
			discard( std::move( card ) );
		}
	}
	for ( auto discard_ite = m_discard_pile.begin(); discard_ite != m_discard_pile.end(); )
	{
		m_deck->add_card( std::move( *discard_ite ));
		discard_ite = m_discard_pile.erase( discard_ite );
	}
}

// --------------------------------------------------------------------------
//! Takes our deck and mixes it up
// --------------------------------------------------------------------------
void DEALER::shuffle()
{
	std::cout << std::endl << "* Shuffle *" << std::endl;
	std::random_device seed;
	std::shuffle( m_deck->begin(), m_deck->end(), seed );
}

// --------------------------------------------------------------------------
//! Moves a drawn card to the discard pile
// --------------------------------------------------------------------------
void DEALER::discard( std::unique_ptr<CARD>&& card_to_discard )
{
	m_discard_pile.push_back( std::move( card_to_discard ) );
}