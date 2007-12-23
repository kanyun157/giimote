// Joystick.h - Contains functions to use joysticks that expand the functionality
//				of the Wii Remote.

namespace GiiMoteLib {

	/////////////////////////
	// General
	/////////////////////////

	double GiiMote::joystick_direction(double xx, double yy)
	{
		return ( System::Math::Atan2(yy,xx) * ( 180 / System::Math::PI ) );
	}

	double GiiMote::joystick_pressure(double xx, double yy)
	{
		return ( System::Math::Sqrt( ( xx * xx ) + ( yy * yy ) ) / System::Math::Sqrt( 0.5 ) );
	}

	/////////////////////////
	// Nunchuck (Expansion)
	/////////////////////////

	// Normalized Functions
	double GiiMote::wm_nunchuck_xpos()
	{
		double xx;
		try
		{
			xx = (double)this->wmState->NunchukState.X;
		}
		catch(...)
		{
			return ( -1 );
		}
		if ( System::Math::Abs(xx) < (this->dead_zone) )
		{
			xx = 0;
		}
		return ( xx );
	}

	double GiiMote::wm_nunchuck_ypos()
	{
		double yy;
		try
		{
			yy = (double)this->wmState->NunchukState.Y;
		}
		catch(...)
		{
			return ( -1 );
		}
		if ( System::Math::Abs(yy) < (this->dead_zone) )
		{
			yy = 0;
		}	
		return ( yy );
	}

	double GiiMote::wm_nunchuck_direction()
	{
		double xx = wm_nunchuck_xpos();
		double yy = wm_nunchuck_ypos();
		if (xx == -1 || yy == -1)
		{
			return ( -1 );
		}
		else
		{
			return ( joystick_direction(xx,yy) );
		}
	}

	double GiiMote::wm_nunchuck_pressure()
	{
		double xx = wm_nunchuck_xpos();
		double yy = wm_nunchuck_ypos();
		if (xx == -1 || yy == -1)
		{
			return ( -1 );
		}
		else
		{
			return ( joystick_pressure(xx,yy) );
		}
	}

	// Raw Functions
	double GiiMote::wm_nunchuck_rawx()
	{
		double rawX;
		try
		{
			rawX = (double)this->wmState->NunchukState.RawX;
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( rawX );
	}

	double GiiMote::wm_nunchuck_rawy()
	{
		double rawY;
		try
		{
			rawY = (double)this->wmState->NunchukState.RawY;
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( rawY );
	}

	/////////////////////////
	// Classic Controller
	/////////////////////////

	// Normalized Functions
	double GiiMote::wm_classic_xpos(double stick)
	{
		double xx;
		try
		{
			switch ((int)stick)
			{
			case joyL:
				xx = (double)this->wmState->ClassicControllerState.XL;
				break;
			case joyR:
				xx = (double)this->wmState->ClassicControllerState.XR;
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

		if ( System::Math::Abs(xx) < (this->dead_zone) )
		{
			xx = 0;
		}
		return ( xx );
	}

	double GiiMote::wm_classic_ypos(double stick)
	{
		double yy;
		try
		{
			switch ((int)stick)
			{
			case joyL:
				yy = (double)this->wmState->ClassicControllerState.YL;
				break;
			case joyR:
				yy = (double)this->wmState->ClassicControllerState.YR;
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

		if ( System::Math::Abs(yy) < (this->dead_zone) )
		{
			yy = 0;
		}	
		return ( yy );
	}

	// Raw Functions

	double GiiMote::wm_classic_rawx(double stick)
	{
		double rawX;
		try
		{
			switch ((int)stick)
			{
			case joyL:
				rawX = (double)this->wmState->ClassicControllerState.RawXL;
				break;
			case joyR:
				rawX = (double)this->wmState->ClassicControllerState.RawXR;
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

	double GiiMote::wm_classic_rawy(double stick)
	{
		double rawY;
		try
		{
			switch ((int)stick)
			{
			case joyL:
				rawY = (double)this->wmState->ClassicControllerState.RawYL;
				break;
			case joyR:
				rawY = (double)this->wmState->ClassicControllerState.RawYR;
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

} // namespace GiiMoteLib