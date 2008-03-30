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

	/// <summary>Checks the state of a button</summary>
	/// <param name="key_code">
	/// The button to check
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///		<item>
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
	///			<term>btnX</term>
	///         <description>X Button</description>
	///     </item>
	///     <item>
	///			<term>btnY</term>
	///         <description>Y Button</description>
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
	///     <item>
	///			<term>btnL</term>
	///         <description>Left Trigger</description>
	///     </item>
	///     <item>
	///			<term>btnR</term>
	///         <description>Right Trigger</description>
	///     </item>
	///     <item>
	///			<term>btnZL</term>
	///         <description>ZL Button</description>
	///     </item>
	///     <item>
	///			<term>btnZR</term>
	///         <description>ZR Button</description>
	///     </item>
	/// </list>
	/// </param>
	/// <returns>Button pressed</returns>
	double GiiMote::wm_classic_check_button(double key_code)
	{
		bool is_pressed = 0;
		switch ((int)key_code)
		{
		case btnA:
			is_pressed = this->wmState->ClassicControllerState.ButtonState.A;
			break;
		case btnB:
			is_pressed = this->wmState->ClassicControllerState.ButtonState.B;
			break;
		case btnUp:
			is_pressed = this->wmState->ClassicControllerState.ButtonState.Up;
			break;
		case btnDown:
			is_pressed = this->wmState->ClassicControllerState.ButtonState.Down;
			break;
		case btnRight:
			is_pressed = this->wmState->ClassicControllerState.ButtonState.Right;
			break;
		case btnLeft:
			is_pressed = this->wmState->ClassicControllerState.ButtonState.Left;
			break;
		case btnX:
			is_pressed = this->wmState->ClassicControllerState.ButtonState.X;
			break;
		case btnY:
			is_pressed = this->wmState->ClassicControllerState.ButtonState.Y;
			break;
		case btnPlus:
			is_pressed = this->wmState->ClassicControllerState.ButtonState.Plus;
			break;
		case btnMinus:
			is_pressed = this->wmState->ClassicControllerState.ButtonState.Minus;
			break;
		case btnHome:
			is_pressed = this->wmState->ClassicControllerState.ButtonState.Home;
			break;
		case btnL:
			is_pressed = this->wmState->ClassicControllerState.ButtonState.TriggerL;
			break;
		case btnR:
			is_pressed = this->wmState->ClassicControllerState.ButtonState.TriggerR;
			break;
		case btnZL:
			is_pressed = this->wmState->ClassicControllerState.ButtonState.ZL;
			break;
		case btnZR:
			is_pressed = this->wmState->ClassicControllerState.ButtonState.ZR;
			break;
		default:
			is_pressed = false;
			break;
		}

		return ((double)is_pressed);
	}

	/// <summary>
	/// Checks the state of a button
	/// </summary>
	/// <param name="key_code">
	/// The button to check
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>btnC</term>
	///         <description>C Button</description>
	///     </item>
	///     <item>
	///			<term>btnZ</term>
	///         <description>Z Button</description>
	///     </item>
	/// </list>
	/// </param>
	/// <returns>Button pressed</returns>
	double GiiMote::wm_nunchuck_check_button(double key_code)
	{
		bool is_pressed = 0;
		switch ((int)key_code)
		{
		case btnC:
			is_pressed = this->wmState->NunchukState.C;
			break;
		case btnZ:
			is_pressed = this->wmState->NunchukState.Z;
			break;
		default:
			is_pressed = false;
			break;
		}
		
		return ((double)is_pressed);
	}

////////////////////////////////////////////
// Triggers
////////////////////////////////////////////

	/// <summary>Sets the dead-zone value</summary>
	/// <remarks>Domain: [0.0,1.0]</remarks>
	/// <param name="val">The dead-zone value</param>
	/// <returns>1</returns>
	double GiiMote::wm_set_trigger_dead_zone(double val)
	{
		this->trigger_dead_zone = in_domain<double>(val, 0, 1);
		return ( 1 );
	}

	/// <summary>Gets the dead-zone value</summary>
	/// <returns>Trigger dead-zone value</returns>
	double GiiMote::wm_get_trigger_dead_zone()
	{
		return ( this->trigger_dead_zone );
	}

	// Normalized Functions
	/// <summary>
	/// Normalized trigger pressure
	/// </summary>
	/// <remarks>
	/// Domain: [0.0,1.0]
	/// </remarks>
	/// <param name="trigger">
	/// The trigger to check:
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>btnL</term>
	///         <description>Left Trigger</description>
	///     </item>
	///     <item>
	///			<term>btnR</term>
	///         <description>Right Trigger</description>
	///     </item>
	/// </list>
	/// </param>
	/// <returns>Normalized trigger pressure</returns>
	double GiiMote::wm_classic_trigger_pressure(double trigger)
	{
		double val = -1;
		if (trigger == btnL || trigger == 0)
		{
			// Left
			val = (double)this->wmState->ClassicControllerState.TriggerL;
		}
		if (trigger == btnR || trigger == 1)
		{
			// Right
			val = (double)this->wmState->ClassicControllerState.TriggerR;
		}
		if (val < this->trigger_dead_zone && val != -1)
		{
			val = 0;
		}
		if (val > (1 - this->trigger_dead_zone) )
		{
			val = 1;
		}
		return ( val );
	}
	
	// Raw Functions
	/// <summary>Raw trigger pressure</summary>
	/// <remarks>Domain: [0,255]</remarks>
	/// <param name="trigger">
	/// The trigger to check:
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>btnL</term>
	///         <description>Left Trigger</description>
	///     </item>
	///     <item>
	///			<term>btnR</term>
	///         <description>Right Trigger</description>
	///     </item>
	/// </list>
	/// </param>
	/// <returns>Raw trigger pressure</returns>
	double GiiMote::wm_classic_trigger_raw(double trigger)
	{
		if (trigger == btnL || trigger == 0)
		{
			// Left
			return( (double)this->wmState->ClassicControllerState.RawTriggerL );
	
		}
		if (trigger == btnR || trigger == 1)
		{
			// Right
			return( (double)this->wmState->ClassicControllerState.RawTriggerR );
		}
	
		return ( -1 );
	}

} // namespace GiiMoteLib