// Wiimote.h - Contains functions and constants relating to the Wii Remote in general.

namespace GiiMoteLib {

	/////////////////////////
	// Connection Functions
	/////////////////////////

	double GiiMote::wm_connected(void)
	{
		return ((double)this->connected);
	}

	double GiiMote::wm_connect()
	{
		if (!wm_connected())
		{
			this->wm->Connect();
			this->connected = true;
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
			this->wm->GetStatus();
		}

		return (wm_connected());
	}

	double GiiMote::wm_set_write_method(double alt_write_method)
	{
		this->wm->AltWriteMethod = (alt_write_method > 0);
		return ( 1 );
	}

	double GiiMote::wm_disconnect(void)
	{
		if (wm_connected())
		{
			this->wm->Disconnect();
			this->connected = false;
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

		this->wm->SetLEDs(bLed1,bLed2,bLed3,bLed4);

		return ( 1 );
	}

	double GiiMote::wm_set_leds_int(double val)
	{
		int LEDs = (int)val;
		this->wm->SetLEDs( LEDs );
		return ( (double)LEDs );
	}

	/////////////////////////
	// Status Functions
	/////////////////////////

	double GiiMote::wm_get_battery()
	{
		this->wm->GetStatus();
		return ( (double)this->wmState->Battery );
	}

	double GiiMote::wm_check_extension()
	{
		double extension_type;
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
	
		return (extension_type);
	}

	double GiiMote::wm_set_rumble(double rumbling)
	{
		if (rumbling <= 0)
		{
			this->wm->SetRumble(false);
		}
		else
		{
			this->wm->SetRumble(true);
		}
		return (wm_get_rumble());
	}

	double GiiMote::wm_get_rumble()
	{
		return ( (double)this->wmState->Rumble );
	}

	/////////////////////////
	// Calibration Functions
	/////////////////////////
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

	/////////////////////////
	// Calibration Functions
	/////////////////////////
	double GiiMote::wm_bin_read_byte(double address)
	{
		double value = -1;
		value = double( (this->wm->ReadData((int)address,1))[0] );
		return ( value );
	}

	double GiiMote::wm_bin_write_byte(double address, double value)
	{
		this->wm->WriteData((int)address,(unsigned char)value);
		return ( 1 );
	}
}