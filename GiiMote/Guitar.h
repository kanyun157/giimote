// Guitar.h -  Contains functions that deal with the guitar extension.
// Copyright 2008 Sam Whited
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

	/// <summary>Checks the state of a button</summary>
	/// <param name="key_code">
	/// The button to check
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///		<item>
	///			<term>btnBlue</term>
	///         <description>Blue Fret</description>
	///     </item>
	///		<item>
	///			<term>btnGreen</term>
	///         <description>Green Fret</description>
	///     </item>
	///		<item>
	///			<term>btnOrange</term>
	///         <description>Orange Fret</description>
	///     </item>
	///		<item>
	///			<term>btnRed</term>
	///         <description>Red Fret</description>
	///     </item>
	///		<item>
	///			<term>btnYellow</term>
	///         <description>Yellow Fret</description>
	///     </item>
	///		<item>
	///			<term>btnStrumDown</term>
	///         <description>Strum bar down</description>
	///     </item>
	///		<item>
	///			<term>btnStrumUp</term>
	///         <description>Strum bar up</description>
	///     </item>
	///		<item>
	///			<term>btnMinus</term>
	///         <description>Minus button</description>
	///     </item>
	///		<item>
	///			<term>btnPlus</term>
	///         <description>Plus button</description>
	///     </item>
	/// </list>
	/// </param>
	/// <returns>Button pressed</returns>
	double wm_guitar_check_button(double key_code)
	{
		bool is_pressed = 0;
		switch ((int)key_code)
		{
		case btnBlue:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.FretButtonState.Blue;
			break;
		case btnGreen:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.FretButtonState.Green;
			break;
		case btnOrange:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.FretButtonState.Orange;
			break;
		case btnRed:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.FretButtonState.Red;
			break;
		case btnYellow:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.FretButtonState.Yellow;
			break;
		case btnTouchBlue:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.TouchbarState.Blue;
			break;
		case btnTouchGreen:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.TouchbarState.Green;
			break;
		case btnTouchOrange:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.TouchbarState.Orange;
			break;
		case btnTouchRed:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.TouchbarState.Red;
			break;
		case btnTouchYellow:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.TouchbarState.Yellow;
			break;
		case btnStrumDown:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.ButtonState.StrumDown;
			break;
		case btnStrumUp:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.ButtonState.StrumUp;
			break;
		case btnMinus:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.ButtonState.Minus;
			break;
		case btnPlus:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.ButtonState.Plus;
			break;
		default:
			is_pressed = false;
			break;
		}

		return ((double)is_pressed);
	}

	/// <summary>Normalized joystick position</summary>
	/// <remarks>Domain: [-0.5,0.5]</remarks>
	/// <returns>The normalized X-position of the joystick</returns>
	double wm_guitar_xpos()
	{
		double xx;
		try
		{
			xx = (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.Joystick.X;
		}
		catch(...)
		{
			return ( -1 );
		}
		if ( System::Math::Abs(xx) < (GiiMote::gm->joystick_dead_zone[GiiMote::gm->wmIndex]) )
		{
			xx = 0;
		}
		return ( xx );
	}

	/// <summary>Normalized joystick position</summary>
	/// <remarks>Domain: [-0.5,0.5]</remarks>
	/// <returns>The normalized Y-position of the joystick</returns>
	double wm_guitar_ypos()
	{
		double yy;
		try
		{
			yy = (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.Joystick.Y;
		}
		catch(...)
		{
			return ( -1 );
		}
		if ( System::Math::Abs(yy) < (GiiMote::gm->joystick_dead_zone[GiiMote::gm->wmIndex]) )
		{
			yy = 0;
		}	
		return ( yy );
	}

	/// <summary>Joystick direction</summary>
	/// <returns>The direction of the joystick in degrees</returns>
	double wm_guitar_direction()
	{
		double xx = wm_guitar_xpos();
		double yy = wm_guitar_ypos();
		if (xx == -1 || yy == -1)
		{
			return ( -1 );
		}
		else
		{
			return ( joystick_direction(xx,yy) );
		}
	}

	/// <summary>Joystick pressure</summary>
	/// <returns>The pressure on the joystick</returns>
	double wm_guitar_pressure()
	{
		double xx = wm_guitar_xpos();
		double yy = wm_guitar_ypos();
		if (xx == -1 || yy == -1)
		{
			return ( -1 );
		}
		else
		{
			return ( joystick_pressure(xx,yy) );
		}
	}

	/// <summary>Raw joystick X-position</summary>
	/// <remarks>Domain: [0,255]</remarks>
	/// <returns>Raw joystick X-position</returns>
	double wm_guitar_rawx()
	{
		double rawX;
		try
		{
			rawX = (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.RawJoystick.X;
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( rawX );
	}

	/// <summary>Raw joystick Y-position</summary>
	/// <remarks>Domain: [0,255]</remarks>
	/// <returns>Raw joystick Y-position</returns>
	double wm_guitar_rawy()
	{
		double rawY;
		try
		{
			rawY = (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.RawJoystick.Y;
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( rawY );
	}

	/// <summary>Whammy bar position</summary>
	/// <remarks>Domain: [0.0,1.0]</remarks>
	/// <returns>Whammy bar position</returns>
	double wm_guitar_whammybar_pos()
	{
		return (GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.WhammyBar);
	}

	/// <summary>Raw whammy bar position</summary>
	/// <remarks>Domain: [0,10]</remarks>
	/// <returns>Raw whammy bar position</returns>
	double wm_guitar_whammybar_rawpos()
	{
		return (GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.RawWhammyBar);
	}

	/// <summary>Type of guitar extension</summary>
	/// <returns>Guitar Hero 3 (0) or Guitar Hero World Tour (1)</returns>
	double wm_guitar_get_type()
	{
		switch ((int)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->GuitarState.GuitarType)
		{
		case (0):
			return ( 0.0 );
			break;
		case (1):
			return ( 1.0 );
			break;
		default:
			return ( -1.0 );
			break;
		}
	}