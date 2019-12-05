#include "card_utilities.h"

#include "card.h"
#include "colours.h"
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

	// --------------------------------------------------------------------------
	//! Calculates the strength of a given hand
	// --------------------------------------------------------------------------
	HAND_STRENGTH get_hand_strength( const PLAYER_HAND& hand_in )
	{
		HAND_STRENGTH strength_out = HAND_STRENGTH::HIGH_CARD;

		std::map<int, int> card_count;
		bool is_flush = true;
		bool is_straight = true;
		analyse_cards( hand_in, card_count, is_flush, is_straight );

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
				if ( is_flush )
				{
					strength_out = HAND_STRENGTH::FLUSH;
					if ( is_straight )
					{
						strength_out = HAND_STRENGTH::STRAIGHT_FLUSH;
						if ( hand_in.at( 0 )->get_value() == 10 )
						{
							strength_out = HAND_STRENGTH::ROYAL_FLUSH;
						}
					}
				}
				else if ( is_straight )
				{
					strength_out = HAND_STRENGTH::STRAIGHT;
				}
			}
		default:
			break;
		}
		return strength_out;
	}

	// --------------------------------------------------------------------------
	//! Returns true if the hand provided has a pair
	// --------------------------------------------------------------------------
	void analyse_cards( const PLAYER_HAND& hand_in, std::map<int, int>& cards_count, bool& is_flush, bool& is_straight )
	{
		const SUIT suit_to_check = hand_in.at( 0 )->get_suit();
		int count = -1;
		for ( const auto& card : hand_in )
		{
			const int card_value = card->get_value();
			if ( card->get_suit() != suit_to_check )
			{
				is_flush = false;
			}

			if ( count == -1 )
			{
				count = card_value;
			}
			else if ( card_value != ++count )
			{
				is_straight = false;
			}

			const auto entry = cards_count.find( card_value );
			if ( entry != cards_count.end() )
			{
				entry->second++;
			}
			else
			{
				cards_count[card_value] = 1;
			}
		}
	}

	// --------------------------------------------------------------------------
	//! Returns the colour of the suit
	// --------------------------------------------------------------------------
	int get_suit_colour( SUIT suit )
	{
		switch ( suit )
		{
		case SUIT::CLUB:
			return colour::BLUE;
		case SUIT::DIAMOND:
			return colour::PURPLE;
		case SUIT::SPADE:
			return colour::GREEN;
		case SUIT::HEART:
			return colour::RED;
		}
	}

	bool run_card_test()
	{
		auto run_test = []( const HAND_STRENGTH expected_result, const PLAYER_HAND& hand ) -> bool
		{
			const bool pass = expected_result == get_hand_strength( hand );
			std::cout << (pass ? "Test Passed!" : "Test Failed");
			std::cout << std::endl;
			return pass;
		};
		const PLAYER_HAND high_card = { std::make_unique<CARD>( SUIT::HEART, 1 ), std::make_unique<CARD>( SUIT::CLUB, 3 ),
										std::make_unique<CARD>( SUIT::SPADE, 4 ), std::make_unique<CARD>( SUIT::DIAMOND, 10 ), std::make_unique<CARD>( SUIT::CLUB, 13 ) };
		bool passed = run_test( HAND_STRENGTH::HIGH_CARD, high_card );

		const PLAYER_HAND pair = { std::make_unique<CARD>( SUIT::CLUB, 1 ), std::make_unique<CARD>( SUIT::SPADE, 1 ),
										std::make_unique<CARD>( SUIT::CLUB, 3 ), std::make_unique<CARD>( SUIT::CLUB, 4 ), std::make_unique<CARD>( SUIT::CLUB, 8 ) };
		passed = run_test( HAND_STRENGTH::PAIR, pair );

		const PLAYER_HAND two_pair = { std::make_unique<CARD>( SUIT::CLUB, 1 ), std::make_unique<CARD>( SUIT::SPADE, 1 ),
										std::make_unique<CARD>( SUIT::CLUB, 3 ), std::make_unique<CARD>( SUIT::CLUB, 3 ), std::make_unique<CARD>( SUIT::CLUB, 8 ) };
		passed = run_test( HAND_STRENGTH::TWO_PAIR, two_pair );

		const PLAYER_HAND three_of_a_kind = { std::make_unique<CARD>( SUIT::CLUB, 1 ), std::make_unique<CARD>( SUIT::SPADE, 1 ),
								std::make_unique<CARD>( SUIT::CLUB, 1 ), std::make_unique<CARD>( SUIT::CLUB, 3 ), std::make_unique<CARD>( SUIT::CLUB, 8 ) };
		passed = run_test( HAND_STRENGTH::THREE_OF_A_KIND, three_of_a_kind );

		const PLAYER_HAND straight = { std::make_unique<CARD>( SUIT::CLUB, 1 ), std::make_unique<CARD>( SUIT::SPADE, 2 ),
						std::make_unique<CARD>( SUIT::CLUB, 3 ), std::make_unique<CARD>( SUIT::CLUB, 4 ), std::make_unique<CARD>( SUIT::CLUB, 5 ) };
		passed = run_test( HAND_STRENGTH::STRAIGHT, straight );

		const PLAYER_HAND flush = { std::make_unique<CARD>( SUIT::CLUB, 1 ), std::make_unique<CARD>( SUIT::CLUB, 3 ),
						std::make_unique<CARD>( SUIT::CLUB, 4 ), std::make_unique<CARD>( SUIT::CLUB, 5 ), std::make_unique<CARD>( SUIT::CLUB, 8 ) };
		passed = run_test( HAND_STRENGTH::FLUSH, flush );

		const PLAYER_HAND full_house = { std::make_unique<CARD>( SUIT::SPADE, 1 ), std::make_unique<CARD>( SUIT::CLUB, 1 ),
				std::make_unique<CARD>( SUIT::HEART, 1 ), std::make_unique<CARD>( SUIT::HEART, 2 ), std::make_unique<CARD>( SUIT::DIAMOND, 2 ) };
		passed = run_test( HAND_STRENGTH::FULL_HOUSE, full_house );

		const PLAYER_HAND four_of_a_kind = { std::make_unique<CARD>( SUIT::CLUB, 1 ), std::make_unique<CARD>( SUIT::SPADE, 1 ),
						std::make_unique<CARD>( SUIT::CLUB, 1 ), std::make_unique<CARD>( SUIT::CLUB, 1 ), std::make_unique<CARD>( SUIT::CLUB, 8 ) };
		passed = run_test( HAND_STRENGTH::FOUR_OF_A_KIND, four_of_a_kind );

		const PLAYER_HAND straight_flush = { std::make_unique<CARD>( SUIT::CLUB, 1 ), std::make_unique<CARD>( SUIT::CLUB, 2 ),
				std::make_unique<CARD>( SUIT::CLUB, 3 ), std::make_unique<CARD>( SUIT::CLUB, 4 ), std::make_unique<CARD>( SUIT::CLUB, 5 ) };
		passed = run_test( HAND_STRENGTH::STRAIGHT_FLUSH, straight_flush );

		const PLAYER_HAND royal_flush = { std::make_unique<CARD>( SUIT::CLUB, 10 ), std::make_unique<CARD>( SUIT::CLUB, 11 ),
				std::make_unique<CARD>( SUIT::CLUB, 12 ), std::make_unique<CARD>( SUIT::CLUB, 13 ), std::make_unique<CARD>( SUIT::CLUB, 14 ) };
		passed = run_test( HAND_STRENGTH::ROYAL_FLUSH, royal_flush );

		return passed;
	}
}