#include "tests.h"

#include "card.h"
#include "card_utilities.h"
#include "poker_defs.h"
#include <array>
#include <iostream>

#if TESTS_ENABLED
namespace tests
{
	// --------------------------------------------------------------------------
	//! Tests our hand scoring system
	// --------------------------------------------------------------------------
	bool run_card_scoring_test()
	{
		auto run_test = []( const HAND_STRENGTH expected_result, const PLAYER_HAND& hand ) -> bool
		{
			const bool pass = expected_result == card_utilities::get_hand_strength( hand );
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
#endif // TESTS_ENABLED
