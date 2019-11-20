#include "card_utilities.h"

#include "card.h"
#include "poker_defs.h"

#include <array>
#include <iostream>
#include <map>

namespace card_utilities
{
	// --------------------------------------------------------------------------
	//! Returns a readable name of the suit
	// --------------------------------------------------------------------------
	std::string get_name_of_suit( const SUIT suit )
	{
		switch ( suit )
		{
		case SUIT::CLUB:
			return "C";
		case SUIT::HEART:
			return "H";
		case SUIT::DIAMOND:
			return "D";
		case SUIT::SPADE:
			return "S";
		default:
			return "invalid";
		}
	}

	// --------------------------------------------------------------------------
	//! Returns the human readable string responding to the card value
	// --------------------------------------------------------------------------
	std::string get_card_value_string( const int value )
	{
		switch ( value )
		{
		case 1:
			return "A";
		case 2:
			return "2";
		case 3:
			return "3";
		case 4:
			return "4";
		case 5:
			return "5";
		case 6:
			return "6";
		case 7:
			return "7";
		case 8:
			return "8";
		case 9:
			return "9";
		case 10:
			return "T";
		case 11:
			return "J";
		case 12:
			return "Q";
		case 13:
			return "K";
		default:
			return "0";
		}
	}

	// --------------------------------------------------------------------------
	//! Takes a player hand and works out it's description and returns it
	// --------------------------------------------------------------------------
	std::string calculate_hand_description( const PLAYER_HAND& hand_in )
	{
		for ( const auto& card : hand_in )
		{
			std::cout << get_card_value_string( card->get_value() ) << get_name_of_suit( card->get_suit() ) << " ";
		}
		std::cout << std::endl;

		HAND_STRENGTH strength_out = HAND_STRENGTH::HIGH_CARD;
// 		const bool is_straight = card_utilities::is_straight( hand_in );
// 		const bool is_flush = card_utilities::is_flush( hand_in );
// 		if ( is_flush && is_straight )
// 		{
// 			if ( hand_in.begin()->get()->get_value() == 10 )
// 			{
// 				strength_out = HAND_STRENGTH::ROYAL_FLUSH;
// 			}
// 			else
// 			{
// 				strength_out = HAND_STRENGTH::STRAIGHT_FLUSH;
// 			}
// 		}
		// else if is four of a king
		// else if is full house
// 		else if ( is_flush )
// 		{
// 			strength_out = HAND_STRENGTH::FLUSH;
// 		}
// 		else if ( is_straight )
// 		{
// 			strength_out = HAND_STRENGTH::STRAIGHT;
// 		}
		// else if three of a kind
		// else if two pair
		if ( has_pair( hand_in ) )
		{
			strength_out = HAND_STRENGTH::PAIR;
		}

		return get_hand_description( strength_out );
	}

	// --------------------------------------------------------------------------
	//! Given a hand strength return a description of it
	// --------------------------------------------------------------------------
	std::string get_hand_description( const HAND_STRENGTH strength_in )
	{
		switch ( strength_in )
		{
		case HAND_STRENGTH::HIGH_CARD:
			return "High Card";
		case HAND_STRENGTH::PAIR:
			return "Pair";
		case HAND_STRENGTH::TWO_PAIR:
			return "Two Pair";
		case HAND_STRENGTH::THREE_OF_A_KIND:
			return "Three of a Kind";
		case HAND_STRENGTH::STRAIGHT:
			return "Straight";
		case HAND_STRENGTH::FLUSH:
			return "Flush";
		case HAND_STRENGTH::FULL_HOUSE:
			return "Full House";
		case HAND_STRENGTH::FOUR_OF_A_KIND:
			return "Four of a Kind";
		case HAND_STRENGTH::STRAIGHT_FLUSH:
			return "Straight Flush";
		case HAND_STRENGTH::ROYAL_FLUSH:
			return "Royal Flush";
		}
	}

	void print_card_info( const CARD* card )
	{
		std::cout << get_card_value_string( card->get_value() ) << get_name_of_suit( card->get_suit() ) << std::endl;
	}

	// --------------------------------------------------------------------------
	//! Loops through the hands and checks if we have a straight
	// --------------------------------------------------------------------------
// 	bool is_straight( const PLAYER_HAND& hand_in  [[maybe_unused]] )
// 	{
// 		return false;
// 	}

	// --------------------------------------------------------------------------
	//! Loops through the hand and checks if all cards are the same suit
	// --------------------------------------------------------------------------
// 	bool is_flush( const PLAYER_HAND& hand_in )
// 	{
// 		const SUIT suit_to_check = hand_in.at( 0 )->get_suit();
// 		for ( int i = 1; i < hand_in.size(); ++i )
// 		{
// 			if ( hand_in.at( i )->get_suit() != suit_to_check )
// 			{
// 				return false;
// 			}
// 		}
// 		return true;
// 	}

	// --------------------------------------------------------------------------
	//! Returns true if the hand provided has a pair
	// --------------------------------------------------------------------------
	bool has_pair( const PLAYER_HAND& hand_in )
	{
		std::map<int, int> found_cards;
		for ( const auto& card : hand_in )
		{
			auto entry = found_cards.find( card->get_value() );
			if ( entry != found_cards.end() )
			{
				entry->second++;
			}
			else
			{
				found_cards[card->get_value()] = 1;
			}
		}
		for ( auto entry : found_cards )
		{
			if ( entry.second > 1 )
			{
				return true;
			}
		}
		return false;
	}
}