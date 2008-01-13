// GMAccel.h - Contains functions for getting data from the Wii Remote and expansions
//			   accelerometers.

namespace GiiMoteLib {

	/////////////////////////
	// General
	/////////////////////////
	double GiiMote::wm_calc_accel(float accel)
	{
		double val = (double)accel;
		// if (val < this->accel_dead_zone && val > -(this->accel_dead_zone))
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
	double GiiMote::wm_get_accel_x()
	{
		return ( wm_calc_accel(this->wmState->AccelState.X) );
	}
	double GiiMote::wm_get_accel_y()
	{
		return ( wm_calc_accel(this->wmState->AccelState.Y) );
	}
	double GiiMote::wm_get_accel_z()
	{
		return ( wm_calc_accel(this->wmState->AccelState.Z) );
	}
	// Raw Data
	double GiiMote::wm_get_accel_rawx()
	{
		return ( (double)this->wmState->AccelState.RawX );
	}
	double GiiMote::wm_get_accel_rawy()
	{
		return ( (double)this->wmState->AccelState.RawY );
	}
	double GiiMote::wm_get_accel_rawz()
	{
		return ( (double)this->wmState->AccelState.RawZ );
	}

	/////////////////////////
	// Nunchuck
	/////////////////////////
	// Normalized Data
	double GiiMote::wm_nunchuck_get_accel_x()
	{
		return ( wm_calc_accel(this->wmState->NunchukState.AccelState.X) );
	}
	double GiiMote::wm_nunchuck_get_accel_y()
	{
		return ( wm_calc_accel(this->wmState->NunchukState.AccelState.Y) );
	}
	double GiiMote::wm_nunchuck_get_accel_z()
	{
		return ( wm_calc_accel(this->wmState->NunchukState.AccelState.Z) );
	}
	// Raw Data
	double GiiMote::wm_nunchuck_get_accel_rawx()
	{
		return ( (double)this->wmState->NunchukState.AccelState.RawX );
	}
	double GiiMote::wm_nunchuck_get_accel_rawy()
	{
		return ( (double)this->wmState->NunchukState.AccelState.RawY );
	}
	double GiiMote::wm_nunchuck_get_accel_rawz()
	{
		return ( (double)this->wmState->NunchukState.AccelState.RawZ );
	}

} // namespace GiiMoteLib