// Nunchuck.h - Contains functions that deal with the Nunchuck.
//				For functions having to do with the six-axis accelerometer
//				see "GMAccel.h". For joystick functions, see "Joystick.h".
//				For button checking, see "GMButtons.h".

namespace GiiMoteLib {
	
	// Calibration Reading Functions
	double GiiMote::wm_nunchuck_get_calibration_x0()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.X0 );
	}
	double GiiMote::wm_nunchuck_get_calibration_xg()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.XG );
	}
	double GiiMote::wm_nunchuck_get_calibration_y0()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.Y0 );
	}
	double GiiMote::wm_nunchuck_get_calibration_yg()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.YG );
	}
	double GiiMote::wm_nunchuck_get_calibration_z0()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.Z0 );
	}
	double GiiMote::wm_nunchuck_get_calibration_zg()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.ZG );
	}
	double GiiMote::wm_nunchuck_get_calibration_maxx()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.MaxX );
	}
	double GiiMote::wm_nunchuck_get_calibration_maxy()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.MaxY );
	}
	double GiiMote::wm_nunchuck_get_calibration_midx()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.MidX );
	}
	double GiiMote::wm_nunchuck_get_calibration_midy()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.MidY );
	}
	double GiiMote::wm_nunchuck_get_calibration_minx()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.MinX );
	}
	double GiiMote::wm_nunchuck_get_calibration_miny()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.MinY );
	}

} // namespace GiiMoteLib