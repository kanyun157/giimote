// GMButtons.h - Contains information on the buttons and triggers
//				 used by the Wii Remote and Expansions.

namespace GiiMoteLib {

////////////////////////////////////////////
// Buttons
////////////////////////////////////////////
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

	// Normalized Functions
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