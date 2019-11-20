#pragma once

#include "card.h"
#include "poker_defs.h"

#include <array>
#include <string.h>

class PLAYER
{
public:
	PLAYER( std::string name_in );

	int get_stack_size() const;
	void add_chips( int chips );
	
	bool deal( std::unique_ptr<CARD>&& card );
	PLAYER_HAND& muck_cards();

	std::string get_name() const;
	const PLAYER_HAND& get_hand() const;

private:
	std::string m_name;
	PLAYER_HAND m_hand;
	int m_stack{ 0 };
};

