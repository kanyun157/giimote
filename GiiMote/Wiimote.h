// Wiimote.h - Contains functions and constants relating to the Wii Remote in general.
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
	// Connection Functions
	/////////////////////////

	/// <summary>Finds all paired Wii Remotes</summary>
	/// <returns>Number of Wii Remotes found or -1 on error</returns>
	double wm_find_all()
	{
		int return_code = -1;
		try
		{
			GiiMote::gm->wc->FindAllWiimotes();
		}
		catch(WiimoteLib::WiimoteNotFoundException^)
		{
			return_code = 0;
		}
		catch(...)
		{
			return_code = -1;
		}

		cli::array<PointF, 2>^ temp_ir_last_pos = GiiMote::gm->ir_last_pos;
		cli::array<Point, 2>^ temp_ir_last_raw_pos  = GiiMote::gm->ir_last_raw_pos;
		cli::array<double, 2>^ temp_accel_dead_zone = GiiMote::gm->accel_dead_zone;

		GiiMote::gm->ir_last_pos     = gcnew cli::array<PointF, 2>(GiiMote::gm->wc->Count, 4);
		GiiMote::gm->ir_last_raw_pos = gcnew cli::array<Point, 2>(GiiMote::gm->wc->Count, 4);
		GiiMote::gm->accel_dead_zone = gcnew cli::array<double, 2>(GiiMote::gm->wc->Count, 6);
		
		cli::array<PointF>::ConstrainedCopy(temp_ir_last_pos, 0, GiiMote::gm->ir_last_pos, 0, temp_ir_last_pos->Length);
		cli::array<Point>::ConstrainedCopy(temp_ir_last_raw_pos, 0, GiiMote::gm->ir_last_raw_pos, 0, temp_ir_last_raw_pos->Length);
		cli::array<double>::ConstrainedCopy(temp_accel_dead_zone, 0, GiiMote::gm->accel_dead_zone, 0, temp_accel_dead_zone->Length);

		delete temp_ir_last_pos;
		delete temp_ir_last_raw_pos;
		delete temp_accel_dead_zone;

		cli::array<PointF>::Resize(GiiMote::gm->ir_last_mid_pos, GiiMote::gm->wc->Count);
		cli::array<Point>::Resize(GiiMote::gm->ir_last_rawmid_pos, GiiMote::gm->wc->Count);
		cli::array<Point>::Resize(GiiMote::gm->ir_screen_pos, GiiMote::gm->wc->Count);

		cli::array<int>::Resize(GiiMote::gm->report_type, GiiMote::gm->wc->Count);
		cli::array<bool>::Resize(GiiMote::gm->continuous, GiiMote::gm->wc->Count);
		cli::array<IRSensitivity>::Resize(GiiMote::gm->ir_sensitivity, GiiMote::gm->wc->Count);
		cli::array<double>::Resize(GiiMote::gm->trigger_dead_zone, GiiMote::gm->wc->Count);
		cli::array<double>::Resize(GiiMote::gm->joystick_dead_zone, GiiMote::gm->wc->Count);

		if (GiiMote::gm->wc->Count > 0)
		{
			// Default the report type to rt_auto
			// with continuous reporting and level 3 IR sensitivity.
			int tIndex = GiiMote::gm->wmIndex;
			for(int i = 0; i < GiiMote::gm->wc->Count; i++)
			{
				GiiMote::gm->wmIndex = i;
				if (!wm_connected())
				{
					GiiMote::gm->report_type[i] = rtAuto;
					GiiMote::gm->continuous[i] = 1;
					GiiMote::gm->ir_sensitivity[i] = IRSensitivity::WiiLevel3;
					GiiMote::gm->joystick_dead_zone[i] = GiiMote::gm->trigger_dead_zone[i] = 0;
					// Set the current X and Y position on the display to 0
					GiiMote::gm->ir_screen_pos[i].X = 0;
					GiiMote::gm->ir_screen_pos[i].Y = 0;
				}
			}
			GiiMote::gm->wmIndex = tIndex;
			GiiMote::gm->wmGUID = GiiMote::gm->wc[GiiMote::gm->wmIndex]->ID;

			if (GiiMote::gm->wmIndex >= GiiMote::gm->wc->Count)
			{
				int tIndex = (int)wm_get_index_guid(toCharArray(GiiMote::gm->wmGUID->ToString()));
				if (tIndex != -1)
				{
					GiiMote::gm->wmIndex = tIndex;
				}
				else
				{
					GiiMote::gm->wmIndex = 0;
					GiiMote::gm->wmGUID  = GiiMote::gm->wc[GiiMote::gm->wmIndex]->ID;
				}
			}
			return_code = GiiMote::gm->wc->Count;
		}
		return ( (double)return_code );
	}

	/// <summary>Returns the number of currently discovered Wii Remotes</summary>
	/// <returns>Number of paired (not connected) Wii Remotes or -1 on error</returns>
	double wm_found()
	{
		int num;
		try
		{
			num = GiiMote::gm->wc->Count;
		}
		catch(...)
		{
			num = -1;
		}

		return ( (double)num );
	}

	/// <summary>Sets the current Wii Remote to use by index or numerical GUID</summary>
	/// <returns>Success</returns>
	double wm_set_using_val(double wm)
	{
		if (wm == -1)
		{
			double tIndex = GiiMote::gm->wmIndex;
			for(int i = 0; i < GiiMote::gm->wc->Count; i++)
			{
				wm_set_using_val(i);
				if (wm_exists())
				{
					return ( 1.0 );
				}
			}
			wm_set_using_val(tIndex);
		}

		if (GiiMote::gm->wc->Count > 0)
		{
			// Error traps
			if (wm < 0)
			{
				return ( 0 );
			}

			if (wm < GiiMote::gm->wc->Count)
			{
				GiiMote::gm->wmIndex = (int)wm;
				GiiMote::gm->wmGUID  = GiiMote::gm->wc[GiiMote::gm->wmIndex]->ID;
				return ( 1 );
			}
			else
			{
				int i = (int)wm_get_index_id(wm);
				if (i != -1)
				{
					GiiMote::gm->wmIndex = i;
					GiiMote::gm->wmGUID  = GiiMote::gm->wc[GiiMote::gm->wmIndex]->ID;
					return ( 1 );
				}
			}
		}

		return ( 0 );
	}

	/// <summary>Sets the current Wii Remote to use by GUID</summary>
	/// <returns>Success</returns>
	double wm_set_using_guid(char* guid)
	{
		int i = (int)wm_get_index_guid(guid);
		if (GiiMote::gm->wc->Count > 0 && i != -1)
		{
			GiiMote::gm->wmIndex = i;
			GiiMote::gm->wmGUID  = GiiMote::gm->wc[GiiMote::gm->wmIndex]->ID;
			return ( 1 );
		}

		return ( 0 );
	}

	/// <summary>If the current Wii Remote is connected</summary>
	/// <returns>Wii Remote connected</returns>
	double wm_connected()
	{
		try
		{
			GiiMote::gm->wc[GiiMote::gm->wmIndex]->ReadData(0x0016,1);
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
	double wm_connect()
	{
		if (!wm_connected())
		{
			try
			{
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteChanged += (gcnew System::EventHandler<WiimoteChangedEventArgs^>(GiiMote::gm, &GiiMoteLib::GiiMote::wm_OnWiimoteChanged));
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteExtensionChanged += (gcnew System::EventHandler<WiimoteExtensionChangedEventArgs^>(GiiMote::gm, &GiiMoteLib::GiiMote::wm_OnWiimoteExtensionChanged));
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->Connect();
				wm_set_report_type(GiiMote::gm->report_type[GiiMote::gm->wmIndex], GiiMote::gm->continuous[GiiMote::gm->wmIndex]);
			}
			catch( ... )
			{
				return ( 0 );
			}

			try
			{
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->SetLEDs(false, false, false, false);
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
	double wm_connect_all()
	{
		int tIndex = GiiMote::gm->wmIndex;
		int count  = 0;
		for(int i = 0; i < GiiMote::gm->wc->Count; i++)
		{
			GiiMote::gm->wmIndex = i;
			if (wm_connect() == 1)
			{
				count += 1;
			}
		}
		GiiMote::gm->wmIndex = tIndex;

		return ( count );
	}

	/// <summary>Checks to see if the current Wii Remote exists</summary>
	/// <returns>Weather or not the current Wii Remote exists</returns>
	double wm_exists()
	{
		double num = 1.0;
		if (!wm_connected())
		{
			try
			{
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->Connect();
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->Disconnect();
			}
			catch(...)
			{
				num = 0.0;
			}
		}
		return ( double(num) );
	}

	/// <summary>Checks to see how many Wii Remotes exist</summary>
	/// <returns>The number of existing Wii Remotes</returns>
	double wm_num_exists()
	{
		int num = 0;
		int current = GiiMote::gm->wmIndex;
		for(int i = 0; i < GiiMote::gm->wc->Count; i++)
		{
			GiiMote::gm->wmIndex = i;
			num += (int)wm_exists();
		}
		GiiMote::gm->wmIndex = current;
		return ( double(num) );
	}

	/// <summary>Disconnect from the Wii Remote</summary>
	/// <returns>Wii Remote connected</returns>
	double wm_disconnect()
	{
		if (wm_connected())
		{
			try
			{
				delete (GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteChanged);
				delete (GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteExtensionChanged);
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->Disconnect();
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
	double wm_disconnect_all()
	{
		int tIndex = GiiMote::gm->wmIndex;
		int count  = 0;
		for(int i = 0; i < GiiMote::gm->wc->Count; i++)
		{
			GiiMote::gm->wmIndex = i;
			if (wm_disconnect() == 1)
			{
				count += 1;
			}
		}
		GiiMote::gm->wmIndex = tIndex;

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
	/// <returns>Success or -1 on error</returns>
	double wm_set_report_type(double report_type, double continuous)
	{
		#pragma warning( disable : 4800 ) // Suppress warning 4800 (Conversion from double to bool)
		if (wm_connected())
		{
			try
			{
				switch ( int(report_type) )
				{
				case rtButtons:
					GiiMote::gm->wc[GiiMote::gm->wmIndex]->SetReportType(WiimoteLib::InputReport::Buttons, GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex], bool(continuous));
					break;
				case rtButtonsAccel:
					GiiMote::gm->wc[GiiMote::gm->wmIndex]->SetReportType(WiimoteLib::InputReport::ButtonsAccel, GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex], bool(continuous));
					break;
				case rtButtonsExtension:
					GiiMote::gm->wc[GiiMote::gm->wmIndex]->SetReportType(WiimoteLib::InputReport::ButtonsExtension, GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex], bool(continuous));
					break;
				case rtExtensionAccel:
					GiiMote::gm->wc[GiiMote::gm->wmIndex]->SetReportType(WiimoteLib::InputReport::ExtensionAccel, GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex], bool(continuous));
					break;
				case rtIRAccel:
					GiiMote::gm->wc[GiiMote::gm->wmIndex]->SetReportType(WiimoteLib::InputReport::IRAccel, GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex], bool(continuous));
					break;
				case rtIRExtensionAccel:
					GiiMote::gm->wc[GiiMote::gm->wmIndex]->SetReportType(WiimoteLib::InputReport::IRExtensionAccel, GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex], bool(continuous));
					break;
				case rtReadData:
					GiiMote::gm->wc[GiiMote::gm->wmIndex]->SetReportType(WiimoteLib::InputReport::ReadData, GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex], bool(continuous));
					break;
				case rtStatus:
					GiiMote::gm->wc[GiiMote::gm->wmIndex]->SetReportType(WiimoteLib::InputReport::Status, GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex], bool(continuous));
					break;
				case rtAuto:
					if (GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->Extension)
					{
						GiiMote::gm->wc[GiiMote::gm->wmIndex]->SetReportType(WiimoteLib::InputReport::IRExtensionAccel, GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex], bool(continuous));
					}
					else
					{
						GiiMote::gm->wc[GiiMote::gm->wmIndex]->SetReportType(WiimoteLib::InputReport::IRAccel, GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex], bool(continuous));
					}
					break;
				default:
					return ( 0 );
					break;
				}
			}
			catch(...)
			{
				return ( -1 );
			}
		}

		GiiMote::gm->report_type[GiiMote::gm->wmIndex] = int(report_type);
		GiiMote::gm->continuous[GiiMote::gm->wmIndex]  = bool(continuous);

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
	double wm_get_report_type()
	{
		return ( double(GiiMote::gm->report_type[GiiMote::gm->wmIndex]) );
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
	double wm_get_report_continuous()
	{
		return ( double(GiiMote::gm->continuous[GiiMote::gm->wmIndex]) );
	}

	/// <summary>Gets the guid of the current Wii Remote</summary>
	/// <returns>Guid as char*</returns>
	char* wm_get_guid_current()
	{
		return ( toCharArray(GiiMote::gm->wc[GiiMote::gm->wmIndex]->ID.ToString()) );
	}

	/// <summary>Gets the guid of the given Wii Remote</summary>
	/// <param name="val">The hashed guid of the Wii Remote</param>
	/// <returns>guid as char* or an empty char* on error</returns>
	char* wm_get_guid_id(double val)
	{
		for (int i = 0; i < GiiMote::gm->wc->Count; i++)
		{
			if (val == GiiMote::gm->wc[i]->ID.GetHashCode())
			{
				return ( toCharArray(GiiMote::gm->wc[i]->ID.ToString()) );
			}
		}

		return ( "" );
	}

	/// <summary>Hashes the guid of the current Wii Remote</summary>
	/// <returns>Guid hash as double</returns>
	double wm_get_id_current()
	{
		return ( (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->ID.GetHashCode() );
	}

	/// <summary>Hashes the guid of the given Wii Remote</summary>
	/// <param name="guid">The guid of the Wii Remote</param>
	/// <returns>Guid hash as double or -1 on error</returns>
	double wm_get_id_guid(char* guid)
	{
		System::String^ GUID = gcnew System::String(guid);
		GUID->Replace("-","");
		GUID->Replace("{","");
		GUID->Replace("}","");
		for (int i = 0; i < GiiMote::gm->wc->Count; i++)
		{
			System::String^ temp = gcnew System::String(wm_get_guid_current());
			temp->Replace("-","");
			temp->Replace("{","");
			temp->Replace("}","");
			if (GUID == temp)
			{
				delete GUID;
				delete temp;
				return ( (double)GiiMote::gm->wc[i]->ID.GetHashCode() );
			}
			delete temp;
		}
		delete GUID;
		return ( -1.0 );
	}

	/// <summary>Gets the index of the given Wii Remote</summary>
	/// <param name="guid">The guid of the Wii Remote</param>
	/// <returns>Index</returns>
	double wm_get_index_guid(char* guid)
	{
		System::String^ GUID = gcnew System::String(guid);
		GUID->Replace("-","");
		GUID->Replace("{","");
		GUID->Replace("}","");
		for (int i = 0; i < GiiMote::gm->wc->Count; i++)
		{
			System::String^ temp = GiiMote::gm->wc[i]->ID.ToString();
			temp->Replace("-","");
			temp->Replace("{","");
			temp->Replace("}","");
			if (GUID == temp)
			{
				delete GUID;
				delete temp;
				return ( i );
			}
			delete temp;
		}
		delete GUID;
		return ( -1.0 );
	}

	/// <summary>Gets the index of the given Wii Remote</summary>
	/// <param name="guid">The hashed guid of the Wii Remote</param>
	/// <returns>Index</returns>
	double wm_get_index_id(double guid)
	{
		for (int i = 0; i < GiiMote::gm->wc->Count; i++)
		{
			if (guid == GiiMote::gm->wc[i]->ID.GetHashCode())
			{
				return ( i );
			}
		}
		return ( -1 );
	}

	/// <summary>Gets the index of the current Wii Remote</summary>
	/// <returns>Index</returns>
	double wm_get_index_current()
	{
		return ( (double)GiiMote::gm->wmIndex);
	}

	/////////////////////////
	// LED Functions
	/////////////////////////
	/// <summary>Gets the state of an LED</summary>
	/// <param name="led_num">The LED to get the state of (1-4)</param>
	/// <returns>The state of the LED</returns>
	double wm_get_led(double led_num)
	{
		bool led = false;
		try
		{
			switch( (int)led_num )
			{
			case 1:
				led = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->LEDState.LED1;
				break;
			case 2:
				led = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->LEDState.LED2;
				break;
			case 3:
				led = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->LEDState.LED3;
				break;
			case 4:
				led = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->LEDState.LED4;
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
	double wm_set_leds(double led1, double led2, double led3, double led4)
	{
		bool bLed1,bLed2,bLed3,bLed4;
		bLed1 = (led1 > 0.5);
		bLed2 = (led2 > 0.5);
		bLed3 = (led3 > 0.5);
		bLed4 = (led4 > 0.5);

		try
		{
			GiiMote::gm->wc[GiiMote::gm->wmIndex]->SetLEDs(bLed1,bLed2,bLed3,bLed4);
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
	double wm_set_leds_int(double val)
	{
		int LEDs = (int)val;
		try
		{
			GiiMote::gm->wc[GiiMote::gm->wmIndex]->SetLEDs( LEDs );
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
	double wm_get_battery()
	{
		double battery_state;
		try
		{
			battery_state = (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->Battery;
		}
		catch(...)
		{
			return ( - 1 );
		}
		return ( battery_state );
	}

	/// <summary>Updates the Wii Remote's status</summary>
	/// <returns>Success</returns>
	double wm_get_status()
	{
		try
		{
			GiiMote::gm->wc[GiiMote::gm->wmIndex]->GetStatus();
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
	double wm_check_extension()
	{
		double extension_type;
		try
		{
			switch(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->ExtensionType)
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
	double wm_set_rumble(double rumbling)
	{
		try
		{
			GiiMote::gm->wc[GiiMote::gm->wmIndex]->SetRumble( rumbling > 0.5 );
		}
		catch(...)
		{
			return (0);
		}
		return (1);
	}
	/// <summary>Vibration motor status</summary>
	/// <returns>Rumbling (1 or 0) or Error (-1)</returns>
	double wm_get_rumble()
	{
		double rumbling;
		try
		{
			rumbling = (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->Rumble;
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
	double wm_get_calibration_x0()
	{
		return ( (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelCalibrationInfo.X0 );
	}
	/// <summary>Gets the gravity at rest of the accelerometer</summary>
	/// <returns>Normalized calibration data</returns>
	double wm_get_calibration_xg()
	{
		return ( (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelCalibrationInfo.XG );
	}
	/// <summary>Gets the zero point of the accelerometer</summary>
	/// <returns>Normalized calibration data</returns>
	double wm_get_calibration_y0()
	{
		return ( (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelCalibrationInfo.Y0 );
	}
	/// <summary>Gets the gravity at rest of the accelerometer</summary>
	/// <returns>Normalized calibration data</returns>
	double wm_get_calibration_yg()
	{
		return ( (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelCalibrationInfo.YG );
	}
	/// <summary>Gets the zero point of the accelerometer</summary>
	/// <returns>Normalized calibration data</returns>
	double wm_get_calibration_z0()
	{
		return ( (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelCalibrationInfo.Z0 );
	}
	/// <summary>Gets the gravity at rest of the accelerometer</summary>
	/// <returns>Normalized calibration data</returns>
	double wm_get_calibration_zg()
	{
		return ( (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelCalibrationInfo.ZG );
	}
	// Set
	/// <summary>Sets the zero point of the accelerometer</summary>
	/// <param name="val">X0 Value as byte</param>
	/// <returns>Success</returns>
	double wm_set_calibration_x0(double val)
	{
		try
		{
			GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelCalibrationInfo.X0 = (unsigned char)val;
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
	double wm_set_calibration_xg(double val)
	{
		try
		{
			GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelCalibrationInfo.XG = (unsigned char)val;
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
	double wm_set_calibration_y0(double val)
	{
		try
		{
			GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelCalibrationInfo.Y0 = (unsigned char)val;
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
	double wm_set_calibration_yg(double val)
	{
		try
		{
			GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelCalibrationInfo.YG = (unsigned char)val;
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
	double wm_set_calibration_z0(double val)
	{
		try
		{
			GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelCalibrationInfo.Z0 = (unsigned char)val;
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
	double wm_set_calibration_zg(double val)
	{
		try
		{
			GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->AccelCalibrationInfo.ZG = (unsigned char)val;
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
	double wm_bin_read_byte(double address)
	{
		double value;
		try
		{
			value = double( (GiiMote::gm->wc[GiiMote::gm->wmIndex]->ReadData((int)address,1))[0] );
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
	double wm_bin_write_byte(double address, double value)
	{
		try
		{
			GiiMote::gm->wc[GiiMote::gm->wmIndex]->WriteData((int)address,(unsigned char)value);
		}
		catch(...)
		{
			return ( 0 );
		}
		return ( 1 );
	}
