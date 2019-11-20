#pragma once

#include <memory>

class CARD;

// --------------------------------------------------------------------------
//! Constants
// --------------------------------------------------------------------------
constexpr int hand_size{ 5 };
constexpr int DECK_SIZE{ 52 };

typedef std::array<std::unique_ptr<CARD>, hand_size> PLAYER_HAND;

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

