// Joystick.h - Contains functions to use joysticks that expand the functionality
//				of the Wii Remote.

namespace GiiMoteLib {

	/////////////////////////
	// General
	/////////////////////////

	double GiiMote::joystick_direction(double xx, double yy)
	{
		return ( System::Math::Atan2(yy,xx) );
	}

	/////////////////////////
	// Nunchuck (Expansion)
	/////////////////////////

	// Normalized Functions
	double GiiMote::wm_nunchuck_xpos()
	{
		double xx = (double)this->wmState->NunchukState.X;
		if ( System::Math::Abs(xx) < (this->dead_zone) )
		{
			xx = 0;
		}
		return ( xx );
	}

	double GiiMote::wm_nunchuck_ypos()
	{
		double yy = (double)this->wmState->NunchukState.Y;
		if ( System::Math::Abs(yy) < (this->dead_zone) )
		{
			yy = 0;
		}	
		return ( yy );
	}

	double GiiMote::wm_nunchuck_direction()
	{
		return (joystick_direction(wm_nunchuck_xpos(),wm_nunchuck_ypos()));
	}

	// Raw Functions
	double GiiMote::wm_nunchuck_rawx()
	{
		return ( (double)this->wmState->NunchukState.RawX );
	}

	double GiiMote::wm_nunchuck_rawy()
	{
		return ( (double)this->wmState->NunchukState.RawY );
	}

	/////////////////////////
	// Classic Controller
	/////////////////////////

	// Normalized Functions
	double GiiMote::wm_classic_xpos(double stick)
	{
		double xx;
		switch ((int)stick)
		{
		case joyL:
			xx = (this->wmState->ClassicControllerState.XL);
			break;
		case joyR:
			xx = (this->wmState->ClassicControllerState.XR);
			break;
		default:
			xx = -1;
			break;
		}
		if ( System::Math::Abs(xx) < (this->dead_zone) )
		{
			xx = 0;
		}
		return ( xx );
	}

	double GiiMote::wm_classic_ypos(double stick)
	{
		double yy;	
		switch ((int)stick)
		{
		case joyL:
			yy = (this->wmState->ClassicControllerState.YL);
			break;
		case joyR:
			yy = (this->wmState->ClassicControllerState.YR);
			break;
		default:
			yy = -1;
			break;
		}
		if ( System::Math::Abs(yy) < (this->dead_zone) )
		{
			yy = 0;
		}	
		return ( yy );
	}

	// Raw Functions

	double GiiMote::wm_classic_rawx(double stick)
	{
		if (stick == joyL)
		{
			return (this->wmState->ClassicControllerState.RawXL);
		}
		if (stick == joyR)
		{
			return (this->wmState->ClassicControllerState.RawXR);
		}
		return (-1);
	}

	double GiiMote::wm_classic_rawy(double stick)
	{
	
		if (stick == joyL)
		{
			return (this->wmState->ClassicControllerState.RawYL);
		}
		if (stick == joyR)
		{
			return (this->wmState->ClassicControllerState.RawYR);
		}
		return (-1);
	}

	double GiiMote::wm_classic_direction(double stick)
	{
		if (stick == joyR || stick == joyL)
		{
			return (joystick_direction( wm_classic_xpos(stick) , wm_classic_ypos(stick) ));
		}
		else
		{
			return (0);
		}
	}

} // namespace GiiMoteLib