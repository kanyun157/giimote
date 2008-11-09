// Joystick.h - Contains functions to use joysticks that expand the functionality
//				of the Wii Remote.
// Copyright 2007 Sam Whited
//
//    This file is part of GiiMote.
//
//    GiiMote is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Lesser General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    GiiMote is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Lesser General Public License for more details.
//
//    You should have received a copy of the GNU Lesser General Public License
//    along with GiiMote.  If not, see <http://www.gnu.org/licenses/>.

	/////////////////////////
	// General
	/////////////////////////

	/// <summary>Calculates the direction of a joystick</summary>
	/// <param name="xx">The normalized X value of the joystick</param>
	/// <param name="yy">The normalized Y value of the joystick</param>
	/// <returns>The direction of the Joystick in degrees</returns>
	double joystick_direction(double xx, double yy)
	{
		return ( System::Math::Atan2(yy,xx) * ( 180 / System::Math::PI ) );
	}

	/// <summary>Calculates the pressure on a joystick</summary>
	/// <param name="xx">The normalized X value of the joystick</param>
	/// <param name="yy">The normalized Y value of the joystick</param>
	/// <returns>The pressure on the joystick</returns>
	double joystick_pressure(double xx, double yy)
	{
		return ( System::Math::Sqrt( System::Math::Pow(xx, 2) + System::Math::Pow(yy, 2) ) * 2 );
	}

	/// <summary>Sets the dead-zone value</summary>
	/// <remarks>Domain: [0.0,0.5]</remarks>
	/// <param name="val">The dead-zone value</param>
	/// <returns>1</returns>
	double wm_set_joystick_dead_zone(double val)
	{
		GiiMote::gm->joystick_dead_zone[GiiMote::gm->wmIndex] = in_domain(val, 0, 0.5);
		return ( 1 );
	}

	/// <summary>Gets the dead-zone value</summary>
	/// <returns>Joystick dead-zone value</returns>
	double wm_get_joystick_dead_zone()
	{
		return ( GiiMote::gm->joystick_dead_zone[GiiMote::gm->wmIndex] );
	}
