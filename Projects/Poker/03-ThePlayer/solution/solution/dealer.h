// --------------------------------------------------------------------------
//! The dealer class is in charge of card and chip distribution and retrieval.
// --------------------------------------------------------------------------

#pragma once

#include "deck.h"
#include <memory>

class CARD;
class PLAYER;

class DEALER
{
public:
	DEALER();

	void draw( int number_to_draw );
	void shuffle();
	void deal_hand( std::vector<std::unique_ptr<PLAYER>>& players );

private:
	void discard( std::unique_ptr<CARD>&& card_to_discard );

	std::unique_ptr<DECK> m_deck{ nullptr };
	std::vector<std::unique_ptr<CARD>> m_discard_pile;
};

