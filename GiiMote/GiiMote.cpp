// This is the main DLL file.

#include "stdafx.h"
#include "GiiMote.h"

using namespace GiiMoteLib;

#include "mii.h"
#include "GMMath.h"
#include "Wiimote.h"
#include "GMButtons.h"
#include "Joystick.h"
#include "GMAccel.h"
#include "Orientation.h"
#include "IR.h"
#include "Guitar.h"
#include "Nunchuck.h"
#include "Classic.h"
#include "BalanceBoard.h"

/// <summary>True if an instance of GiiMote exists.</summary>
bool initialized = 0;

/// <summary>Initializes GiiMote by creating a new instance of GiiMoteLib.GiiMote</summary>
/// <returns>Success or -1 if already initialized</returns>
exp double gm_init()
{
	if (!initialized)
	{
		try
		{
			gcnew GiiMote();
			initialized = true;
		}
		catch(...)
		{
			initialized = false;
		}
	}
	else
	{
		return ( -1.0 );
	}
	return ( (double)initialized );
}

/// <summary>Cleans up the heap when GiiMote exists gracefully</summary>
/// <returns>Success</returns>
exp double gm_cleanup()
{
	if (initialized)
	{
		try
		{
			delete GiiMote::gm;
		}
		catch(...)
		{
			initialized = 1;
		}
		initialized = false;
	}
	return ( !initialized );
}
