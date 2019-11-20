#include "deck.h"

#include <iostream>

// --------------------------------------------------------------------------
//! Constructor
// --------------------------------------------------------------------------
DECK::DECK()
{
	create_deck();
}

// --------------------------------------------------------------------------
//! Creates our deck
// --------------------------------------------------------------------------
void DECK::create_deck()
{
	int deck_position = 0;
	reserve( 52 );
	for ( auto i = 1; i <= 13; i++ )
	{
		push_back( std::make_unique<CARD>( SUIT::HEART, i ));
		push_back( std::make_unique<CARD>( SUIT::CLUB, i ));
		push_back( std::make_unique<CARD>( SUIT::DIAMOND, i ));
		push_back( std::make_unique<CARD>( SUIT::SPADE, i ));
	}
}

// --------------------------------------------------------------------------
//! Draws the top card
// --------------------------------------------------------------------------
std::unique_ptr<CARD> DECK::draw()
{
	return std::move( at( m_current_index++ ) );
}

