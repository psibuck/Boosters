#include "dealer.h"

#include "card.h"

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
//! Shuffles the deck
// --------------------------------------------------------------------------
void DEALER::shuffle()
{
	std::cout << "* Shuffle *" << std::endl;
	std::random_device seed;
	std::shuffle( m_deck->begin(), m_deck->end(), seed );
}

// --------------------------------------------------------------------------
//! Draws n cards
// --------------------------------------------------------------------------
void DEALER::draw( const int number_of_cards )
{
	int num_drawn = 0;
	while ( num_drawn < number_of_cards )
	{
		card_utilities::get_card_value_string( m_deck->at( num_drawn )->get_value() );
		num_drawn++;
	}
}