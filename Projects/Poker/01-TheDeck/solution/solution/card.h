
# pragma once 

#include <string>

class CARD;

enum class SUIT : int
{
	HEART,
	DIAMOND,
	SPADE, 
	CLUB
};

namespace card_utilities
{
	std::string get_name_of_suit( SUIT suit );
	std::string get_card_value_string( int value );
}

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