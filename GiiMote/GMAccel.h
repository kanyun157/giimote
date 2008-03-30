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
	/// <param name="dz_index">The index of the dead-zone to use</param>
    /// <returns>Acceleration</returns>
    double GiiMote::wm_calc_accel(float accel, int dz_index)
    {
            double val = (double)accel;
            if ( System::Math::Abs(val) < this->accel_dead_zone[dz_index] )
            {
                    val = 0;
            }
            return ( val );
    }

	/////////////////////////
	// Wii Remote
	/////////////////////////
	// Normalized Data
	/// <summary>Normalized accelerometer data</summary>
	/// <remarks>Domain: [0,?)</remarks>
	/// <returns>Normalized acceleration</returns>
	double GiiMote::wm_get_accel_x()
	{
		return ( wm_calc_accel(this->wmState->AccelState.X, 0) );
	}
	/// <summary>Normalized accelerometer data</summary>
	/// <remarks>Domain: [0,?)</remarks>
	/// <returns>Normalized acceleration</returns>
	double GiiMote::wm_get_accel_y()
	{
		return ( wm_calc_accel(this->wmState->AccelState.Y, 1) );
	}
	/// <summary>Normalized accelerometer data</summary>
	/// <remarks>Domain: [0,?)</remarks>
	/// <returns>Normalized acceleration</returns>
	double GiiMote::wm_get_accel_z()
	{
		return ( wm_calc_accel(this->wmState->AccelState.Z, 2) );
	}
	// Raw Data
	/// <summary>Raw accelerometer data</summary>
	/// <remarks>Domain: [0,255]</remarks>
	/// <returns>Raw acceleration</returns>
	double GiiMote::wm_get_accel_rawx()
	{
		return ( (double)this->wmState->AccelState.RawX );
	}
	/// <summary>Raw accelerometer data</summary>
	/// <remarks>Domain: [0,255]</remarks>
	/// <returns>Raw acceleration</returns>
	double GiiMote::wm_get_accel_rawy()
	{
		return ( (double)this->wmState->AccelState.RawY );
	}
	/// <summary>Raw accelerometer data</summary>
	/// <remarks>Domain: [0,255]</remarks>
	/// <returns>Raw acceleration</returns>
	double GiiMote::wm_get_accel_rawz()
	{
		return ( (double)this->wmState->AccelState.RawZ );
	}
	/// <summary>Sets the dead-zone value</summary>
	/// <remarks>Domain: [0,Infinity]</remarks>
	/// <param name="val">The dead-zone value</param>
	/// <returns>1</returns>
	double GiiMote::wm_set_accel_dead_zone_x(double val)
	{
		accel_dead_zone[0] = in_domain<double>(val, 0, -1);
		return ( 1 );
	}
	/// <summary>Sets the dead-zone value</summary>
	/// <remarks>Domain: [0,Infinity]</remarks>
	/// <param name="val">The dead-zone value</param>
	/// <returns>1</returns>
	double GiiMote::wm_set_accel_dead_zone_y(double val)
	{
		accel_dead_zone[1] = in_domain<double>(val, 0, -1);
		return ( 1 );
	}
	/// <summary>Sets the dead-zone value</summary>
	/// <remarks>Domain: [0,Infinity]</remarks>
	/// <param name="val">The dead-zone value</param>
	/// <returns>1</returns>
	double GiiMote::wm_set_accel_dead_zone_z(double val)
	{
		accel_dead_zone[2] = in_domain<double>(val, 0, -1);
		return ( 1 );
	}
	/// <summary>Gets the dead-zone value</summary>
	/// <returns>X-axis dead zone</returns>
	double GiiMote::wm_get_accel_dead_zone_x()
	{
		return ( accel_dead_zone[0] );
	}
	/// <summary>Gets the dead-zone value</summary>
	/// <returns>Y-axis dead zone</returns>
	double GiiMote::wm_get_accel_dead_zone_y()
	{
		return ( accel_dead_zone[1] );
	}
	/// <summary>Gets the dead-zone value</summary>
	/// <returns>Z-axis dead zone</returns>
	double GiiMote::wm_get_accel_dead_zone_z()
	{
		return ( accel_dead_zone[2] );
	}
	/////////////////////////
	// Nunchuck
	/////////////////////////
	// Normalized Data
	/// <summary>Normalized accelerometer data</summary>
	/// <remarks>Domain: [0,?)</remarks>
	/// <returns>Normalized acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_x()
	{
		return ( wm_calc_accel(this->wmState->AccelState.X, 3) );
	}
	/// <summary>Normalized accelerometer data</summary>
	/// <remarks>Domain: [0,?)</remarks>
	/// <returns>Normalized acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_y()
	{
		return ( wm_calc_accel(this->wmState->NunchukState.AccelState.Y, 4) );
	}
	/// <summary>Normalized accelerometer data</summary>
	/// <remarks>Domain: [0,?)</remarks>
	/// <returns>Normalized acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_z()
	{
		return ( wm_calc_accel(this->wmState->NunchukState.AccelState.Z, 5) );
	}
	// Raw Data
	/// <summary>Raw accelerometer data</summary>
	/// <remarks>Domain: [0,255]</remarks>
	/// <returns>Raw acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_rawx()
	{
		return ( (double)this->wmState->NunchukState.AccelState.RawX );
	}
	/// <summary>Raw accelerometer data</summary>
	/// <remarks>Domain: [0,255]</remarks>
	/// <returns>Raw acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_rawy()
	{
		return ( (double)this->wmState->NunchukState.AccelState.RawY );
	}
	/// <summary>Raw accelerometer data</summary>
	/// <remarks>Domain: [0,255]</remarks>
	/// <returns>Raw acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_rawz()
	{
		return ( (double)this->wmState->NunchukState.AccelState.RawZ );
	}
	/// <summary>Sets the dead-zone value</summary>
	/// <remarks>Domain: [0,Infinity]</remarks>
	/// <param name="val">The dead-zone value</param>
	/// <returns>1</returns>
	double GiiMote::wm_nunchuck_set_accel_dead_zone_x(double val)
	{
		accel_dead_zone[3] = in_domain<double>(val, 0, -1);
		return ( 1 );
	}
	/// <summary>Sets the dead-zone value</summary>
	/// <remarks>Domain: [0,Infinity]</remarks>
	/// <param name="val">The dead-zone value</param>
	/// <returns>1</returns>
	double GiiMote::wm_nunchuck_set_accel_dead_zone_y(double val)
	{
		accel_dead_zone[4] = in_domain<double>(val, 0, -1);
		return ( 1 );
	}
	/// <summary>Sets the dead-zone value</summary>
	/// <remarks>Domain: [0,Infinity]</remarks>
	/// <param name="val">The dead-zone value</param>
	/// <returns>1</returns>
	double GiiMote::wm_nunchuck_set_accel_dead_zone_z(double val)
	{
		accel_dead_zone[5] = in_domain<double>(val, 0, -1);
		return ( 1 );
	}
	/// <summary>Gets the dead-zone value</summary>
	/// <returns>X-axis dead zone</returns>
	double GiiMote::wm_nunchuck_get_accel_dead_zone_x()
	{
		return ( accel_dead_zone[3] );
	}
	/// <summary>Gets the dead-zone value</summary>
	/// <returns>Y-axis dead zone</returns>
	double GiiMote::wm_nunchuck_get_accel_dead_zone_y()
	{
		return ( accel_dead_zone[4] );
	}
	/// <summary>Gets the dead-zone value</summary>
	/// <returns>Z-axis dead zone</returns>
	double GiiMote::wm_nunchuck_get_accel_dead_zone_z()
	{
		return ( accel_dead_zone[5] );
	}



} // namespace GiiMoteLib