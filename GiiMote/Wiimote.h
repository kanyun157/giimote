// Wiimote.h - Contains functions and constants relating to the Wii Remote in general.

namespace GiiMoteLib {

	/////////////////////////
	// Connection Functions
	/////////////////////////

	/// <summary>If the Wii Remote is connected</summary>
	/// <returns>Wii Remote connected</returns>
	double GiiMote::wm_connected()
	{
		try
		{
			wm->GetStatus();
		}
		catch(...)
		{
			return ( 0 );
		}

		return ( 1 );
	}

	/// <summary>Connect to Wii Remote</summary>
	/// <returns>
	/// <list type="table">
	///     <listheader>
	///         <term>Return Code</term>
	///         <description>Description</description>
	///     </listheader>
	///     <item>
	///         <term>-1</term>
	///         <description>Wii Remote already connected</description>
	///     </item>
	///     <item>
	///         <term>0</term>
	///         <description>Wii Remote failed to connect or no Wii Remote Detected</description>
	///     </item>
	///     <item>
	///         <term>1</term>
	///         <description>Wii Remote connected Successly</description>
	///     </item>
	/// </list>
	/// </returns>
	double GiiMote::wm_connect()
	{
		if (!wm_connected())
		{
			try
			{
				this->wm->Connect();
			}
			catch( ... )
			{
				return ( 0 );
			}
			// this->connected = true;
			if (this->wm->WiimoteState->Extension)
			{
				this->wm->SetReportType(Wiimote::InputReport::IRExtensionAccel, true);
			}
			else
			{
				this->wm->SetReportType(Wiimote::InputReport::IRAccel, true);
			}
			this->wm->WiimoteChanged += (gcnew WiimoteChangedEventHandler(this,&GiiMote::wm_OnWiimoteChanged));
			this->wm->WiimoteExtensionChanged += (gcnew WiimoteExtensionChangedEventHandler(this,&GiiMote::wm_OnWiimoteExtensionChanged));
			this->wm->SetLEDs(false, false, false, false);
			// wm->GetStatus(); - This is covered in wm_connected().
		}
		else
		{
			return ( -1 );
		}

		return (wm_connected());
	}

	/// <summary>Checks to see if a Wii Remote exists</summary>
	/// <remarks>Same as seeing if <see>wm_connect()</see> fails</remarks>
	/// <returns>Wii Remote exists</returns>
	double GiiMote::wm_exists()
	{
		if (!wm_connected())
		{
			try
			{
				this->wm->Connect();
			}
			catch(...)
			{
				return ( 0 );
			}
			this->wm->Disconnect();
		}
		return ( 1 );
	}

