#include "card_utilities.h"

#include "card.h"
#include "poker_defs.h"

#include <array>
#include <iostream>

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

		return get_hand_description( get_hand_strength( hand_in ) );
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
	void local_function( bool is_true )
	{
		is_true = true;
	}

	// --------------------------------------------------------------------------
	//! Calculates the strength of a given hand
	// --------------------------------------------------------------------------
	HAND_STRENGTH get_hand_strength( const PLAYER_HAND& hand_in )
	{
		HAND_STRENGTH strength_out = HAND_STRENGTH::HIGH_CARD;

		std::map<int, int> card_count;

		bool is_true = false;
		local_function( is_true );
		if ( is_true )
		{
			std::cout << "Value Changed";
		}
		else
		{
			std::cout << "Value Stayed";
		}

		bool is_straight{ true };
		bool is_flush{ true };
		analyse_cards( hand_in, card_count, is_straight, is_flush );

		const auto num_groups = card_count.size();
		switch ( num_groups )
		{
		case 2:
			if ( card_count.begin()->second == 1 || card_count.begin()->second == 4 )
			{
				strength_out = HAND_STRENGTH::FOUR_OF_A_KIND;
			}
			else
			{
				strength_out = HAND_STRENGTH::FULL_HOUSE;
			}
			break;
		case 3:
			strength_out = HAND_STRENGTH::TWO_PAIR;
			for ( const auto& entry : card_count )
			{
				if ( entry.second == 3 )
				{
					strength_out = HAND_STRENGTH::THREE_OF_A_KIND;
					break;
				}
			}
			break;
		case 4:
			strength_out = HAND_STRENGTH::PAIR;
			break;
		case 5:
			{
				const bool straight = is_straight( hand_in );
				const bool flush = is_flush( hand_in );
				if ( flush )
				{
					strength_out = HAND_STRENGTH::FLUSH;
					if ( straight )
					{
						strength_out = HAND_STRENGTH::STRAIGHT_FLUSH;
						if ( hand_in.at( 0 )->get_value() == 10 )
						{
							strength_out = HAND_STRENGTH::ROYAL_FLUSH;
						}
					}
				}
				else if ( straight )
				{
					strength_out = HAND_STRENGTH::STRAIGHT;
				}
			}
		default:
			break;
		}
		return strength_out;
	}

	void print_card_info( const CARD* card )
	{
		std::cout << get_card_value_string( card->get_value() ) << get_name_of_suit( card->get_suit() ) << std::endl;
	}

	// --------------------------------------------------------------------------
	//! Loops through the hands and checks if we have a straight
	// --------------------------------------------------------------------------
 	bool is_straight( const PLAYER_HAND& hand_in )
 	{
		int count = hand_in.at( 0 )->get_value();
		for ( int i = 1; i < HAND_SIZE; ++i )
		{
			if ( hand_in.at( i )->get_value() != ++count )
			{
				return false;
			}
		}
		return true;
 	}

	// --------------------------------------------------------------------------
	//! Loops through the hand and checks if all cards are the same suit
	// --------------------------------------------------------------------------
	bool is_flush( const PLAYER_HAND& hand_in )
	{
		const SUIT suit_to_check = hand_in.at( 0 )->get_suit();
		for ( int i = 1; i < HAND_SIZE; ++i )
		{
			if ( hand_in.at( i )->get_suit() != suit_to_check )
			{
				return false;
			}
		}
		return true;
	}

	// --------------------------------------------------------------------------
	//! Analyse a hand and populate feedback
	// --------------------------------------------------------------------------
	void analyse_cards( const PLAYER_HAND& hand_in, std::map<int, int>& cards_count, bool is_straight[[maybe_unused]], bool is_flush[[maybe_unused]] )
	{
		for ( const auto& card : hand_in )
		{
			auto entry = cards_count.find( card->get_value() );
			if ( entry != cards_count.end() )
			{
				entry->second++;
			}
			else
			{
				cards_count[card->get_value()] = 1;
			}
		}
	}
}