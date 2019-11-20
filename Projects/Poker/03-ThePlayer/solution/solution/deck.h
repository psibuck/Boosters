
#pragma once

#include "card.h"
#include <memory>
#include <vector>

class DECK : public std::vector<std::unique_ptr<CARD>>
{
public:
	DECK();
	std::unique_ptr<CARD> draw();
private:
	void create_deck();
	int m_current_index{ 0 };
};