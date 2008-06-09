// Nunchuck.h - Contains functions that deal with the Nunchuck.

namespace GiiMoteLib {

	// Normalized Data
	/// <summary>Normalized accelerometer data</summary>
	/// <remarks>Domain: [0,?)</remarks>
	/// <returns>Normalized acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_x()
	{
		return ( wm_calc_accel(this->wc[wmIndex]->WiimoteState->AccelState.Values.X, 3) );
	}

	/// <summary>Normalized accelerometer data</summary>
	/// <remarks>Domain: [0,?)</remarks>
	/// <returns>Normalized acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_y()
	{
		return ( wm_calc_accel(this->wc[wmIndex]->WiimoteState->NunchukState.AccelState.Values.Y, 4) );
	}

	/// <summary>Normalized accelerometer data</summary>
	/// <remarks>Domain: [0,?)</remarks>
	/// <returns>Normalized acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_z()
	{
		return ( wm_calc_accel(this->wc[wmIndex]->WiimoteState->NunchukState.AccelState.Values.Z, 5) );
	}

	// Raw Data
	/// <summary>Raw accelerometer data</summary>
	/// <remarks>Domain: [0,255]</remarks>
	/// <returns>Raw acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_rawx()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->NunchukState.AccelState.RawValues.X );
	}

	/// <summary>Raw accelerometer data</summary>
	/// <remarks>Domain: [0,255]</remarks>
	/// <returns>Raw acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_rawy()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->NunchukState.AccelState.RawValues.Y );
	}

	/// <summary>Raw accelerometer data</summary>
	/// <remarks>Domain: [0,255]</remarks>
	/// <returns>Raw acceleration</returns>
	double GiiMote::wm_nunchuck_get_accel_rawz()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->NunchukState.AccelState.RawValues.Z );
	}

	/// <summary>Sets the dead-zone value</summary>
	/// <remarks>Domain: [0,Infinity]</remarks>
	/// <param name="val">The dead-zone value</param>
	/// <returns>1</returns>
	double GiiMote::wm_nunchuck_set_accel_dead_zone_x(double val)
	{
		accel_dead_zone[wmIndex, 3] = in_domain(val, 0, -1);
		return ( 1 );
	}

	/// <summary>Sets the dead-zone value</summary>
	/// <remarks>Domain: [0,Infinity]</remarks>
	/// <param name="val">The dead-zone value</param>
	/// <returns>1</returns>
	double GiiMote::wm_nunchuck_set_accel_dead_zone_y(double val)
	{
		accel_dead_zone[wmIndex, 4] = in_domain(val, 0, -1);
		return ( 1 );
	}

	/// <summary>Sets the dead-zone value</summary>
	/// <remarks>Domain: [0,Infinity]</remarks>
	/// <param name="val">The dead-zone value</param>
	/// <returns>1</returns>
	double GiiMote::wm_nunchuck_set_accel_dead_zone_z(double val)
	{
		accel_dead_zone[wmIndex, 5] = in_domain(val, 0, -1);
		return ( 1 );
	}

	/// <summary>Gets the dead-zone value</summary>
	/// <returns>X-axis dead zone</returns>
	double GiiMote::wm_nunchuck_get_accel_dead_zone_x()
	{
		return ( accel_dead_zone[wmIndex, 3] );
	}

	/// <summary>Gets the dead-zone value</summary>
	/// <returns>Y-axis dead zone</returns>
	double GiiMote::wm_nunchuck_get_accel_dead_zone_y()
	{
		return ( accel_dead_zone[wmIndex, 4] );
	}

	/// <summary>Gets the dead-zone value</summary>
	/// <returns>Z-axis dead zone</returns>
	double GiiMote::wm_nunchuck_get_accel_dead_zone_z()
	{
		return ( accel_dead_zone[wmIndex, 5] );
	}

	/// <summary>
	/// Checks the state of a button
	/// </summary>
	/// <param name="key_code">
	/// The button to check
	/// <list type="bullet">
	///     <listheader>
	///         <term>Key Code</term>
	///         <description>Button</description>
	///     </listheader>
	///     <item>
	///			<term>btnC</term>
	///         <description>C Button</description>
	///     </item>
	///     <item>
	///			<term>btnZ</term>
	///         <description>Z Button</description>
	///     </item>
	/// </list>
	/// </param>
	/// <returns>Button pressed</returns>
	double GiiMote::wm_nunchuck_check_button(double key_code)
	{
		bool is_pressed = 0;
		switch ((int)key_code)
		{
		case btnC:
			is_pressed = this->wc[wmIndex]->WiimoteState->NunchukState.C;
			break;
		case btnZ:
			is_pressed = this->wc[wmIndex]->WiimoteState->NunchukState.Z;
			break;
		default:
			is_pressed = false;
			break;
		}
		
		return ((double)is_pressed);
	}

	// Normalized Functions
	/// <summary>Normalized joystick position</summary>
	/// <remarks>Domain: [-0.5,0.5]</remarks>
	/// <returns>The normalized X-position of the joystick</returns>
	double GiiMote::wm_nunchuck_xpos()
	{
		double xx;
		try
		{
			xx = (double)this->wc[wmIndex]->WiimoteState->NunchukState.Joystick.X;
		}
		catch(...)
		{
			return ( -1 );
		}
		if ( System::Math::Abs(xx) < (this->joystick_dead_zone[wmIndex]) )
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
			yy = (double)this->wc[wmIndex]->WiimoteState->NunchukState.Joystick.Y;
		}
		catch(...)
		{
			return ( -1 );
		}
		if ( System::Math::Abs(yy) < (this->joystick_dead_zone[wmIndex]) )
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
			rawX = (double)this->wc[wmIndex]->WiimoteState->NunchukState.RawJoystick.X;
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
			rawY = (double)this->wc[wmIndex]->WiimoteState->NunchukState.RawJoystick.Y;
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( rawY );
	}

	// Calibration Reading Functions
	/// <summary>
	/// Gets the zero point of the accelerometer
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_x0()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.AccelCalibration.X0 );
	}
	/// <summary>
	/// Gets the gravity at rest of the accelerometer
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_xg()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.AccelCalibration.XG );
	}
	// Calibration Reading Functions
	/// <summary>
	/// Gets the zero point of the accelerometer
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_y0()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.AccelCalibration.Y0 );
	}
	/// <summary>
	/// Gets the gravity at rest of the accelerometer
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_yg()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.AccelCalibration.YG );
	}
	/// <summary>
	/// Gets the zero point of the accelerometer
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_z0()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.AccelCalibration.Z0 );
	}
	/// <summary>
	/// Gets the gravity at rest of the accelerometer
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_zg()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.AccelCalibration.ZG );
	}
	/// <summary>
	/// Gets the joystick X-axis calibration
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_maxx()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.MaxX );
	}
	/// <summary>
	/// Gets the joystick Y-axis calibration
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_maxy()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.MaxY );
	}
	/// <summary>
	/// Gets the joystick X-axis calibration
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_midx()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.MidX );
	}
	/// <summary>
	/// Gets the joystick Y-axis calibration
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_midy()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.MidY );
	}
	/// <summary>
	/// Gets the joystick X-axis calibration
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_minx()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.MinX );
	}
	/// <summary>
	/// Gets the joystick Y-axis calibration
	/// </summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_nunchuck_get_calibration_miny()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.MinY );
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
			this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.AccelCalibration.X0 = calData;
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
			this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.AccelCalibration.XG = calData;
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
			this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.AccelCalibration.Y0 = calData;
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
			this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.AccelCalibration.YG = calData;
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
			this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.AccelCalibration.Z0 = calData;
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
			this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.AccelCalibration.ZG = calData;
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
			this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.MaxX = calData;
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
			this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.MaxY = calData;
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
			this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.MidX = calData;
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
			this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.MidY = calData;
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
			this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.MinX = calData;
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
			this->wc[wmIndex]->WiimoteState->NunchukState.CalibrationInfo.MinY = calData;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}

} // namespace GiiMoteLib