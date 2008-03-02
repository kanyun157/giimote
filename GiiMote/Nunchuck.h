// Nunchuck.h - Contains functions that deal with the Nunchuck.
//				For functions having to do with the six-axis accelerometer
//				see "GMAccel.h". For joystick functions, see "Joystick.h".
//				For button checking, see "GMButtons.h".

namespace GiiMoteLib {
	
	// Calibration Reading Functions
	/// <summary>
	/// Gets the zero point of the accelerometer
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_x0()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.X0 );
	}
	/// <summary>
	/// Gets the gravity at rest of the accelerometer
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_xg()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.XG );
	}
	// Calibration Reading Functions
	/// <summary>
	/// Gets the zero point of the accelerometer
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_y0()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.Y0 );
	}
	/// <summary>
	/// Gets the gravity at rest of the accelerometer
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_yg()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.YG );
	}
	/// <summary>
	/// Gets the zero point of the accelerometer
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_z0()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.Z0 );
	}
	/// <summary>
	/// Gets the gravity at rest of the accelerometer
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_zg()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.ZG );
	}
	/// <summary>
	/// Gets the joystick X-axis calibration
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_maxx()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.MaxX );
	}
	/// <summary>
	/// Gets the joystick Y-axis calibration
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_maxy()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.MaxY );
	}
	/// <summary>
	/// Gets the joystick X-axis calibration
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_midx()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.MidX );
	}
	/// <summary>
	/// Gets the joystick Y-axis calibration
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_midy()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.MidY );
	}
	/// <summary>
	/// Gets the joystick X-axis calibration
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_minx()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.MinX );
	}
	/// <summary>
	/// Gets the joystick Y-axis calibration
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_miny()
	{
		return ( (double)this->wmState->NunchukState.CalibrationInfo.MinY );
	}
	// Calibration Writing Functions
	/// <summary>
	/// Sets the zero point of the accelerometer
	/// </summary>
	/// <param name="val">X0 Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_nunchuck_set_calibration_x0(double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			this->wmState->NunchukState.CalibrationInfo.AccelCalibration.X0 = calData;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>
	/// Sets the gravity at rest of the accelerometer
	/// </summary>
	/// <param name="val">XG Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_nunchuck_set_calibration_xg(double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			this->wmState->NunchukState.CalibrationInfo.AccelCalibration.XG = calData;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>
	/// Sets the zero point of the accelerometer
	/// </summary>
	/// <param name="val">Y0 Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_nunchuck_set_calibration_y0(double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			this->wmState->NunchukState.CalibrationInfo.AccelCalibration.Y0 = calData;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>
	/// Sets the gravity at rest of the accelerometer
	/// </summary>
	/// <param name="val">YG Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_nunchuck_set_calibration_yg(double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			this->wmState->NunchukState.CalibrationInfo.AccelCalibration.YG = calData;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>
	/// Sets the zero point of the accelerometer
	/// </summary>
	/// <param name="val">Z0 Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_nunchuck_set_calibration_z0(double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			this->wmState->NunchukState.CalibrationInfo.AccelCalibration.Z0 = calData;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>
	/// Sets the gravity at rest of the accelerometer
	/// </summary>
	/// <param name="val">ZG Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_nunchuck_set_calibration_zg(double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			this->wmState->NunchukState.CalibrationInfo.AccelCalibration.ZG = calData;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>
	/// Sets the joystick X-axis calibration 
	/// </summary>
	/// <param name="val">MaxX Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_nunchuck_set_calibration_maxx(double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			this->wmState->NunchukState.CalibrationInfo.MaxX = calData;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>
	/// Sets the joystick Y-axis calibration 
	/// </summary>
	/// <param name="val">MaxY Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_nunchuck_set_calibration_maxy(double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			this->wmState->NunchukState.CalibrationInfo.MaxY = calData;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>
	/// Sets the joystick X-axis calibration 
	/// </summary>
	/// <param name="val">MidX Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_nunchuck_set_calibration_midx(double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			this->wmState->NunchukState.CalibrationInfo.MidX = calData;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>
	/// Sets the joystick Y-axis calibration 
	/// </summary>
	/// <param name="val">MidY Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_nunchuck_set_calibration_midy(double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			this->wmState->NunchukState.CalibrationInfo.MidY = calData;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>
	/// Sets the joystick X-axis calibration 
	/// </summary>
	/// <param name="val">MinX Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_nunchuck_set_calibration_minx(double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			this->wmState->NunchukState.CalibrationInfo.MinX = calData;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>
	/// Sets the joystick Y-axis calibration 
	/// </summary>
	/// <param name="val">MinY Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_nunchuck_set_calibration_miny(double val)
	{
		unsigned char calData = (unsigned char)val;
		try
		{
			this->wmState->NunchukState.CalibrationInfo.MinY = calData;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}

} // namespace GiiMoteLib