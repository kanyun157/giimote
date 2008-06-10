// Wiimote.h - Contains functions and constants relating to the Wii Remote in general.

namespace GiiMoteLib {

	/////////////////////////
	// Connection Functions
	/////////////////////////

	/// <summary>Finds all paired Wii Remotes</summary>
	/// <returns>Number of Wii Remotes found</returns>
	double GiiMote::wm_find_all()
	{
		this->wc->FindAllWiimotes();

		cli::array<PointF, 2>^ temp_ir_last_pos     = ir_last_pos;
		cli::array<Point, 2>^ temp_ir_last_raw_pos  = ir_last_raw_pos;
		cli::array<double, 2>^ temp_accel_dead_zone = accel_dead_zone;

		delete ir_last_pos;
		delete ir_last_raw_pos;
		delete accel_dead_zone;

		ir_last_pos     = gcnew cli::array<PointF, 2>(this->wc->Count, 4);
		ir_last_raw_pos = gcnew cli::array<Point, 2>(this->wc->Count, 4);
		accel_dead_zone = gcnew cli::array<double, 2>(this->wc->Count, 6);
		
		cli::array<PointF>::ConstrainedCopy(temp_ir_last_pos, 0, ir_last_pos, 0, temp_ir_last_pos->Length);
		cli::array<Point>::ConstrainedCopy(temp_ir_last_raw_pos, 0, ir_last_raw_pos, 0, temp_ir_last_raw_pos->Length);
		cli::array<double>::ConstrainedCopy(temp_accel_dead_zone, 0, accel_dead_zone, 0, temp_accel_dead_zone->Length);

		cli::array<PointF>::Resize(this->ir_last_mid_pos, wc->Count);
		cli::array<Point>::Resize(this->ir_last_rawmid_pos, wc->Count);
		cli::array<Point>::Resize(this->ir_screen_pos, wc->Count);

		cli::array<int>::Resize(this->report_type, wc->Count);
		cli::array<bool>::Resize(this->continuous, wc->Count);
		cli::array<IRSensitivity>::Resize(this->ir_sensitivity, wc->Count);
		cli::array<double>::Resize(this->trigger_dead_zone, wc->Count);
		cli::array<double>::Resize(this->joystick_dead_zone, wc->Count);

		// Default the report type to rt_auto
		// with continuous reporting and level 3 IR sensitivity.
		int tIndex = wmIndex;
		for(int i = 0; i < wc->Count; i++)
		{
			wmIndex = i;
			if (!wm_connected())
			{
				this->report_type[i] = rtAuto;
				this->continuous[i] = 1;
				this->ir_sensitivity[i] = IRSensitivity::WiiLevel3;
				this->joystick_dead_zone[i] = this->trigger_dead_zone[i] = 0;
				// Set the current X and Y position on the display to 0
				this->ir_screen_pos[i].X = 0;
				this->ir_screen_pos[i].Y = 0;
			}
		}
		wmIndex = tIndex;

		if (wmIndex >= this->wc->Count)
		{
			int tIndex = (int)wm_get_index(wmGUID->ToString());
			if (tIndex != -1)
			{
				wmIndex = tIndex;
			}
			else
			{
				wmIndex = 0;
				wmGUID  = this->wc[wmIndex]->ID;
			}
		}
		return ( (double)this->wc->Count );
	}

	/// <summary>Sets the current Wii Remote to use by index or numerical GUID</summary>
	/// <returns>Success</returns>
	double GiiMote::wm_set_wm(double wm)
	{
		if (this->wc->Count > 0)
		{
			// Error traps
			if (wm < 0)
			{
				return ( 0 );
			}

			if (wm < this->wc->Count)
			{
				wmIndex = (int)wm;
				wmGUID  = this->wc[wmIndex]->ID;
				return ( 1 );
			}
			else
			{
				int i = (int)wm_get_index(wm);
				if (i != -1)
				{
					wmIndex = i;
					wmGUID  = this->wc[wmIndex]->ID;
					return ( 1 );
				}
			}
		}

		return ( 0 );
	}

	/// <summary>Sets the current Wii Remote to use by GUID</summary>
	/// <returns>Success</returns>
	double GiiMote::wm_set_wm(System::String^ guid)
	{
		int i = (int)wm_get_index(guid);
		if (this->wc->Count > 0 && i != -1)
		{
			wmIndex = i;
			wmGUID  = this->wc[wmIndex]->ID;
			return ( 1 );
		}

		return ( 0 );
	}

