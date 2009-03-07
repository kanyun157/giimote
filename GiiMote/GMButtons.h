// GMButtons.h - Contains information on the buttons and triggers
//				 used by the Wii Remote and expansions.
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

////////////////////////////////////////////
// Buttons
////////////////////////////////////////////
	/// <summary>Checks the state of a button</summary>
	/// <param name="key_code">
	/// The button to check
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>btnA</term>
	///         <description>A Button</description>
	///     </item>
	///     <item>
	///			<term>btnB</term>
	///         <description>B Button</description>
	///     </item>
	///     <item>
	///			<term>btnUp</term>
	///         <description>D-Pad Up</description>
	///     </item>
	///     <item>
	///			<term>btnDown</term>
	///         <description>D-Pad Down</description>
	///     </item>
	///     <item>
	///			<term>btnRight</term>
	///         <description>D-Pad Right</description>
	///     </item>
	///     <item>
	///			<term>btnLeft</term>
	///         <description>D-Pad Left</description>
	///     </item>
	///     <item>
	///			<term>btnOne</term>
	///         <description>One Button</description>
	///     </item>
	///     <item>
	///			<term>btnTwo</term>
	///         <description>Two Button</description>
	///     </item>
	///     <item>
	///			<term>btnMinus</term>
	///         <description>Minus Button</description>
	///     </item>
	///     <item>
	///			<term>btnPlus</term>
	///         <description>Plus Button</description>
	///     </item>
	///     <item>
	///			<term>btnHome</term>
	///         <description>Home Button</description>
	///     </item>
	/// </list>
	/// </param>
	/// <returns>Button pressed</returns>
	double wm_check_button(double key_code)
	{
		bool is_pressed = 0;
		switch ((int)key_code)
		{
		case btnA:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->ButtonState.A;
			break;
		case btnB:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->ButtonState.B;
			break;
		case btnUp:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->ButtonState.Up;
			break;
		case btnDown:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->ButtonState.Down;
			break;
		case btnRight:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->ButtonState.Right;
			break;
		case btnLeft:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->ButtonState.Left;
			break;
		case btnOne:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->ButtonState.One;
			break;
		case btnTwo:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->ButtonState.Two;
			break;
		case btnPlus:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->ButtonState.Plus;
			break;
		case btnMinus:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->ButtonState.Minus;
			break;
		case btnHome:
			is_pressed = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->ButtonState.Home;
			break;
		default:
			is_pressed = false;
			break;
		}

		return ((double)is_pressed);
	}
