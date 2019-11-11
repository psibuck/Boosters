#include "card.h"

#include <iostream>

// --------------------------------------------------------------------------
//! Constructor
// --------------------------------------------------------------------------
CARD::CARD( const SUIT _suit, const int _value ) : m_suit( _suit ), m_value( _value )
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
//! Returns a readable name of the suit
// --------------------------------------------------------------------------
std::string card_utilities::get_name_of_suit( const SUIT suit )
{
	switch ( suit )
	{
	case SUIT::CLUB:
		return "C";
	case SUIT::HEART:
		return "H";
	case SUIT::DIAMOND:
		return "D";
	case SUIT::SPADE:
		return "S";
	default:
		return "invalid";
	}
}

std::string card_utilities::get_card_value_string( const int value )
{
	switch ( value )
	{
	case 1:
		return "A";
	case 2:
		return "2";
	case 3:
		return "3";
	case 4:
		return "4";
	case 5:
		return "5";
	case 6:
		return "6";
	case 7:
		return "7";
	case 8:
		return "8";
	case 9:
		return "9";
	case 10:
		return "T";
	case 11:
		return "J";
	case 12:
		return "Q";
	case 13:
		return "K";
	default:
		return "0";
	}
}

void card_utilities::print_card_info( const CARD* card )
{
	std::cout << get_card_value_string( card->get_value() ) << " " << get_name_of_suit( card->get_suit() ) << std::endl;
}