	/// <summary>If the current Wii Remote is connected</summary>
	/// <returns>Wii Remote connected</returns>
	double GiiMote::wm_connected()
	{
		try
		{
			this->wc[wmIndex]->ReadData(0x0016,1);
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
				this->wc[wmIndex]->WiimoteChanged += (gcnew System::EventHandler<WiimoteChangedEventArgs^>(this,&GiiMote::wm_OnWiimoteChanged));
				this->wc[wmIndex]->WiimoteExtensionChanged += (gcnew System::EventHandler<WiimoteExtensionChangedEventArgs^>(this,&GiiMote::wm_OnWiimoteExtensionChanged));
				this->wc[wmIndex]->Connect();
				wm_set_report_type(this->report_type[wmIndex], this->continuous[wmIndex]);
			}
			catch( ... )
			{
				return ( 0 );
			}
			try
			{
				this->wc[wmIndex]->SetLEDs(false, false, false, false);
			}
			catch(...)
			{
				return ( -2 );
			}
		}
		else
		{
			return ( -1 );
		}

		return (1);
	}

	/// <summary>Connects all paired Wii Remotes</summary>
	/// <returns>Number of Wii Remotes connected</returns>
	double GiiMote::wm_connect_all()
	{
		int tIndex = wmIndex;
		int count  = 0;
		for(int i = 0; i < this->wc->Count; i++)
		{
			wmIndex = i;
			if (wm_connect() == 1)
			{
				count += 1;
			}
		}
		wmIndex = tIndex;

		return ( count );
	}

	/// <summary>Checks to see if any Wii Remotes exist</summary>
	/// <remarks>Same as checking if wm_find_all is greater than 0</remarks>
	/// <returns>Wii Remote detected</returns>
	double GiiMote::wm_exists()
	{
		return (double(wm_find_all() > 0));
	}

	/// <summary>Disconnect from the Wii Remote</summary>
	/// <returns>Wii Remote connected</returns>
	double GiiMote::wm_disconnect()
	{
		if (wm_connected())
		{
			try
			{
				delete (this->wc[wmIndex]->WiimoteChanged);
				delete (this->wc[wmIndex]->WiimoteExtensionChanged);
				this->wc[wmIndex]->Disconnect();
			}
			catch (...)
			{
				return ( 0 );
			}
		}
		return ( 1 );
	}

	/// <summary>Disconnects all paired Wii Remotes</summary>
	/// <returns>Number of Wii Remotes disconnected</returns>
	double GiiMote::wm_disconnect_all()
	{
		int tIndex = wmIndex;
		int count  = 0;
		for(int i = 0; i < this->wc->Count; i++)
		{
			wmIndex = i;
			if (wm_disconnect() == 1)
			{
				count += 1;
			}
		}
		wmIndex = tIndex;

		return ( count );
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
					this->wc[wmIndex]->SetReportType(WiimoteLib::InputReport::Buttons, this->ir_sensitivity[wmIndex], bool(continuous));
					break;
				case rtButtonsAccel:
					this->wc[wmIndex]->SetReportType(WiimoteLib::InputReport::ButtonsAccel, this->ir_sensitivity[wmIndex], bool(continuous));
					break;
				case rtButtonsExtension:
					this->wc[wmIndex]->SetReportType(WiimoteLib::InputReport::ButtonsExtension, this->ir_sensitivity[wmIndex], bool(continuous));
					break;
				case rtExtensionAccel:
					this->wc[wmIndex]->SetReportType(WiimoteLib::InputReport::ExtensionAccel, this->ir_sensitivity[wmIndex], bool(continuous));
					break;
				case rtIRAccel:
					this->wc[wmIndex]->SetReportType(WiimoteLib::InputReport::IRAccel, this->ir_sensitivity[wmIndex], bool(continuous));
					break;
				case rtIRExtensionAccel:
					this->wc[wmIndex]->SetReportType(WiimoteLib::InputReport::IRExtensionAccel, this->ir_sensitivity[wmIndex], bool(continuous));
					break;
				case rtReadData:
					this->wc[wmIndex]->SetReportType(WiimoteLib::InputReport::ReadData, this->ir_sensitivity[wmIndex], bool(continuous));
					break;
				case rtStatus:
					this->wc[wmIndex]->SetReportType(WiimoteLib::InputReport::Status, this->ir_sensitivity[wmIndex], bool(continuous));
					break;
				case rtAuto:
					if (this->wc[wmIndex]->WiimoteState->Extension)
					{
						this->wc[wmIndex]->SetReportType(WiimoteLib::InputReport::IRExtensionAccel, this->ir_sensitivity[wmIndex], bool(continuous));
					}
					else
					{
						this->wc[wmIndex]->SetReportType(WiimoteLib::InputReport::IRAccel, this->ir_sensitivity[wmIndex], bool(continuous));
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

		this->report_type[wmIndex] = int(report_type);
		this->continuous[wmIndex]  = bool(continuous);

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
		return ( double(this->report_type[wmIndex]) );
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
		return ( double(this->continuous[wmIndex]) );
	}

	/// <summary>Gets the GUID of the given Wii Remote</summary>
	/// <returns>GUID as String</returns>
	String^ GiiMote::wm_get_guid()
	{
		return ( this->wc[wmIndex]->ID.ToString() );
	}
	/// <summary>Gets the GUID of the given Wii Remote</summary>
	/// <returns>GUID as Double</returns>
	double GiiMote::wm_get_id()
	{
		System::String^ guid = this->wc[wmIndex]->ID.ToString();
		guid->Replace("{","");
		guid->Replace("}","");
		guid->Replace("-","");
		double sum = 0;
		int temp;

		for (int i = 0; i < guid->Length; i++)
		{
			temp = (guid->Substring(1, 1)->ToCharArray()[0] & 0xF0U) >> 4;
			sum = sum*16 + temp;
			temp = (guid->Substring(1, 1)->ToCharArray()[0] & 0x0FU);
			sum = sum*16 + temp;
		}
		return ( sum );
	}

	/// <summary>Gets the index of the given Wii Remote</summary>
	/// <returns>Index</returns>
	double GiiMote::wm_get_index(System::String^ guid)
	{
		System::String^ GUID = guid;
		GUID->Replace("-","");
		GUID->Replace("{","");
		GUID->Replace("}","");
		for (int i = 0; i < wc->Count; i++)
		{
			System::String^ temp = wm_get_guid();
			temp->Replace("-","");
			temp->Replace("{","");
			temp->Replace("}","");
			if (guid == temp)
			{
				return ( i );
			}
		}
		return ( -1 );
	}

	/// <summary>Gets the index of the given Wii Remote</summary>
	/// <returns>Index</returns>
	double GiiMote::wm_get_index(double guid)
	{
		for (int i = 0; i < wc->Count; i++)
		{
			if (guid == wm_get_id())
			{
				return ( i );
			}
		}
		return ( -1 );
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
				led = this->wc[wmIndex]->WiimoteState->LEDState.LED1;
				break;
			case 2:
				led = this->wc[wmIndex]->WiimoteState->LEDState.LED2;
				break;
			case 3:
				led = this->wc[wmIndex]->WiimoteState->LEDState.LED3;
				break;
			case 4:
				led = this->wc[wmIndex]->WiimoteState->LEDState.LED4;
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
			this->wc[wmIndex]->SetLEDs(bLed1,bLed2,bLed3,bLed4);
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
			this->wc[wmIndex]->SetLEDs( LEDs );
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
			battery_state = (double)this->wc[wmIndex]->WiimoteState->Battery;
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
			this->wc[wmIndex]->GetStatus();
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
			switch(this->wc[wmIndex]->WiimoteState->ExtensionType)
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
			case (WiimoteLib::ExtensionType::BalanceBoard):
				extension_type = extBalanceBoard;
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
			this->wc[wmIndex]->SetRumble( rumbling > 0.5 );
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
			rumbling = (double)this->wc[wmIndex]->WiimoteState->Rumble;
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
		return ( (double)this->wc[wmIndex]->WiimoteState->AccelCalibrationInfo.X0 );
	}
	/// <summary>Gets the gravity at rest of the accelerometer</summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_get_calibration_xg()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->AccelCalibrationInfo.XG );
	}
	/// <summary>Gets the zero point of the accelerometer</summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_get_calibration_y0()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->AccelCalibrationInfo.Y0 );
	}
	/// <summary>Gets the gravity at rest of the accelerometer</summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_get_calibration_yg()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->AccelCalibrationInfo.YG );
	}
	/// <summary>Gets the zero point of the accelerometer</summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_get_calibration_z0()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->AccelCalibrationInfo.Z0 );
	}
	/// <summary>Gets the gravity at rest of the accelerometer</summary>
	/// <returns>Normalized calibration data</returns>
	double GiiMote::wm_get_calibration_zg()
	{
		return ( (double)this->wc[wmIndex]->WiimoteState->AccelCalibrationInfo.ZG );
	}
	// Set
	/// <summary>Sets the zero point of the accelerometer</summary>
	/// <param name="val">X0 Value as byte</param>
	/// <returns>Success</returns>
	double GiiMote::wm_set_calibration_x0(double val)
	{
		try
		{
			this->wc[wmIndex]->WiimoteState->AccelCalibrationInfo.X0 = (unsigned char)val;
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
			this->wc[wmIndex]->WiimoteState->AccelCalibrationInfo.XG = (unsigned char)val;
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
			this->wc[wmIndex]->WiimoteState->AccelCalibrationInfo.Y0 = (unsigned char)val;
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
			this->wc[wmIndex]->WiimoteState->AccelCalibrationInfo.YG = (unsigned char)val;
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
			this->wc[wmIndex]->WiimoteState->AccelCalibrationInfo.Z0 = (unsigned char)val;
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
			this->wc[wmIndex]->WiimoteState->AccelCalibrationInfo.ZG = (unsigned char)val;
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
			value = double( (this->wc[wmIndex]->ReadData((int)address,1))[0] );
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
			this->wc[wmIndex]->WriteData((int)address,(unsigned char)value);
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
}