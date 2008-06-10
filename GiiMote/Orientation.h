// Orientation.h - Contains functions for getting data from the Wii Remote and expansions
//			   accelerometers.

namespace GiiMoteLib {
    /////////////////////////
    // Wii Remote
    /////////////////////////

	/// <summary>Is the Wii Remote moving?</summary>
	/// <returns>
	/// True if the cummulative scalar force acting on the Wii Remote is greater than G, false otherwise.
	/// -1 on error.
	/// </returns>
	double GiiMote::wm_get_moving()
	{
		try
		{
			float csf = Math::Abs( this->wc[wmIndex]->WiimoteState->AccelState.Values.X + this->wc[wmIndex]->WiimoteState->AccelState.Values.Y + this->wc[wmIndex]->WiimoteState->AccelState.Values.Z );
			if (  csf > 1.5 || csf < 0.5 )
			{
				return ( 1 );
			}
			else
			{
				return ( 0 );
			}
		}
		catch(...)
		{
			return ( -1 );
		}
	}

    /// <summary>The roll of the Wii Remote</summary>
    /// <returns>Roll in degrees or -1000 on error.</returns>
    double GiiMote::wm_get_roll()
    {
		double roll = 0;

		try
		{
			if ( !wm_get_moving() )
			{
				roll = -Math::Atan2(double(this->wc[wmIndex]->WiimoteState->AccelState.Values.X), Math::Sqrt( Math::Pow(double(this->wc[wmIndex]->WiimoteState->AccelState.Values.Y), 2) + Math::Pow(double(this->wc[wmIndex]->WiimoteState->AccelState.Values.Z), 2)) ) - Math::PI/2;
			}
			else
			{
				throw ( 0 );
			}
		}
		catch(...)
		{
			// If the Wii Remote is accelerating, use the IR.
			if (this->wc[wmIndex]->WiimoteState->IRState.IRSensors[0].Found && this->wc[wmIndex]->WiimoteState->IRState.IRSensors[1].Found)
			{
				Math::Atan2(this->wc[wmIndex]->WiimoteState->IRState.IRSensors[1].Position.Y - this->wc[wmIndex]->WiimoteState->IRState.IRSensors[0].Position.Y, this->wc[wmIndex]->WiimoteState->IRState.IRSensors[1].Position.X - this->wc[wmIndex]->WiimoteState->IRState.IRSensors[0].Position.X);
			}
			else
			{
				return ( -1000 );
			}
		}

		return ( roll * (180 / Math::PI) );
    }
    /// <summary>The pitch of the Wii Remote</summary>
    /// <returns>Pitch in degrees or -1000 on error</returns>
    double GiiMote::wm_get_pitch()
    {
		double pitch = 0;

		try
		{
			if ( !wm_get_moving() )
			{
				pitch = -Math::Atan2( double(wc[wmIndex]->WiimoteState->AccelState.Values.Y), Math::Sqrt( Math::Pow(double(wc[wmIndex]->WiimoteState->AccelState.Values.X), 2) + Math::Pow(double(wc[wmIndex]->WiimoteState->AccelState.Values.Z), 2)) );
			}
			else
			{
				throw ( 0 );
			}
		}
		catch(...)
		{
			return ( -1000 );
		}

		return ( pitch * (180 / Math::PI) );
    }

    /// <summary>The yaw of the Wii Remote</summary>
    /// <returns>Yaw in degrees or -1000 on error</returns>
    double GiiMote::wm_get_yaw()
    {
		double yaw = 0;

		try
		{
			if (this->wc[wmIndex]->WiimoteState->IRState.IRSensors[0].Found && this->wc[wmIndex]->WiimoteState->IRState.IRSensors[1].Found)
			{
				double ax = ((double)Math::Abs(this->wc[wmIndex]->WiimoteState->IRState.IRSensors[0].RawPosition.X) + (double)Math::Abs(this->wc[wmIndex]->WiimoteState->IRState.IRSensors[1].RawPosition.X)) / 2;
				double z = 1023 - Math::Sqrt(Math::Pow((double)this->wc[wmIndex]->WiimoteState->IRState.IRSensors[1].RawPosition.X - (double)Math::Abs(this->wc[wmIndex]->WiimoteState->IRState.IRSensors[1].RawPosition.X), 2) + Math::Pow((double)Math::Abs(this->wc[wmIndex]->WiimoteState->IRState.IRSensors[0].RawPosition.Y) - (double)Math::Abs(this->wc[wmIndex]->WiimoteState->IRState.IRSensors[1].RawPosition.Y), 2));
				yaw = Math::Atan2((ax - 512) * (z / 1024), z);
				// yaw = Math::Atan2(512 - this->wc[wmIndex]->WiimoteState->IRState.RawX1, 600);
			}
		}
		catch(...)
		{
			return ( -1000 );
		}

		return ( yaw * (180 / Math::PI) );
    }

	/// <summary>Distance of the Wii Remote from the sensor bar</summary>
	/// <returns>Distance in meters</returns>
	double GiiMote::wm_get_altitude()
	{
		if (this->wc[wmIndex]->WiimoteState->IRState.IRSensors[0].Found && this->wc[wmIndex]->WiimoteState->IRState.IRSensors[1].Found)
		{
			// return ( ( -54 * Math::Abs(this->wc[wmIndex]->WiimoteState->IRState.X2 - this->wc[wmIndex]->WiimoteState->IRState.X1) + 77 ) * 100 );
			return ( 264 / Math::Abs(this->wc[wmIndex]->WiimoteState->IRState.IRSensors[0].RawPosition.X - this->wc[wmIndex]->WiimoteState->IRState.IRSensors[1].RawPosition.X) );
		}
		else
		{
			return ( -1 );
		}
	}
} // namespace GiiMoteLib