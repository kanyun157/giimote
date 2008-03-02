// Classic.h -  Contains functions that deal with the Classic Controller.
//				For joystick functions, see "Joystick.h".
//				For button checking, see "GMButtons.h".


namespace GiiMoteLib {
	// Get Calibration
	/// <summary>
	/// Gets trigger calibration data
	/// </summary>
	/// <param name="trigger">
	/// The analog trigger to get calibration data for:
	/// <list type="bullet">
	///     <item>
	///         <description>btnL</description>
	///     </item>
	///     <item>
	///         <description>btnR</description>
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
	/// The trigger to get calibration data for:
	/// <list type="bullet">
	///     <item>
	///         <description>btnL</description>
	///     </item>
	///     <item>
	///         <description>btnR</description>
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
	///     <item>
	///         <description>joyL</description>
	///     </item>
	///     <item>
	///         <description>joyR</description>
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
	///     <item>
	///         <description>joyL</description>
	///     </item>
	///     <item>
	///         <description>joyR</description>
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
	///     <item>
	///         <description>joyL</description>
	///     </item>
	///     <item>
	///         <description>joyR</description>
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
	///     <item>
	///         <description>joyL</description>
	///     </item>
	///     <item>
	///         <description>joyR</description>
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
	///     <item>
	///         <description>joyL</description>
	///     </item>
	///     <item>
	///         <description>joyR</description>
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
	///     <item>
	///         <description>joyL</description>
	///     </item>
	///     <item>
	///         <description>joyR</description>
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
	///     <item>
	///         <description>btnL</description>
	///     </item>
	///     <item>
	///         <description>btnR</description>
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
	///     <item>
	///         <description>btnL</description>
	///     </item>
	///     <item>
	///         <description>btnR</description>
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
	///     <item>
	///         <description>joyL</description>
	///     </item>
	///     <item>
	///         <description>joyR</description>
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
	///     <item>
	///         <description>joyL</description>
	///     </item>
	///     <item>
	///         <description>joyR</description>
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
	///     <item>
	///         <description>joyL</description>
	///     </item>
	///     <item>
	///         <description>joyR</description>
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
	///     <item>
	///         <description>joyL</description>
	///     </item>
	///     <item>
	///         <description>joyR</description>
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
	///     <item>
	///         <description>joyL</description>
	///     </item>
	///     <item>
	///         <description>joyR</description>
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
	///     <item>
	///         <description>joyL</description>
	///     </item>
	///     <item>
	///         <description>joyR</description>
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