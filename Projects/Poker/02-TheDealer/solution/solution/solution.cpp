#include "dealer.h"

int main()
{
	DEALER* dealer = new DEALER();
	dealer->draw( 5 );
	dealer->shuffle();
	dealer->draw( 5 );
	dealer->shuffle();
	dealer->draw( 5 );

	delete dealer;
}

