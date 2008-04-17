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

		if (Math::Abs(wmState->AccelState.X) + Math::Abs(wmState->AccelState.Y) + Math::Abs(wmState->AccelState.Z) <= 1.15)
		{
			try
			{
				roll = -Math::Atan2(double(wmState->AccelState.X), Math::Sqrt( Math::Pow(double(wmState->AccelState.Y), 2) + Math::Pow(double(wmState->AccelState.Z), 2)) );
			}
			catch(...)
			{
				// Do Nothing
			}
		}
		else
		{
			if (this->wmState->IRState.Found1 && this->wmState->IRState.Found2)
			{
			}
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
			pitch = -Math::Atan2( double(wmState->AccelState.Y), Math::Sqrt( Math::Pow(double(wmState->AccelState.X), 2) + Math::Pow(double(wmState->AccelState.Z), 2)) );
		}
		catch(...)
		{
			return ( 0 );
		}

		return ( pitch * (180 / Math::PI) );
    }

    /// <summary>The yaw of the Wii Remote</summary>
    /// <returns>Yaw in degrees</returns>
    double GiiMote::wm_get_yaw()
    {
		double yaw = 0;

		try
		{
			if (this->wmState->IRState.Found1)
			{
				// This is not right at all...
				yaw = Math::Atan2(512 - this->wmState->IRState.RawX1, 600);
			}
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( yaw * (180 / Math::PI) );
    }

	/// <summary>Distance of the Wii Remote from the sensor bar</summary>
	/// <returns>Distance in meters</returns>
	double GiiMote::wm_get_altitude()
	{
		if (this->wmState->IRState.Found1 && this->wmState->IRState.Found2)
		{
			// return ( ( -54 * Math::Abs(this->wmState->IRState.X2 - this->wmState->IRState.X1) + 77 ) * 100 );
			return ( 264 / Math::Abs(this->wmState->IRState.RawX1 - this->wmState->IRState.RawX2) );
		}
		else
		{
			return ( -1 );
		}
	}
} // namespace GiiMoteLib