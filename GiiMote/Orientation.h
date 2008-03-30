// Orientation.h - Contains functions for getting data from the Wii Remote and expansions
//			   accelerometers.

namespace GiiMoteLib {
    /////////////////////////
    // Wii Remote
    /////////////////////////

    /// <summary>The roll of the Wii Remote</summary>
    /// <returns>Roll in degrees</returns>
    double GiiMote::wm_get_roll()
    {
		double roll = 0;

		try
		{
			roll = Math::Atan2( double(wmState->AccelState.Z), double(wmState->AccelState.X) );
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( roll * (180 / Math::PI) );
    }
    /// <summary>The pitch of the Wii Remote</summary>
    /// <returns>Pitch in degrees</returns>
    double GiiMote::wm_get_pitch()
    {
		double pitch = 0;

		try
		{
			pitch = Math::Atan2( double(wmState->AccelState.Z), double(wmState->AccelState.Y) );
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( pitch * (180 / Math::PI) );
    }

    /// <summary>The yaw of the Wii Remote</summary>
    /// <returns>Yaw in degrees</returns>
    double GiiMote::wm_get_yaw()
    {
		double yaw = 0;

		if (this->wmState->IRState.Found1)
		{
			yaw = Math::Atan2(512 - this->wmState->IRState.RawX1, 600);
		}

		return ( yaw );
    }

	/// <summary>Distance of the Wii Remote from the sensor bar</summary>
	/// <returns>Distance in XX</returns>
	double GiiMote::wm_get_altitude()
	{
		if (this->wmState->IRState.Found1 && this->wmState->IRState.Found2)
		{
			return ( 264 / Math::Abs(this->wmState->IRState.X2 - this->wmState->IRState.X1) );
		}
		else
		{
			return ( -1 );
		}
	}
} // namespace GiiMoteLib