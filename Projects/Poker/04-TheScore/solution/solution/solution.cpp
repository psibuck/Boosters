#include "app_settings.h"
#include "card.h"
#include "card_utilities.h"
#include "deck.h"
#include "dealer.h"
#include "player.h"
#include "tests.h"

#include <iostream>
#include <memory>
#include <string.h>
#include <vector>



int main()
{
#if TESTS_ENABLED
	if( tests::run_card_scoring_test() )
#endif // TESTS_ENABLED
	{
		std::vector<std::unique_ptr<PLAYER>> players;
		players.emplace_back( new PLAYER( "Archie" ) );
		players.emplace_back( new PLAYER( "Sam" ) );
		players.emplace_back( new PLAYER( "Stu" ) );
		players.emplace_back( new PLAYER( "Miles" ) );

		DEALER* dealer = new DEALER();
		while ( true )
		{
			std::string input;
			std::cin >> input;
			if ( input == "d" )
			{
				dealer->shuffle();
				dealer->deal_hand( players );
				dealer->score_hand( players );
				dealer->collect_cards( players );
			}
		}

		delete dealer;
	}
}

