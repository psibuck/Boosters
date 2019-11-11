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
//! Takes our deck and mixes it up
// --------------------------------------------------------------------------
void DEALER::shuffle()
{
	std::cout << std::endl << "* Shuffle *" << std::endl;
	std::random_device seed;
	std::shuffle( m_deck->begin(), m_deck->end(), seed );
}
