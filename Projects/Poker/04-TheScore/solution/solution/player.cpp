#include "player.h"

#include "card.h"
#include "card_utilities.h"
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
	for ( auto ite = 0; ite < HAND_SIZE && !dealt; ite++ )
	{
		if ( m_hand[ite] == nullptr )
		{
			m_hand[ite] = std::move( card );
			dealt = true;
		}
	}
	std::sort( m_hand.begin(), m_hand.end(), []( const auto& card_1, const auto& card_2 )
			   {
				   if ( card_1.get() != nullptr && card_2.get() != nullptr )
				   {
					   return card_1.get()->get_value() < card_2.get()->get_value();
				   }
				   return false;
			   } );
	return dealt;
}

// --------------------------------------------------------------------------
//! Clears the player hand and returns it
// --------------------------------------------------------------------------
PLAYER_HAND& PLAYER::muck_cards()
{
	return m_hand;
}

// --------------------------------------------------------------------------
//! Returns the name of the player
// --------------------------------------------------------------------------
std::string PLAYER::get_name() const
{
	return m_name;
}

// --------------------------------------------------------------------------
//! Returns the players hand
// --------------------------------------------------------------------------
const PLAYER_HAND& PLAYER::get_hand() const
{
	return m_hand;
}
