#pragma once

#include "poker_defs.h"
#include "printable_object.h"

class CARD : public PRINTABLE_OBJECT
{
public:
	CARD( SUIT _suit, int _value );
	SUIT get_suit() const;
	int get_value() const;

private:
	virtual void write_to_console() final;

	SUIT m_suit;
	int m_value;
};