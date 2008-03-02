// GMAccel.h - Contains functions for getting data from the Wii Remote and expansions
//			   accelerometers.

namespace GiiMoteLib {

	/////////////////////////
	// General
	/////////////////////////
	/// <summary>
	/// Re-calculates the acceleration with dead-zones
	/// </summary>
	/// <param name="accel">Normalized acceleration data</param>
	/// <returns>Acceleration</returns>
	double GiiMote::wm_calc_accel(float accel)
	{
		double val = (double)accel;
		if ( System::Math::Abs(val) < this->accel_dead_zone )
		{
			val = 0;
		}
		return ( val );
	}

	/////////////////////////
	// Wii Remote
	/////////////////////////
	// Normalized Data
	/// <summary>
	/// Normalized accelerometer data
	/// </summary>
	/// <remarks>
	/// Domain: [0,?)
	/// </remarks>
	/// <returns>Normalized acceleration</returns>
	double GiiMote::wm_get_accel_x()
	{
		return ( wm_calc_accel(this->wmState->AccelState.X) );
	}
	/// <summary>
	/// Normalized accelerometer data
	/// </summary>
	/// <remarks>
	/// Domain: [0,?)
	/// </remarks>
	/// <returns>Normalized acceleration</returns>
	double GiiMote::wm_get_accel_y()
	{
		return ( wm_calc_accel(this->wmState->AccelState.Y) );
	}
	/// <summary>
	/// Normalized accelerometer data
	/// </summary>
	/// <remarks>
	/// Domain: [0,?)
	/// </remarks>
	/// <returns>Normalized acceleration</returns>
	double GiiMote::wm_get_accel_z()
	{
		return ( wm_calc_accel(this->wmState->AccelState.Z) );
	}
	// Raw Data
	/// <summary>
	/// Raw accelerometer data
	/// </summary>
	/// <remarks>
	/// Domain: [0,255]
	/// </remarks>
	/// <returns>Raw acceleration</returns>
	double GiiMote::wm_get_accel_rawx()
	{
		return ( (double)this->wmState->AccelState.RawX );
	}
	/// <summary>
	/// Raw accelerometer data
	/// </summary>
	/// <remarks>
	/// Domain: [0,255]
	/// </remarks>
	/// <returns>Raw acceleration</returns>
	double GiiMote::wm_get_accel_rawy()
	{
		return ( (double)this->wmState->AccelState.RawY );
	}
	/// <summary>
	/// Raw accelerometer data
	/// </summary>
	/// <remarks>
	/// Domain: [0,255]
	/// </remarks>
	/// <returns>Raw acceleration</returns>
	double GiiMote::wm_get_accel_rawz()
	{
		return ( (double)this->wmState->AccelState.RawZ );
	}

	/////////////////////////
	// Nunchuck
	/////////////////////////
	// Normalized Data
	/// <summary>
	/// Normalized accelerometer data
	/// </summary>
	/// <remarks>
	/// Domain: [0,?)
	/// </remarks>
	/// <returns>Normalized acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_x()
	{
		return ( wm_calc_accel(this->wmState->NunchukState.AccelState.X) );
	}
	/// <summary>
	/// Normalized accelerometer data
	/// </summary>
	/// <remarks>
	/// Domain: [0,?)
	/// </remarks>
	/// <returns>Normalized acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_y()
	{
		return ( wm_calc_accel(this->wmState->NunchukState.AccelState.Y) );
	}
	/// <summary>
	/// Normalized accelerometer data
	/// </summary>
	/// <remarks>
	/// Domain: [0,?)
	/// </remarks>
	/// <returns>Normalized acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_z()
	{
		return ( wm_calc_accel(this->wmState->NunchukState.AccelState.Z) );
	}
	// Raw Data
	/// <summary>
	/// Raw accelerometer data
	/// </summary>
	/// <remarks>
	/// Domain: [0,255]
	/// </remarks>
	/// <returns>Raw acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_rawx()
	{
		return ( (double)this->wmState->NunchukState.AccelState.RawX );
	}
	/// <summary>
	/// Raw accelerometer data
	/// </summary>
	/// <remarks>
	/// Domain: [0,255]
	/// </remarks>
	/// <returns>Raw acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_rawy()
	{
		return ( (double)this->wmState->NunchukState.AccelState.RawY );
	}
	/// <summary>
	/// Raw accelerometer data
	/// </summary>
	/// <remarks>
	/// Domain: [0,255]
	/// </remarks>
	/// <returns>Raw acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_rawz()
	{
		return ( (double)this->wmState->NunchukState.AccelState.RawZ );
	}

} // namespace GiiMoteLib