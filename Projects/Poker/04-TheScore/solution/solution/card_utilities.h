#pragma once

#include "poker_defs.h"
#include <map>
#include <string>

namespace card_utilities
{
	std::string get_name_of_suit( SUIT suit );
	std::string get_card_value_string( int value );
	std::string calculate_hand_description( const PLAYER_HAND& hand_in );
	std::string get_hand_description( const HAND_STRENGTH strength_in );
	HAND_STRENGTH get_hand_strength( const PLAYER_HAND& hand_in );
	void print_card_info( const CARD* card );
	void analyse_cards( const PLAYER_HAND& hand_in, std::map<int, int>& cards_count, bool is_straight, bool is_flush );

	bool is_straight( const PLAYER_HAND& hand_in );
	bool is_flush( const PLAYER_HAND& hand_in );
}