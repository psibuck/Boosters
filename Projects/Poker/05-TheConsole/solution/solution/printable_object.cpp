#include "printable_object.h"

#include "colours.h"

// --------------------------------------------------------------------------
//! Constructor
// --------------------------------------------------------------------------
PRINTABLE_OBJECT::PRINTABLE_OBJECT( const int colour_in ) : m_colour( colour_in )
{
}

// --------------------------------------------------------------------------
//! Returns the colour of the printable object
// --------------------------------------------------------------------------
int PRINTABLE_OBJECT::get_colour() const
{
	return m_colour;
}

// --------------------------------------------------------------------------
//! Sets the settings for the console, writes the object and resets settings
// --------------------------------------------------------------------------
void PRINTABLE_OBJECT::print()
{
	//! Sets the settings of the console
	HANDLE hstdout = GetStdHandle( (DWORD)-11 );
	SetConsoleTextAttribute( hstdout, m_colour );

	//! Writes to the console
	write_to_console();

	//! Resets the console settings
	SetConsoleTextAttribute( hstdout, s_default_settings.wAttributes );
}

// --------------------------------------------------------------------------
//! Static function: called to get default console props
// --------------------------------------------------------------------------
void PRINTABLE_OBJECT::store_default_settings()
{
	HANDLE hstdout = GetStdHandle( (DWORD)-11 );
	GetConsoleScreenBufferInfo( hstdout, &s_default_settings );
}
