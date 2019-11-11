
# pragma once 

#include <vector>
#include <memory>
#include "card.h"
#include "dealer.h"

class DECK : public std::vector<std::unique_ptr<CARD>>
{	
	friend class DEALER;
	DECK();

private:
	void create_deck();
};