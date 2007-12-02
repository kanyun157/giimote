// Classic.h -  Contains functions that deal with the Classic Controller.
//				For joystick functions, see "Joystick.h".
//				For button checking, see "GMButtons.h".

namespace GiiMoteLib {
	// Get Calibration
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