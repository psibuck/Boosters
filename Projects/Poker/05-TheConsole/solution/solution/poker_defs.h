#pragma once

#include <memory>

class CARD;

// --------------------------------------------------------------------------
//! Constants
// --------------------------------------------------------------------------
constexpr int HAND_SIZE{ 5 };
constexpr int DECK_SIZE{ 52 };

typedef std::array<std::unique_ptr<CARD>, HAND_SIZE> PLAYER_HAND;

enum class SUIT : int
{
	HEART,
	DIAMOND,
	SPADE,
	CLUB
};

enum class HAND_STRENGTH : int
{
	HIGH_CARD,
	PAIR,
	TWO_PAIR,
	THREE_OF_A_KIND,
	STRAIGHT,
	FLUSH,
	FULL_HOUSE,
	FOUR_OF_A_KIND,
	STRAIGHT_FLUSH,
	ROYAL_FLUSH
};

