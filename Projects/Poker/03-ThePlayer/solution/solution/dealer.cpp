#include "dealer.h"

#include "card.h"
#include "player.h"

#include <algorithm>
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