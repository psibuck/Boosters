
#pragma once

#include "card.h"
#include <memory>
#include <vector>

class DECK : public std::vector<std::unique_ptr<CARD>>
{
public:
	DECK();
private:
	void create_deck();
};