#pragma once

enum class SUIT : int
{
	HEART,
	CLUB, 
	SPADE,
	DIAMOND
};

class CARD
{
public:
	CARD( SUIT _suit, int _value );

	SUIT get_suit() const { return m_suit; }
	int get_value() const { return m_value; }

private:
	SUIT m_suit;
	int m_value;
};

