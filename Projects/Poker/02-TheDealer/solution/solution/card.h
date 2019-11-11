#pragma once

#include <string>

enum class SUIT : int
{
	HEART,
	DIAMOND,
	SPADE,
	CLUB
};

class CARD
{
public:
	CARD( SUIT _suit, int _value );
	SUIT get_suit() const;
	int get_value() const;

private:
	SUIT m_suit;
	int m_value;
};


namespace card_utilities
{
	std::string get_name_of_suit( SUIT suit );
	std::string get_card_value_string( int value );
	void print_card_info( const CARD* card );
}