	/// <summary>Manually set the bluetooth write method</summary>
	/// <remarks>Has no effect if called after connection</remarks>
	/// <param name="alt_write_method">Use alternate write method</param>
	/// <returns>Success</returns>
	double GiiMote::wm_set_write_method(double alt_write_method)
	{
		try
		{
			switch ((int)alt_write_method)
			{
			case 0:
				this->wm->AltWriteMethod = 0;
				break;
			case 1:
				this->wm->AltWriteMethod = 1;
				break;
			default:
				throw ( 0 );
				break;
			}
		}
		catch (...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>Disconnect from the Wii Remote</summary>
	/// <returns>Success</returns>
	double GiiMote::wm_disconnect(void)
	{
		if (wm_connected())
		{
			try
			{
				this->wm->Disconnect();
			}
			catch (...)
			{
				return (-1);
			}
			// this->connected = false;
		}
		return (!wm_connected());
	}
	/// <summary>Sets a dead zone</summary>
	/// <param name="num">The value for the dead-zone</param>
	/// <param name="type">
	/// The type of dead-zone:
	/// <list type="table">
	///     <listheader>
	///         <term>Code</term>
	///         <description>Dead Zone Type</description>
	///     </listheader>
	///     <item>
	///         <term>0</term>
	///         <description>Joystick dead zone</description>
	///     </item>
	///     <item>
	///         <term>1</term>
	///         <description>Trigger dead zone</description>
	///     </item>
	///     <item>
	///         <term>2</term>
	///         <description>Accelerometer dead zone</description>
	///     </item>
	/// </list>
	/// </param>
	/// <returns>Dead zone ammount</returns>
	double GiiMote::wm_set_dead_zone(double num, double type)
	{
		double dz = num;
		switch ((int)type)
		{
		case 0: // Joystick
			this->dead_zone = in_domain(dz,0,0.1);
			break;
		case 1: // Trigger
			this->trigger_dead_zone = in_domain(dz,0,1);
			break;
		case 2: // Accelerometer
			this->accel_dead_zone = in_domain(dz,0,-1);
			break;
		default:
			break;
		}

		return (dz);
	}

	/////////////////////////
	// LED Functions
	/////////////////////////
	/// <summary>Gets the state of an LED</summary>
	/// <param name="led_num">The LED to get the state of (1-4)</param>
	/// <returns>The state of the LED</returns>
	double GiiMote::wm_get_led(double led_num)
	{
		bool led = false;
		switch( (int)led_num )
		{
		case 1:
			led = this->wmState->LEDState.LED1;
			break;
		case 2:
			led = this->wmState->LEDState.LED2;
			break;
		case 3:
			led = this->wmState->LEDState.LED3;
			break;
		case 4:
			led = this->wmState->LEDState.LED4;
			break;
		default:
			led = false;
			break;
		}

		return ( (double)led );
	}
	/// <summary>Sets the state of the LEDs</summary>
	/// <param name="led1">The state of LED 1 (boolean)</param>
	/// <param name="led2">The state of LED 2 (boolean)</param>
	/// <param name="led3">The state of LED 3 (boolean)</param>
	/// <param name="led4">The state of LED 4 (boolean)</param>
	/// <returns>Success</returns>
	double GiiMote::wm_set_leds(double led1, double led2, double led3, double led4)
	{
		bool bLed1,bLed2,bLed3,bLed4;
		bLed1 = (led1 > 0);
		bLed2 = (led2 > 0);
		bLed3 = (led3 > 0);
		bLed4 = (led4 > 0);

		try
		{
			this->wm->SetLEDs(bLed1,bLed2,bLed3,bLed4);
		}
		catch (...)
		{
			return ( 0 );
		}

		return ( 1 );
	}

	/// <summary>Sets the LEDS on the Wii Remote</summary>
	/// <param name="val">The state the LEDs</param>
	/// <returns>Success</returns>
	double GiiMote::wm_set_leds_int(double val)
	{
		int LEDs = (int)val;
		try
		{
			this->wm->SetLEDs( LEDs );
		}
		catch (...)
		{
			return ( 0 );
		}
		return ( 1 );
	}

	/////////////////////////
	// Status Functions
	/////////////////////////

	/// <summary>Gets the current battery level</summary>
	/// <returns>The current battery level</returns>
	double GiiMote::wm_get_battery()
	{
		double battery_state;
		try
		{
			this->wm->GetStatus();
			battery_state = (double)this->wmState->Battery;
		}
		catch(...)
		{
			return ( - 1 );
		}
		return ( battery_state );
	}
	/// <summary>Updates the Wii Remote status</summary>
	/// <returns>Success</returns>
	double GiiMote::wm_get_status()
	{
		try
		{
			this->wm->GetStatus();
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>Checks the current extension</summary>
	/// <returns>
	/// Current extension:
	/// <list type="table">
	///     <listheader>
	///         <term>Code</term>
	///         <description>Extension</description>
	///     </listheader>
	///     <item>
	///         <term>expClassic</term>
	///         <description>Classic Controller</description>
	///     </item>
	///     <item>
	///         <term>expNunchuck</term>
	///         <description>Nunchuck</description>
	///     </item>
	///     <item>
	///         <term>expNone</term>
	///         <description>None</description>
	///     </item>
	///     <item>
	///         <term>expUnknown</term>
	///         <description>Unknown Extension</description>
	///     </item>
	///     <item>
	///         <term>-2</term>
	///         <description>Error</description>
	///     </item>
	/// </list>
	/// </returns>
	double GiiMote::wm_check_extension()
	{
		double extension_type;
		try
		{
			switch(this->wmState->ExtensionType)
			{
			case WiimoteLib::ExtensionType::ClassicController:
				extension_type = expClassic;
				break;
			case WiimoteLib::ExtensionType::Nunchuk:
				extension_type = expNunchuck;
				break;
			case WiimoteLib::ExtensionType::None:
				extension_type = expNone;
				break;
			default:
				extension_type = expUnknown;
				break;
			}
		}
		catch(...)
		{
			return ( -2 );
		}
	
		return (extension_type);
	}

	/// <summary>Sets the vibration motor's status</summary>
	/// <param name="rumbling">Rumble status (1 or 0)</param>
	/// <returns>Rumbling (1 or 0) or error (-1)</returns>
	double GiiMote::wm_set_rumble(double rumbling)
	{
		try
		{
			switch ((int)rumbling)
			{
			case 0:
				this->wm->SetRumble(false);
				break;
			case 1:
				this->wm->SetRumble(true);
				break;
			default:
				throw (-1);
				break;
			}
		}
		catch(...)
		{
			return (-1);
		}
		return (wm_get_rumble());
	}
	/// <summary>Vibration motor status</summary>
	/// <returns>Rumbling (1 or 0)</returns>
	double GiiMote::wm_get_rumble()
	{
		double rumbling;
		try
		{
			rumbling = (double)this->wmState->Rumble;
		}
		catch (...)
		{
			rumbling = -1;
		}

		return ( rumbling );
	}

	/////////////////////////
	// Calibration Functions
	/////////////////////////
	// Get
	/// <summary>Gets the zero point of the accelerometer</summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_get_calibration_x0()
	{
		return ( (double)this->wmState->AccelCalibrationInfo.X0 );
	}
	/// <summary>Gets the gravity at rest of the accelerometer</summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_get_calibration_xg()
	{
		return ( (double)this->wmState->AccelCalibrationInfo.XG );
	}
	/// <summary>Gets the zero point of the accelerometer</summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_get_calibration_y0()
	{
		return ( (double)this->wmState->AccelCalibrationInfo.Y0 );
	}
	/// <summary>Gets the gravity at rest of the accelerometer</summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_get_calibration_yg()
	{
		return ( (double)this->wmState->AccelCalibrationInfo.YG );
	}
	/// <summary>Gets the zero point of the accelerometer</summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_get_calibration_z0()
	{
		return ( (double)this->wmState->AccelCalibrationInfo.Z0 );
	}
	/// <summary>Gets the gravity at rest of the accelerometer</summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_get_calibration_zg()
	{
		return ( (double)this->wmState->AccelCalibrationInfo.ZG );
	}
	// Set
	/// <summary>Sets the zero point of the accelerometer</summary>
	/// <param name="val">X0 Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_set_calibration_x0(double val)
	{
		try
		{
			this->wmState->AccelCalibrationInfo.X0 = (unsigned char)val;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>Sets the gravity at rest of the accelerometer</summary>
	/// <param name="val">XG Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_set_calibration_xg(double val)
	{
		try
		{
			this->wmState->AccelCalibrationInfo.XG = (unsigned char)val;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>Sets the zero point of the accelerometer</summary>
	/// <param name="val">Y0 Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_set_calibration_y0(double val)
	{
		try
		{
			this->wmState->AccelCalibrationInfo.Y0 = (unsigned char)val;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>Sets the gravity at rest of the accelerometer</summary>
	/// <param name="val">YG Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_set_calibration_yg(double val)
	{
		try
		{
			this->wmState->AccelCalibrationInfo.YG = (unsigned char)val;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>Sets the zero point of the accelerometer</summary>
	/// <param name="val">Z0 Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_set_calibration_z0(double val)
	{
		try
		{
			this->wmState->AccelCalibrationInfo.Z0 = (unsigned char)val;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
	/// <summary>Sets the gravity at rest of the accelerometer</summary>
	/// <param name="val">ZG Value</param>
	/// <returns>Success</returns>
	double GiiMote::wm_set_calibration_zg(double val)
	{
		try
		{
			this->wmState->AccelCalibrationInfo.ZG = (unsigned char)val;
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}


	/////////////////////////
	// Data Functions
	/////////////////////////

	/// <summary>Reads a byte from a register or memory</summary>
	/// <param name="address">The address to read from</param>
	/// <returns>Byte at address</returns>
	double GiiMote::wm_bin_read_byte(double address)
	{
		double value;
		try
		{
			value = double( (this->wm->ReadData((int)address,1))[0] );
		}
		catch(...)
		{
			value = -1;
		}
		return ( value );
	}
	/// <summary>Writes a byte to a register or memory</summary>
	/// <param name="address">The address to write to</param>
	/// <returns>Success</returns>
	double GiiMote::wm_bin_write_byte(double address, double value)
	{
		try
		{
			this->wm->WriteData((int)address,(unsigned char)value);
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
}