
#pragma once

#include <windows.h>

class PRINTABLE_OBJECT
{
public:
	PRINTABLE_OBJECT( int colour_in );

	int get_colour() const;

	virtual void print();

	static void store_default_settings();

private:
	virtual void write_to_console() = 0;

	int m_colour;

	inline static CONSOLE_SCREEN_BUFFER_INFO s_default_settings;
};

