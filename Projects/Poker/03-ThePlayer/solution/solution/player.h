#pragma once

#include "card.h"
#include <array>
#include <string.h>

//! Texas hold-em for now
constexpr int hand_size{ 5 };

class PLAYER
{
public:
	PLAYER( std::string name_in );

	int get_stack_size() const;
	void add_chips( int chips );
	
	bool deal( std::unique_ptr<CARD>&& card );
	
	std::string get_name() const;

private:
	std::string m_name;
	std::array<std::unique_ptr<CARD>, hand_size> m_hand;
	int m_stack{ 0 };
};

