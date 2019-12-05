#include "card.h"

#include "card_utilities.h"
#include "player.h"

#include <iostream>

// --------------------------------------------------------------------------
//! Constructor
// --------------------------------------------------------------------------
CARD::CARD( const SUIT _suit, const int _value )
	: PRINTABLE_OBJECT( card_utilities::get_suit_colour( _suit )), m_suit( _suit ), m_value( _value )
{
}

// --------------------------------------------------------------------------
//! Returns the suit of the card
// --------------------------------------------------------------------------
SUIT CARD::get_suit() const
{
	return m_suit;
}

// --------------------------------------------------------------------------
//! Returns the value of the card
// --------------------------------------------------------------------------
int CARD::get_value() const
{
	return m_value;
}

// --------------------------------------------------------------------------
//! Writes card info to the console
// --------------------------------------------------------------------------
void CARD::write_to_console()
{
	std::cout << " " <<  card_utilities::get_card_value_string( get_value() ) << card_utilities::get_name_of_suit( get_suit() ) << " ";
}
