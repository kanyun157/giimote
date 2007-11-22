// Classic.h -  Contains functions that deal with the Classic Controller.
//				For joystick functions, see "Joystick.h".
//				For button checking, see "GMButtons.h".

namespace GiiMoteLib {
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
} // GiiMoteLib