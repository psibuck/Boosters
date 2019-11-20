#include "card.h"
#include "deck.h"
#include "dealer.h"
#include "player.h"

#include <memory>
#include <string.h>
#include <vector>

int main()
{
	std::vector<std::unique_ptr<PLAYER>> players;
	players.emplace_back( new PLAYER( "Archie" ) );
	players.emplace_back( new PLAYER( "Sam" ) );
	players.emplace_back( new PLAYER( "Stu" ) );
	players.emplace_back( new PLAYER( "Miles" ) );

	DEALER* dealer = new DEALER();
	dealer->draw( 10 );
	dealer->shuffle();
	dealer->draw( 10 );

	dealer->deal_hand( players );

	delete dealer;
}

