// Joystick.h - Contains functions to use joysticks that expand the functionality
//				of the Wii Remote.

namespace GiiMoteLib {

	/////////////////////////
	// General
	/////////////////////////

	/// <summary>Calculates the direction of a joystick</summary>
	/// <param name="xx">The normalized X value of the joystick</param>
	/// <param name="yy">The normalized Y value of the joystick</param>
	/// <returns>The direction of the Joystick in degrees</returns>
	double GiiMote::joystick_direction(double xx, double yy)
	{
		return ( System::Math::Atan2(yy,xx) * ( 180 / System::Math::PI ) );
	}

	/// <summary>Calculates the pressure on a joystick</summary>
	/// <param name="xx">The normalized X value of the joystick</param>
	/// <param name="yy">The normalized Y value of the joystick</param>
	/// <returns>The pressure on the joystick</returns>
	double GiiMote::joystick_pressure(double xx, double yy)
	{
		return ( System::Math::Sqrt( System::Math::Pow(xx, 2) + System::Math::Pow(yy, 2) ) * 2 );
	}

	/// <summary>Sets the dead-zone value</summary>
	/// <remarks>Domain: [0.0,0.5]</remarks>
	/// <param name="val">The dead-zone value</param>
	/// <returns>1</returns>
	double GiiMote::wm_set_joystick_dead_zone(double val)
	{
		this->joystick_dead_zone = in_domain(val, 0, 0.5);
		return ( 1 );
	}

	/// <summary>Gets the dead-zone value</summary>
	/// <returns>Joystick dead-zone value</returns>
	double GiiMote::wm_get_joystick_dead_zone()
	{
		return ( this->joystick_dead_zone );
	}

	/////////////////////////
	// Nunchuck (Expansion)
	/////////////////////////

	// Normalized Functions
	/// <summary>Normalized joystick position</summary>
	/// <remarks>Domain: [-0.5,0.5]</remarks>
	/// <returns>The normalized X-position of the joystick</returns>
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
		if ( System::Math::Abs(xx) < (this->joystick_dead_zone) )
		{
			xx = 0;
		}
		return ( xx );
	}

	/// <summary>Normalized joystick position</summary>
	/// <remarks>Domain: [-0.5,0.5]</remarks>
	/// <returns>The normalized Y-position of the joystick</returns>
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
		if ( System::Math::Abs(yy) < (this->joystick_dead_zone) )
		{
			yy = 0;
		}	
		return ( yy );
	}

	/// <summary>Joystick direction</summary>
	/// <returns>The direction of the joystick in degrees</returns>
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

	/// <summary>Joystick pressure</summary>
	/// <returns>The pressure on the joystick</returns>
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
	/// <summary>Raw joystick X-position</summary>
	/// <remarks>Domain: [0,255]</remarks>
	/// <returns>Raw joystick X-position</returns>
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
	/// <summary>Raw joystick Y-position</summary>
	/// <remarks>Domain: [0,255]</remarks>
	/// <returns>Raw joystick Y-position</returns>
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

} // namespace GiiMoteLib