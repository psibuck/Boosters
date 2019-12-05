#include "card.h"
#include "card_utilities.h"
#include "colours.h"
#include "dealer.h"
#include "deck.h"
#include "player.h"

#include <iostream>
#include <memory>
#include <string.h>
#include <vector>
#include <windows.h>

int main()
{
	HANDLE hstdout = GetStdHandle( (DWORD)-11 );

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( hstdout, &csbi );

	std::cout << "Normal";
	SetConsoleTextAttribute( hstdout, colour::BLUE );
	std::cout << "coloured" << std::endl;

	SetConsoleTextAttribute( hstdout, csbi.wAttributes );


	if ( card_utilities::run_card_test() )
	{
		std::vector<std::unique_ptr<PLAYER>> players;
		players.emplace_back( new PLAYER( "Archie", colour::GREEN ) );
		players.emplace_back( new PLAYER( "Sam", colour::BLUE ) );
		players.emplace_back( new PLAYER( "Stu", colour::GOLD ) );
		players.emplace_back( new PLAYER( "Miles", colour::ORANGE ) );

		DEALER* dealer = new DEALER();
		while ( true )
		{
			std::string input;
			std::cin >> input;
			if ( input == "d" )
			{

				dealer->shuffle();
				dealer->deal_hand( players );

				for ( const auto& player : players )
				{
					player->print();
				}
				dealer->score_hand( players );
				dealer->collect_cards( players );
			}
		}

		delete dealer;
	}
	return 0;
}

