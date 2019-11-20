#pragma once

#include "poker_defs.h"
#include <string>

namespace card_utilities
{
	std::string get_name_of_suit( SUIT suit );
	std::string get_card_value_string( int value );
	std::string calculate_hand_description( const PLAYER_HAND& hand_in );
	std::string get_hand_description( const HAND_STRENGTH strength_in );
	void print_card_info( const CARD* card );

	//bool is_straight( const PLAYER_HAND& hand_in );
	//bool is_flush( const PLAYER_HAND& hand_in );
	bool has_pair( const PLAYER_HAND& hand_in );
}