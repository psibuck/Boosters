#pragma once

#include "poker_defs.h"

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