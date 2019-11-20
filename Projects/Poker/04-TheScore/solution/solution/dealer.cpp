#include "dealer.h"

#include "card.h"
#include "card_utilities.h"
#include "player.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

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
		card_utilities::print_card_info( m_deck->at( num_drawn ).get() );
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

	const int num_of_players = players.size();
	for ( auto ite = 0; ite < num_of_players * hand_size; ite++ )
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
	for ( auto player_ite = players.begin(); player_ite != players.end(); ++player_ite )
	{
		PLAYER* player = player_ite->get();
		std::cout << player->get_name() << " has " << card_utilities::calculate_hand_description( player->get_hand() ) << std::endl;
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