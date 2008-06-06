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
			/// TODO: Fix this to read from a valid address.
#pragma message("Fix this to read from a valid address.")
			this->wm->ReadData(0x0008,1);
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
	///         <term>-2</term>
	///         <description>Wii Remote connected but an error occured</description>
	///     </item>
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
	///         <description>Wii Remote connected successfully</description>
	///     </item>
	/// </list>
	/// </returns>
	double GiiMote::wm_connect()
	{
		if (!wm_connected())
		{
			try
			{
				this->wm->WiimoteChanged += (gcnew System::EventHandler<WiimoteChangedEventArgs^>(this,&GiiMote::wm_OnWiimoteChanged));
				this->wm->WiimoteExtensionChanged += (gcnew System::EventHandler<WiimoteExtensionChangedEventArgs^>(this,&GiiMote::wm_OnWiimoteExtensionChanged));
				this->wm->Connect();
				wm_set_report_type(this->report_type, this->continuous);
			}
			catch( ... )
			{
				return ( 0 );
			}
			try
			{
				this->wm->SetLEDs(false, false, false, false);
			}
			catch(...)
			{
				return ( -2 );
			}
			// wm->GetStatus(); - This is covered in wm_connected().
		}
		else
		{
			return ( -1 );
		}

		return (1);
	}

	/// <summary>Checks to see if a Wii Remote exists</summary>
	/// <remarks>Same as seeing if wm_connect() fails</remarks>
	/// <returns>
	/// <list type="table">
	///     <listheader>
	///         <term>Return Code</term>
	///         <description>Description</description>
	///     </listheader>
	///     <item>
	///         <term>-1</term>
	///         <description>Wii Remote detected but an error occured</description>
	///     </item>
	///     <item>
	///         <term>0</term>
	///         <description>No Wii Remote detected</description>
	///     </item>
	///     <item>
	///         <term>1</term>
	///         <description>Wii Remote detected</description>
	///     </item>
	/// </list>
	/// </returns>
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
			try
			{
				this->wm->Disconnect();
			}
			catch(...)
			{
				return ( -1 );
			}
		}
		return ( 1 );
	}

	/// <summary>Disconnect from the Wii Remote</summary>
	/// <returns>Success</returns>
	double GiiMote::wm_disconnect()
	{
		if (wm_connected())
		{
			try
			{
				delete (this->wm->WiimoteChanged);
				delete (this->wm->WiimoteExtensionChanged);
				this->wm->Disconnect();
			}
			catch (...)
			{
				return ( 0 );
			}
		}
		return ( 1 );
	}

	/// <summary>Changes the report type of the Wii Remote</summary>
	/// <param name="report_type">
	/// <list type="bullet">
	///     <listheader>
	///         <term>Value</term>
	///         <description>Report Type</description>
	///     </listheader>
	///     <item>
	///			<term>0</term>
	///         <description>rtAuto</description>
	///     </item>
	///     <item>
	///			<term>1</term>
	///         <description>rtButtons</description>
	///     </item>
	///     <item>
	///			<term>2</term>
	///         <description>rtButtonsAccel</description>
	///     </item>
	///     <item>
	///			<term>3</term>
	///         <description>rtButtonsExtension</description>
	///     </item>
	///     <item>
	///			<term>4</term>
	///         <description>rtExtensionAccel</description>
	///     </item>
	///     <item>
	///			<term>5</term>
	///         <description>rtIRAccel</description>
	///     </item>
	///     <item>
	///			<term>6</term>
	///         <description>rtIRExtensionAccel</description>
	///     </item>
	///     <item>
	///			<term>7</term>
	///         <description>rtReadData</description>
	///     </item>
	///     <item>
	///			<term>8</term>
	///         <description>rtStatus</description>
	///     </item>
	/// </list>	
	/// </param>
	/// <param name="continuous">Report continuously</param>
	/// <returns>Success</returns>
	double GiiMote::wm_set_report_type(double report_type, double continuous)
	{
		#pragma warning( disable : 4800 ) // Suppress warning 4800 (Conversion from double to bool)
		if (wm_connected())
		{
			try
			{
				switch ( int(report_type) )
				{
				case rtButtons:
					this->wm->SetReportType(WiimoteLib::InputReport::Buttons, this->ir_sensitivity, bool(continuous));
					break;
				case rtButtonsAccel:
					this->wm->SetReportType(WiimoteLib::InputReport::ButtonsAccel, this->ir_sensitivity, bool(continuous));
					break;
				case rtButtonsExtension:
					this->wm->SetReportType(WiimoteLib::InputReport::ButtonsExtension, this->ir_sensitivity, bool(continuous));
					break;
				case rtExtensionAccel:
					this->wm->SetReportType(WiimoteLib::InputReport::ExtensionAccel, this->ir_sensitivity, bool(continuous));
					break;
				case rtIRAccel:
					this->wm->SetReportType(WiimoteLib::InputReport::IRAccel, this->ir_sensitivity, bool(continuous));
					break;
				case rtIRExtensionAccel:
					this->wm->SetReportType(WiimoteLib::InputReport::IRExtensionAccel, this->ir_sensitivity, bool(continuous));
					break;
				case rtReadData:
					this->wm->SetReportType(WiimoteLib::InputReport::ReadData, this->ir_sensitivity, bool(continuous));
					break;
				case rtStatus:
					this->wm->SetReportType(WiimoteLib::InputReport::Status, this->ir_sensitivity, bool(continuous));
					break;
				case rtAuto:
					if (this->wm->WiimoteState->Extension)
					{
						this->wm->SetReportType(WiimoteLib::InputReport::IRExtensionAccel, this->ir_sensitivity, bool(continuous));
					}
					else
					{
						this->wm->SetReportType(WiimoteLib::InputReport::IRAccel, this->ir_sensitivity, bool(continuous));
					}
					break;
				default:
					return ( 0 );
					break;
				}
			}
			catch(...)
			{
				return ( 0 );
			}
		}
		else
		{
			this->report_type = int(report_type);
			this->continuous  = bool(continuous);
		}

		return ( 1 );
		#pragma warning( default : 4800 ) // Re-enable warning 4800
	}

	/// <summary>Gets the current report type of the Wii Remote</summary>
	/// <returns>
	/// <list type="bullet">
	///     <listheader>
	///         <term>Value</term>
	///         <description>Report Type</description>
	///     </listheader>
	///     <item>
	///			<term>0</term>
	///         <description>rtAuto</description>
	///     </item>
	///     <item>
	///			<term>1</term>
	///         <description>rtButtons</description>
	///     </item>
	///     <item>
	///			<term>2</term>
	///         <description>rtButtonsAccel</description>
	///     </item>
	///     <item>
	///			<term>3</term>
	///         <description>rtButtonsExtension</description>
	///     </item>
	///     <item>
	///			<term>4</term>
	///         <description>rtExtensionAccel</description>
	///     </item>
	///     <item>
	///			<term>5</term>
	///         <description>rtIRAccel</description>
	///     </item>
	///     <item>
	///			<term>6</term>
	///         <description>rtIRExtensionAccel</description>
	///     </item>
	///     <item>
	///			<term>7</term>
	///         <description>rtReadData</description>
	///     </item>
	///     <item>
	///			<term>8</term>
	///         <description>rtStatus</description>
	///     </item>
	/// </list>
	/// </returns>
	double GiiMote::wm_get_report_type()
	{
		return ( double(this->report_type) );
	}

	/// <summary>Gets the current report interval of the Wii Remote</summary>
	/// <returns>
	/// <list type="bullet">
	///     <listheader>
	///         <term>Value</term>
	///         <description>Report Type</description>
	///     </listheader>
	///     <item>
	///			<term>1</term>
	///         <description>Reporting continuously</description>
	///     </item>
	///     <item>
	///			<term>0</term>
	///         <description>Reporting on update</description>
	///     </item>
	/// </list>
	/// </returns>
	double GiiMote::wm_get_report_continuous()
	{
		return ( double(this->continuous) );
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
		try
		{
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
				throw( 0 );
				break;
			}
		}
		catch(...)
		{
			led = false;
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
		bLed1 = (led1 > 0.5);
		bLed2 = (led2 > 0.5);
		bLed3 = (led3 > 0.5);
		bLed4 = (led4 > 0.5);

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
	/// <returns>The current battery level between 0 and 200</returns>
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

	/// <summary>Updates the Wii Remote's status</summary>
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
	///         <term>1</term>
	///         <description>extClassic</description>
	///     </item>
	///     <item>
	///         <term>2</term>
	///         <description>extNunchuck</description>
	///     </item>
	///     <item>
	///         <term>3</term>
	///         <description>extGuitar</description>
	///     </item>
	///     <item>
	///         <term>0</term>
	///         <description>extNone</description>
	///     </item>
	///     <item>
	///         <term>-1</term>
	///         <description>extUnknown</description>
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
			case (WiimoteLib::ExtensionType::ClassicController):
				extension_type = extClassic;
				break;
			case (WiimoteLib::ExtensionType::Nunchuk):
				extension_type = extNunchuck;
				break;
			case (WiimoteLib::ExtensionType::Guitar):
				extension_type = extGuitar;
				break;
			case (WiimoteLib::ExtensionType::None):
				extension_type = extNone;
				break;
			default:
				extension_type = extUnknown;
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
	/// <param name="rumbling">Rumble status (true or false)</param>
	/// <returns>Success</returns>
	double GiiMote::wm_set_rumble(double rumbling)
	{
		try
		{
			this->wm->SetRumble( rumbling > 0.5 );
		}
		catch(...)
		{
			return (0);
		}
		return (1);
	}
	/// <summary>Vibration motor status</summary>
	/// <returns>Rumbling (1 or 0) or Error (-1)</returns>
	double GiiMote::wm_get_rumble()
	{
		double rumbling;
		try
		{
			rumbling = (double)this->wmState->Rumble;
		}
		catch (...)
		{
			return ( -1 );
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
	/// <param name="val">X0 Value as byte</param>
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
	/// <param name="val">XG Value as byte</param>
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
	/// <param name="val">Y0 Value as byte</param>
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
	/// <param name="val">YG Value as byte</param>
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
	/// <param name="val">Z0 Value as byte</param>
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
	/// <param name="val">ZG Value as byte</param>
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
	/// <returns>Byte at address or -1 on error</returns>
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