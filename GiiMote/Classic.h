// Classic.h -  Contains functions that deal with the Classic Controller.


namespace GiiMoteLib {
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

////////////////////////////////////////////
// Triggers
////////////////////////////////////////////

	/// <summary>Sets the dead-zone value</summary>
	/// <remarks>Domain: [0.0,1.0]</remarks>
	/// <param name="val">The dead-zone value</param>
	/// <returns>1</returns>
	double GiiMote::wm_set_trigger_dead_zone(double val)
	{
		this->trigger_dead_zone = in_domain(val, 0, 1);
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

	// Normalized Functions
	/// <summary>Normalized joystick position</summary>
	/// <remarks>Domain: [-0.5,0.5]</remarks>
	/// <returns>The normalized X-position of the joystick</returns>
	double GiiMote::wm_classic_xpos(double stick)
	{
		double xx;
		try
		{
			switch ((int)stick)
			{
			case joyL:
				xx = (double)this->wmState->ClassicControllerState.JoystickL.X;
				break;
			case joyR:
				xx = (double)this->wmState->ClassicControllerState.JoystickR.X;
				break;
			default:
				throw (-1);
				break;
			}
		}
		catch(...)
		{
			return ( -1 );
		}

		if ( System::Math::Abs(xx) < (this->joystick_dead_zone) )
		{
			xx = 0;
		}
		return ( xx );
	}
	/// <summary>Normalized joystick position</summary>
	/// <remarks>Domain: [-0.5,0.5]</remarks>
	/// <returns>The normalized Y-position of the joystick</returns>
	double GiiMote::wm_classic_ypos(double stick)
	{
		double yy;
		try
		{
			switch ((int)stick)
			{
			case joyL:
				yy = (double)this->wmState->ClassicControllerState.JoystickL.Y;
				break;
			case joyR:
				yy = (double)this->wmState->ClassicControllerState.JoystickR.Y;
				break;
			default:
				throw (-1);
				break;
			}
		}
		catch(...)
		{
			return ( -1 );
		}

		if ( System::Math::Abs(yy) < (this->joystick_dead_zone) )
		{
			yy = 0;
		}	
		return ( yy );
	}

	// Raw Functions
	/// <summary>Raw joystick X-position</summary>
	/// <remarks>Domain: [0,255]</remarks>
	/// <returns>Raw joystick X-position</returns>
	double GiiMote::wm_classic_rawx(double stick)
	{
		double rawX;
		try
		{
			switch ((int)stick)
			{
			case joyL:
				rawX = (double)this->wmState->ClassicControllerState.RawJoystickL.X;
				break;
			case joyR:
				rawX = (double)this->wmState->ClassicControllerState.RawJoystickR.X;
				break;
			default:
				throw (-1);
				break;
			}
		}
		catch(...)
		{
			return ( -1 );
		}

		return (rawX);
	}
	/// <summary>Raw joystick Y-position</summary>
	/// <remarks>Domain: [0,255]</remarks>
	/// <returns>Raw joystick Y-position</returns>
	double GiiMote::wm_classic_rawy(double stick)
	{
		double rawY;
		try
		{
			switch ((int)stick)
			{
			case joyL:
				rawY = (double)this->wmState->ClassicControllerState.RawJoystickL.Y;
				break;
			case joyR:
				rawY = (double)this->wmState->ClassicControllerState.RawJoystickR.Y;
				break;
			default:
				throw (-1);
				break;
			}
		}
		catch (...)
		{
			return ( -1 );
		}

		return (rawY);
	}
	/// <summary>Joystick direction</summary>
	/// <returns>The direction of the joystick in degrees</returns>
	double GiiMote::wm_classic_direction(double stick)
	{
		double xx, yy;
		if (stick == joyR || stick == joyL)
		{
			xx = wm_classic_xpos(stick);
			yy = wm_classic_ypos(stick);
			if (xx != -1 && yy != -1)
			{
				return ( joystick_direction(xx,yy) );
			}
		}

		return ( -1 );
	}
	/// <summary>Joystick pressure</summary>
	/// <returns>The pressure on the joystick</returns>
	double GiiMote::wm_classic_pressure(double stick)
	{
		double xx, yy;
		if (stick == joyR || stick == joyL)
		{
			xx = wm_classic_xpos(stick);
			yy = wm_classic_ypos(stick);
			if (xx != -1 && yy != -1)
			{
				return ( joystick_pressure(xx,yy) );
			}
		}

		return ( -1 );
	}

////////////////////////////////////////////
// Calibration
////////////////////////////////////////////

	// Get Calibration
	/// <summary>
	/// Gets trigger calibration data
	/// </summary>
	/// <param name="trigger">
	/// The analog trigger to get calibration data for:
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
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_classic_get_calibration_maxtrigger(double trigger)
	{
		double returnValue = -1;
		switch ((int)trigger)
		{
		case btnL:
			returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MaxTriggerL);
			break;
		case btnR:
			returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MaxTriggerR);
			break;
		default:
			break;
		}
		return (returnValue);
	}

	/// <summary>
	/// Gets trigger calibration data
	/// </summary>
	/// <param name="trigger">
	/// The analog trigger to get calibration data for:
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
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_classic_get_calibration_mintrigger(double trigger)
	{
		double returnValue = -1;
		switch ((int)trigger)
		{
		case btnL:
			returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MinTriggerL);
			break;
		case btnR:
			returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MinTriggerR);
			break;
		default:
			break;
		}

		return (returnValue);
	}

	/// <summary>
	/// Gets X-axis joystick Calibration data
	/// </summary>
	/// <param name="joystick">
	/// The joystick to get calibration data for:
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>joyL</term>
	///         <description>Left Joystick</description>
	///     </item>
	///     <item>
	///			<term>joyR</term>
	///         <description>Right Joystick</description>
	///     </item>
	/// </list>
	/// </param>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_classic_get_calibration_maxx(double joystick)
	{
		double returnValue = -1;
		switch ((int)joystick)
		{
		case joyL:
			returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MaxXL);
			break;
		case joyR:
			returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MaxXR);
			break;
		default:
			break;
		}

		return (returnValue);
	}

	/// <summary>
	/// Gets X-axis joystick Calibration data
	/// </summary>
	/// <param name="joystick">
	/// The joystick to get calibration data for:
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>joyL</term>
	///         <description>Left Joystick</description>
	///     </item>
	///     <item>
	///			<term>joyR</term>
	///         <description>Right Joystick</description>
	///     </item>
	/// </list>
	/// </param>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_classic_get_calibration_minx(double joystick)
	{
		double returnValue = -1;
		switch ((int)joystick)
		{
		case joyL:
			returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MinXL);
			break;
		case joyR:
			returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MinXR);
			break;
		default:
			break;
		}
		return (returnValue);
	}

	/// <summary>
	/// Gets X-axis joystick Calibration data
	/// </summary>
	/// <param name="joystick">
	/// The joystick to get calibration data for:
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>joyL</term>
	///         <description>Left Joystick</description>
	///     </item>
	///     <item>
	///			<term>joyR</term>
	///         <description>Right Joystick</description>
	///     </item>
	/// </list>
	/// </param>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_classic_get_calibration_midx(double joystick)
	{
		double returnValue = -1;
		switch ((int)joystick)
		{
		case joyL:
			returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MidXL);
			break;
		case joyR:
			returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MidXR);
			break;
		default:
			break;
		}

		return (returnValue);
	}

	/// <summary>
	/// Gets Y-axis joystick Calibration data
	/// </summary>
	/// <param name="joystick">
	/// The joystick to get calibration data for:
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>joyL</term>
	///         <description>Left Joystick</description>
	///     </item>
	///     <item>
	///			<term>joyR</term>
	///         <description>Right Joystick</description>
	///     </item>
	/// </list>
	/// </param>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_classic_get_calibration_midy(double joystick)
	{
		double returnValue = -1;
		switch ((int)joystick)
		{
		case joyL:
			returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MidYL);
			break;
		case joyR:
			returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MidYR);
			break;
		default:
			break;
		}
		return (returnValue);
	}

	/// <summary>
	/// Gets Y-axis joystick Calibration data
	/// </summary>
	/// <param name="joystick">
	/// The joystick to get calibration data for:
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>joyL</term>
	///         <description>Left Joystick</description>
	///     </item>
	///     <item>
	///			<term>joyR</term>
	///         <description>Right Joystick</description>
	///     </item>
	/// </list>
	/// </param>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_classic_get_calibration_maxy(double joystick)
	{
		double returnValue = -1;
		switch ((int)joystick)
		{
		case joyL:
			returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MaxYL);
			break;
		case joyR:
			returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MaxYR);
			break;
		default:
			break;
		}
		return (returnValue);
	}

	/// <summary>
	/// Gets Y-axis joystick Calibration data
	/// </summary>
	/// <param name="joystick">
	/// The joystick to get calibration data for:
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>joyL</term>
	///         <description>Left Joystick</description>
	///     </item>
	///     <item>
	///			<term>joyR</term>
	///         <description>Right Joystick</description>
	///     </item>
	/// </list>
	/// </param>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_classic_get_calibration_miny(double joystick)
	{
		double returnValue = -1;

		switch ((int)joystick)
		{
		case joyL:
			returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MinYL);
			break;
		case joyR:
			returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MinYR);
			break;
		default:
			break;
		}
		return (returnValue);
	}
	// Set Calibration
	/// <summary>
	/// Sets trigger calibration data
	/// </summary>
	/// <param name="trigger">
	/// The analog trigger to calibrate:
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
	/// <param name="val">The calibration value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_classic_set_calibration_maxtrigger(double trigger, double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			switch ((int)trigger)
			{
			case btnL:
				this->wmState->ClassicControllerState.CalibrationInfo.MaxTriggerL = calData;
				break;
			case btnR:
				this->wmState->ClassicControllerState.CalibrationInfo.MaxTriggerR = calData;
				break;
			default:
				throw 1;
				break;
			}
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}

	/// <summary>
	/// Sets trigger calibration data
	/// </summary>
	/// <param name="trigger">
	/// The analog trigger to calibrate:
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
	/// <param name="val">The calibration value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_classic_set_calibration_mintrigger(double trigger, double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			switch ((int)trigger)
			{
			case btnL:
				this->wmState->ClassicControllerState.CalibrationInfo.MinTriggerL = calData;
				break;
			case btnR:
				this->wmState->ClassicControllerState.CalibrationInfo.MinTriggerR = calData;
				break;
			default:
				throw 1;
				break;
			}
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}

	/// <summary>
	/// Sets X-axis joystick calibration data
	/// </summary>
	/// <param name="joystick">
	/// The joystick to calibrate:
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>joyL</term>
	///         <description>Left Joystick</description>
	///     </item>
	///     <item>
	///			<term>joyR</term>
	///         <description>Right Joystick</description>
	///     </item>
	/// </list>
	/// </param>
	/// <param name="val">MaxX value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_classic_set_calibration_maxx(double joystick, double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			switch ((int)joystick)
			{
			case joyL:
				this->wmState->ClassicControllerState.CalibrationInfo.MaxXL = calData;
				break;
			case joyR:
				this->wmState->ClassicControllerState.CalibrationInfo.MaxXR = calData;
				break;
			default:
				throw 1;
				break;
			}
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}

	/// <summary>
	/// Sets X-axis joystick calibration data
	/// </summary>
	/// <param name="joystick">
	/// The joystick to calibrate:
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>joyL</term>
	///         <description>Left Joystick</description>
	///     </item>
	///     <item>
	///			<term>joyR</term>
	///         <description>Right Joystick</description>
	///     </item>
	/// </list>
	/// </param>
	/// <param name="val">MinX value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_classic_set_calibration_minx(double joystick, double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			switch ((int)joystick)
			{
			case joyL:
				this->wmState->ClassicControllerState.CalibrationInfo.MinXL = calData;
				break;
			case joyR:
				this->wmState->ClassicControllerState.CalibrationInfo.MinXR = calData;
				break;
			default:
				throw 1;
				break;
			}
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}

	/// <summary>
	/// Sets X-axis joystick calibration data
	/// </summary>
	/// <param name="joystick">
	/// The joystick to calibrate:
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>joyL</term>
	///         <description>Left Joystick</description>
	///     </item>
	///     <item>
	///			<term>joyR</term>
	///         <description>Right Joystick</description>
	///     </item>
	/// </list>
	/// </param>
	/// <param name="val">MidX value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_classic_set_calibration_midx(double joystick, double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			switch ((int)joystick)
			{
			case joyL:
				this->wmState->ClassicControllerState.CalibrationInfo.MidXL = calData;
				break;
			case joyR:
				this->wmState->ClassicControllerState.CalibrationInfo.MidXR = calData;
				break;
			default:
				throw 1;
				break;
			}
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}

	/// <summary>
	/// Sets Y-axis joystick calibration data
	/// </summary>
	/// <param name="joystick">
	/// The joystick to calibrate:
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>joyL</term>
	///         <description>Left Joystick</description>
	///     </item>
	///     <item>
	///			<term>joyR</term>
	///         <description>Right Joystick</description>
	///     </item>
	/// </list>
	/// </param>
	/// <param name="val">MidY value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_classic_set_calibration_midy(double joystick, double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			switch ((int)joystick)
			{
			case joyL:
				this->wmState->ClassicControllerState.CalibrationInfo.MidYL = calData;
				break;
			case joyR:
				this->wmState->ClassicControllerState.CalibrationInfo.MidYR = calData;
				break;
			default:
				throw 1;
				break;
			}
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}

	/// <summary>
	/// Sets Y-axis joystick calibration data
	/// </summary>
	/// <param name="joystick">
	/// The joystick to calibrate:
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>joyL</term>
	///         <description>Left Joystick</description>
	///     </item>
	///     <item>
	///			<term>joyR</term>
	///         <description>Right Joystick</description>
	///     </item>
	/// </list>
	/// </param>
	/// <param name="val">MaxY value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_classic_set_calibration_maxy(double joystick, double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			switch ((int)joystick)
			{
			case joyL:
				this->wmState->ClassicControllerState.CalibrationInfo.MaxYL = calData;
				break;
			case joyR:
				this->wmState->ClassicControllerState.CalibrationInfo.MaxYR = calData;
				break;
			default:
				throw 1;
				break;
			}
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}

	/// <summary>
	/// Sets Y-axis joystick calibration data
	/// </summary>
	/// <param name="joystick">
	/// The joystick to calibrate:
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>joyL</term>
	///         <description>Left Joystick</description>
	///     </item>
	///     <item>
	///			<term>joyR</term>
	///         <description>Right Joystick</description>
	///     </item>
	/// </list>
	/// </param>
	/// <param name="val">MinY value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_classic_set_calibration_miny(double joystick, double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			switch ((int)joystick)
			{
			case joyL:
				this->wmState->ClassicControllerState.CalibrationInfo.MinYL = calData;
				break;
			case joyR:
				this->wmState->ClassicControllerState.CalibrationInfo.MinYR = calData;
				break;
			default:
				throw 1;
				break;
			}
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
} // GiiMoteLib