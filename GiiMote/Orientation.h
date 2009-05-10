// Orientation.h - Contains functions for getting data from the Wii Remote and expansions
//			       accelerometers.
// Copyright 2007 Sam Whited
//
//    This file is part of GiiMote.
//
//    GiiMote is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Lesser General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    GiiMote is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Lesser General Public License for more details.
//
//    You should have received a copy of the GNU Lesser General Public License
//    along with GiiMote.  If not, see <http://www.gnu.org/licenses/>.

    /////////////////////////
    // Wii Remote
    /////////////////////////

	/// <summary>Is the Wii Remote moving?</summary>
	/// <returns>
	/// True if the cummulative scalar force acting on the Wii Remote is greater than G, false otherwise.
	/// -1 on error.
	/// </returns>
	double wm_get_moving()
	{
		try
		{
			float csf = Math::Abs( GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelState.Values.X ) + Math::Abs( GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelState.Values.Y ) + Math::Abs( GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelState.Values.Z );
			if (  csf >= 1.5 )
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
    double wm_get_roll()
    {
		double roll = 0;

		try
		{
			if ( !wm_get_moving() )
			{
				roll = -Math::Atan2(double(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelState.Values.X), Math::Sqrt( Math::Pow(double(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelState.Values.Y), 2) + Math::Pow(double(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelState.Values.Z), 2)) ) - Math::PI/2;
			}
			else
			{
				throw ( 0 );
			}
		}
		catch(...)
		{
			// If the Wii Remote is accelerating, use the IR.
			if (GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[0].Found && GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[1].Found)
			{
				Math::Atan2(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[1].Position.Y - GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[0].Position.Y, GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[1].Position.X - GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[0].Position.X);
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
    double wm_get_pitch()
    {
		double pitch = 0;

		try
		{
			if ( !wm_get_moving() )
			{
				pitch = -Math::Atan2( double(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelState.Values.Y), Math::Sqrt( Math::Pow(double(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelState.Values.X), 2) + Math::Pow(double(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelState.Values.Z), 2)) );
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
    double wm_get_yaw()
    {
		double yaw = 0;

		try
		{
			if (GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[0].Found && GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[1].Found)
			{
				double ax = ((double)Math::Abs(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[0].RawPosition.X) + (double)Math::Abs(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[1].RawPosition.X)) / 2;
				double z = 1023 - Math::Sqrt(Math::Pow((double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[1].RawPosition.X - (double)Math::Abs(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[1].RawPosition.X), 2) + Math::Pow((double)Math::Abs(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[0].RawPosition.Y) - (double)Math::Abs(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[1].RawPosition.Y), 2));
				yaw = Math::Atan2((ax - 512) * (z / 1024), z);
				// yaw = Math::Atan2(512 - GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.RawX1, 600);
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
	double wm_get_altitude()
	{
		if (GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[0].Found && GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[1].Found)
		{
			// return ( ( -54 * Math::Abs(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.X2 - GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.X1) + 77 ) * 100 );
			return ( 264 / Math::Abs(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[0].RawPosition.X - GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[1].RawPosition.X) );
		}
		else
		{
			return ( -1 );
		}
	}
