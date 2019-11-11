# pragma once 

#include "deck.h"
#include <memory>

class DEALER
{
public:
	DEALER();

	void draw( int number_to_draw );
	void shuffle();

private:
	std::unique_ptr<DECK> m_deck{ nullptr };
};