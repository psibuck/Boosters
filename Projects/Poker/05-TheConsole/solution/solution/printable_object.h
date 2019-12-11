
#pragma once

#include <windows.h>

class PRINTABLE_OBJECT
{
public:
	PRINTABLE_OBJECT( int colour_in );

	int get_colour() const;

	virtual void print() const;

private:
	virtual void write_to_console() const = 0;

	int m_colour;
};

