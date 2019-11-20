#include "player.h"

#include "card.h"
#include <iostream>

// --------------------------------------------------------------------------
//! Constructor
// --------------------------------------------------------------------------
PLAYER::PLAYER( const std::string name_in ) : m_name( name_in )
{
}

// --------------------------------------------------------------------------
//! Returns the current stack size the player is holding
// --------------------------------------------------------------------------
int PLAYER::get_stack_size() const
{
	return m_stack;
}

// --------------------------------------------------------------------------
//! Called to add chips to the players stack
// --------------------------------------------------------------------------
void PLAYER::add_chips( const int chips )
{
	m_stack += chips;
}

// --------------------------------------------------------------------------
//! Receive a card from the dealer
// --------------------------------------------------------------------------
bool PLAYER::deal( std::unique_ptr<CARD>&& card )
{
	bool dealt{ false };
	for ( auto ite = 0; ite < hand_size && !dealt; ite++ )
	{
		if ( m_hand[ite] == nullptr )
		{
			m_hand[ite] = std::move( card );
			std::cout << "Dealt: ";
			card_utilities::print_card_info( m_hand[ite].get() );
			dealt = true;
		}
	}
	return dealt;
}

// --------------------------------------------------------------------------
//! Returns the name of the player
// --------------------------------------------------------------------------
std::string PLAYER::get_name() const
{
	return m_name;
}
