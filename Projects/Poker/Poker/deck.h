#include <array>

#pragma once

class CARD;

class DECK
{
	DECK();

private:
	void create_card_list();

	std::array<CARD*, 52> m_cards{};
};

