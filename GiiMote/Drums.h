// Drums.h -  Contains functions that deal with the drum extension.
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

/// <summary>Checks the state of a button or head</summary>
/// <param name="key_code">
/// The button or head to check
/// <list type="bullet">
///     <listheader>
///         <term>Key Code</term>
///         <description>Button</description>
///     </listheader>
///		<item>
///			<term>btnBlue</term>
///         <description>Blue head</description>
///     </item>
///		<item>
///			<term>btnRed</term>
///         <description>Red head</description>
///     </item>
///		<item>
///			<term>btnYellow</term>
///         <description>Yellow head</description>
///     </item>
///		<item>
///			<term>btnGreen</term>
///         <description>Green head</description>
///     </item>
///		<item>
///			<term>btnOrange</term>
///         <description>Orange head</description>
///     </item>
///		<item>
///			<term>btnPedal</term>
///         <description>Pedal</description>
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
double wm_drum_check_button(double key_code)
{
	bool is_pressed = 0;
	switch ((int)key_code)
	{
	case btnBlue:
		is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.Blue;
		break;
	case btnRed:
		is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.Red;
		break;
	case btnYellow:
		is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.Yellow;
		break;
	case btnGreen:
		is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.Green;
		break;
	case btnOrange:
		is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.Orange;
		break;
	case btnMinus:
		is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.Minus;
		break;
	case btnPlus:
		is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.Plus;
		break;
	case btnPedal:
		is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.Pedal;
		break;
	default:
		is_pressed = false;
		break;
	}

	return ((double)is_pressed);
}

/// <summary>Gets the velocity with which the drum head or pedal was hit</summary>
/// <remarks>Domain: (soft) [0,6] (hard)</remarks>
/// <param name="key_code">
/// The head or pedal to check
/// <list type="bullet">
///     <listheader>
///         <term>Key Code</term>
///         <description>Button</description>
///     </listheader>
///		<item>
///			<term>btnBlue</term>
///         <description>Blue head</description>
///     </item>
///		<item>
///			<term>btnRed</term>
///         <description>Red head</description>
///     </item>
///		<item>
///			<term>btnYellow</term>
///         <description>Yellow head</description>
///     </item>
///		<item>
///			<term>btnGreen</term>
///         <description>Green head</description>
///     </item>
///		<item>
///			<term>btnOrange</term>
///         <description>Orange head</description>
///     </item>
///		<item>
///			<term>btnPedal</term>
///         <description>Pedal</description>
///     </item>
/// </list>
/// </param>
/// <returns>Button pressed</returns>
double wm_drum_get_velocity(double key_code)
{
	int is_pressed = 0;
	switch ((int)key_code)
	{
	case btnBlue:
		is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.BlueVelocity;
		break;
	case btnRed:
		is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.RedVelocity;
		break;
	case btnYellow:
		is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.YellowVelocity;
		break;
	case btnGreen:
		is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.GreenVelocity;
		break;
	case btnOrange:
		is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.OrangeVelocity;
		break;
	case btnPedal:
		is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.PedalVelocity;
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
double wm_drum_xpos()
{
	double xx;
	try
	{
		xx = (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.Joystick.X;
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
double wm_drum_ypos()
{
	double yy;
	try
	{
		yy = (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.Joystick.Y;
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
double wm_drum_direction()
{
	double xx = wm_drum_xpos();
	double yy = wm_drum_ypos();
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
double wm_drum_pressure()
{
	double xx = wm_drum_xpos();
	double yy = wm_drum_ypos();
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
double wm_drum_rawx()
{
	double rawX;
	try
	{
		rawX = (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.RawJoystick.X;
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
double wm_drum_rawy()
{
	double rawY;
	try
	{
		rawY = (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->DrumsState.RawJoystick.Y;
	}
	catch(...)
	{
		return ( -1 );
	}

	return ( rawY );
}
