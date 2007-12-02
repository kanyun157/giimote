// Wiimote.h - Contains functions and constants relating to the Wii Remote in general.

namespace GiiMoteLib {

	/////////////////////////
	// Connection Functions
	/////////////////////////

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
		// return ((double)this->connected);
	}

	// Return Codes for wm_connect()
	//		-1 = Wii Remote already connected
	//		 0 = Wii Remote failed to connect / No Wii Remote detected
	//		 1 = Wii Remote connected successfully
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
				throw ( -1 );
				break;
			}
		}
		catch (...)
		{
			return ( 0 );
		}
		return ( 1 );
	}

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
				// Do nothing, the return statement will handle it.
			}
			// this->connected = false;
		}
		return (!wm_connected());
	}

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
	double GiiMote::wm_get_calibration_x0()
	{
		return ( (double)this->wmState->AccelCalibrationInfo.X0 );
	}
	double GiiMote::wm_get_calibration_xg()
	{
		return ( (double)this->wmState->AccelCalibrationInfo.XG );
	}
	double GiiMote::wm_get_calibration_y0()
	{
		return ( (double)this->wmState->AccelCalibrationInfo.Y0 );
	}
	double GiiMote::wm_get_calibration_yg()
	{
		return ( (double)this->wmState->AccelCalibrationInfo.YG );
	}
	double GiiMote::wm_get_calibration_z0()
	{
		return ( (double)this->wmState->AccelCalibrationInfo.Z0 );
	}
	double GiiMote::wm_get_calibration_zg()
	{
		return ( (double)this->wmState->AccelCalibrationInfo.ZG );
	}
	// Set
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
	double GiiMote::wm_get_calibration_y0(double val)
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
	double GiiMote::wm_get_calibration_yg(double val)
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
	double GiiMote::wm_get_calibration_z0(double val)
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
	double GiiMote::wm_get_calibration_zg(double val)
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