// GMButtons.h - Contains information on the buttons and triggers
//				 used by the Wii Remote and Expansions.

namespace GiiMoteLib {

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
	double GiiMote::wm_check_button(double key_code)
	{
		bool is_pressed = 0;
		switch ((int)key_code)
		{
		case btnA:
			is_pressed = this->wmState->ButtonState.A;
			break;
		case btnB:
			is_pressed = this->wmState->ButtonState.B;
			break;
		case btnUp:
			is_pressed = this->wmState->ButtonState.Up;
			break;
		case btnDown:
			is_pressed = this->wmState->ButtonState.Down;
			break;
		case btnRight:
			is_pressed = this->wmState->ButtonState.Right;
			break;
		case btnLeft:
			is_pressed = this->wmState->ButtonState.Left;
			break;
		case btnOne:
			is_pressed = this->wmState->ButtonState.One;
			break;
		case btnTwo:
			is_pressed = this->wmState->ButtonState.Two;
			break;
		case btnPlus:
			is_pressed = this->wmState->ButtonState.Plus;
			break;
		case btnMinus:
			is_pressed = this->wmState->ButtonState.Minus;
			break;
		case btnHome:
			is_pressed = this->wmState->ButtonState.Home;
			break;
		default:
			is_pressed = false;
			break;
		}

		return ((double)is_pressed);
	}

} // namespace GiiMoteLib