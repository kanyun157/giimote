// This is the main DLL file.

/*
TODO:
	Add Sound and Speaker Functions
	Add Calibration Functions
*/

#include "stdafx.h"

#include "GiiMote.h"

using namespace GiiMoteLib;
using namespace System;
using namespace System::IO;

////////////////////////////////////////////
// Setup and Connection
////////////////////////////////////////////

export double __stdcall gm_init()
{
	GiiMote::gm_create();
	return (1);
}

export double __stdcall message()
{
	System::Windows::Forms::MessageBox::Show("test");
	return (1);
}


export double __stdcall gm_cleanup()
{
	GiiMote::gm_destroy();
	return (1);
}

export double __stdcall wm_connect(double use_alt_write_method)
{
	if (!GiiMote::dll_instance->connected)
	{
		bool alt_write_method = 0;
		if (use_alt_write_method != 0)
		{
			alt_write_method = true;
		}
		else
		{
			alt_write_method = false;
		}
		GiiMote::gm_connect(alt_write_method);
	}

	return ((double)GiiMote::dll_instance->connected);
}

export double __stdcall wm_disconnect(void)
{
	GiiMote::gm_disconnect();
	return (double(!GiiMote::dll_instance->connected));
}

export double __stdcall wm_connected(void)
{
	return ((double)GiiMote::dll_instance->connected);
}

////////////////////////////////////////////
// GiiMote Class Wrapper Functions
////////////////////////////////////////////



////////////////////////////////////////////
// Wiimote Class Wrapper Functions
////////////////////////////////////////////

export double __stdcall wm_get_leds(double led_num)
{
	// GiiMote^ dll_instance = GiiMote::dll_instance;
	int led = (int)led_num;
	if (led > 4) { led = 4; }
	if (led < 1) { led = 1; }
	switch(led)
	{
	case 1:
		led = GiiMote::dll_instance->wmState->LEDs.LED1;
		break;
	case 2:
		led = GiiMote::dll_instance->wmState->LEDs.LED2;
		break;
	case 3:
		led = GiiMote::dll_instance->wmState->LEDs.LED3;
		break;
	case 4:
		led = GiiMote::dll_instance->wmState->LEDs.LED4;
		break;
	default:
		led = 0;
		break;
	}

	return ((double)led);
}

export double __stdcall wm_set_led(double led_num, double led_on)
{
	int led = (int)led_num;
	if (led > 4) { led = 4; }
	if (led < 1) { led = 1; }

	bool led_status = 0;
	if (led_on == 0) { led_status = 0; } else { led_status = 1; }

	bool led1, led2, led3, led4;
	led1 = GiiMote::dll_instance->wmState->LEDs.LED1;
	led2 = GiiMote::dll_instance->wmState->LEDs.LED2;
	led3 = GiiMote::dll_instance->wmState->LEDs.LED3;
	led4 = GiiMote::dll_instance->wmState->LEDs.LED4;

	switch (led)
	{
	case 1:
		GiiMote::dll_instance->wm->SetLEDs(led_status,led2,led3,led4);
		break;
	case 2:
		GiiMote::dll_instance->wm->SetLEDs(led1,led_status,led3,led4);
		break;
	case 3:
		GiiMote::dll_instance->wm->SetLEDs(led1,led2,led_status,led4);
		break;
	case 4:
		GiiMote::dll_instance->wm->SetLEDs(led1,led2,led3,led_status);
		break;
	}
	return (led);
}

export double __stdcall wm_check_button(double key_code)
{
	bool is_pressed = 0;
	switch ((int)key_code)
	{
	case btnA:
		is_pressed = GiiMote::dll_instance->wmState->ButtonState.A;
		break;
	case btnB:
		is_pressed = GiiMote::dll_instance->wmState->ButtonState.B;
		break;
	case btnUp:
		is_pressed = GiiMote::dll_instance->wmState->ButtonState.Up;
		break;
	case btnDown:
		is_pressed = GiiMote::dll_instance->wmState->ButtonState.Down;
		break;
	case btnRight:
		is_pressed = GiiMote::dll_instance->wmState->ButtonState.Right;
		break;
	case btnLeft:
		is_pressed = GiiMote::dll_instance->wmState->ButtonState.Left;
		break;
	case btnOne:
		is_pressed = GiiMote::dll_instance->wmState->ButtonState.One;
		break;
	case btnTwo:
		is_pressed = GiiMote::dll_instance->wmState->ButtonState.Two;
		break;
	case btnPlus:
		is_pressed = GiiMote::dll_instance->wmState->ButtonState.Plus;
		break;
	case btnMinus:
		is_pressed = GiiMote::dll_instance->wmState->ButtonState.Minus;
		break;
	case btnHome:
		is_pressed = GiiMote::dll_instance->wmState->ButtonState.Home;
		break;
	default:
		is_pressed = false;
		break;
	}
	return ((double)is_pressed);
}

export double __stdcall wm_classic_check_button(double key_code)
{
	// GiiMote^ dll_instance = GiiMote::dll_instance;
	bool is_pressed = 0;
	switch ((int)key_code)
	{
	case btnA:
		is_pressed = GiiMote::dll_instance->wmState->ClassicControllerState.ButtonState.A;
		break;
	case btnB:
		is_pressed = GiiMote::dll_instance->wmState->ClassicControllerState.ButtonState.B;
		break;
	case btnUp:
		is_pressed = GiiMote::dll_instance->wmState->ClassicControllerState.ButtonState.Up;
		break;
	case btnDown:
		is_pressed = GiiMote::dll_instance->wmState->ClassicControllerState.ButtonState.Down;
		break;
	case btnRight:
		is_pressed = GiiMote::dll_instance->wmState->ClassicControllerState.ButtonState.Right;
		break;
	case btnLeft:
		is_pressed = GiiMote::dll_instance->wmState->ClassicControllerState.ButtonState.Left;
		break;
	case btnX:
		is_pressed = GiiMote::dll_instance->wmState->ClassicControllerState.ButtonState.X;
		break;
	case btnY:
		is_pressed = GiiMote::dll_instance->wmState->ClassicControllerState.ButtonState.Y;
		break;
	case btnPlus:
		is_pressed = GiiMote::dll_instance->wmState->ClassicControllerState.ButtonState.Plus;
		break;
	case btnMinus:
		is_pressed = GiiMote::dll_instance->wmState->ClassicControllerState.ButtonState.Minus;
		break;
	case btnHome:
		is_pressed = GiiMote::dll_instance->wmState->ClassicControllerState.ButtonState.Home;
		break;
	case btnL:
		is_pressed = GiiMote::dll_instance->wmState->ClassicControllerState.ButtonState.TriggerL;
		break;
	case btnR:
		is_pressed = GiiMote::dll_instance->wmState->ClassicControllerState.ButtonState.TriggerR;
		break;
	case btnZL:
		is_pressed = GiiMote::dll_instance->wmState->ClassicControllerState.ButtonState.ZL;
		break;
	case btnZR:
		is_pressed = GiiMote::dll_instance->wmState->ClassicControllerState.ButtonState.ZR;
		break;
	default:
		is_pressed = false;
		break;
	}
	return ((double)is_pressed);
}

export double __stdcall wm_nunchuck_check_button(double key_code)
{
	// GiiMote^ dll_instance = GiiMote::dll_instance;
	bool is_pressed = 0;
	switch ((int)key_code)
	{
	case btnC:
		is_pressed = GiiMote::dll_instance->wmState->NunchukState.C;
		break;
	case btnZ:
		is_pressed = GiiMote::dll_instance->wmState->NunchukState.Z;
		break;
	default:
		is_pressed = false;
		break;
	}
	return ((double)is_pressed);
}

export double __stdcall wm_get_battery()
{
	GiiMote::dll_instance->wm->GetBatteryLevel();
	return ( (double)GiiMote::dll_instance->wmState->Battery );
}

export double __stdcall wm_nunchuck_xpos()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.X );
}

export double __stdcall wm_nunchuck_ypos()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.Y );
}

export double __stdcall wm_nunchuck_rawx()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.RawX );
}

export double __stdcall wm_nunchuck_rawy()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.RawY );
}

export double __stdcall wm_nunchuck_direction()
{
	double yy = wm_nunchuck_ypos();
	double xx = wm_nunchuck_xpos();
	return ( System::Math::Atan( yy/xx ) );
}

export double __stdcall wm_classic_xpos(double stick)
{
	// GiiMote^ dll_instance = GiiMote::dll_instance;
	if (stick == joyL)
	{
		return (GiiMote::dll_instance->wmState->ClassicControllerState.XL);
	}
	else
	{
		return (GiiMote::dll_instance->wmState->ClassicControllerState.XR);
	}
}

export double __stdcall wm_classic_ypos(double stick)
{
	if (stick == joyL)
	{
		return (GiiMote::dll_instance->wmState->ClassicControllerState.YL);
	}
	else
	{
		return (GiiMote::dll_instance->wmState->ClassicControllerState.YR);
	}
}

export double __stdcall wm_classic_rawx(double stick)
{
	if (stick == joyL)
	{
		return (GiiMote::dll_instance->wmState->ClassicControllerState.RawXL);
	}
	else
	{
		return (GiiMote::dll_instance->wmState->ClassicControllerState.RawXR);
	}
}

export double __stdcall wm_classic_rawy(double stick)
{
	if (stick == joyL)
	{
		return (GiiMote::dll_instance->wmState->ClassicControllerState.RawYL);
	}
	else
	{
		return (GiiMote::dll_instance->wmState->ClassicControllerState.RawYR);
	}
}

export double __stdcall wm_classic_direction(double stick)
{
	double yy = wm_classic_ypos(stick);
	double xx = wm_classic_xpos(stick);
	return ( System::Math::Atan( yy/xx ) );
}

export double __stdcall wm_classic_trigger_pressure(double trigger)
{
	double pressure = 0;
	if (trigger == btnL || trigger == 0)
	{
		// Left
		pressure = (double)GiiMote::dll_instance->wmState->ClassicControllerState.TriggerL;

	}
	else
	{
		if (trigger == btnR || trigger == 1)
		{
			// Right
			pressure = (double)GiiMote::dll_instance->wmState->ClassicControllerState.TriggerR;
		}
	}

	return ( pressure );
}

export double __stdcall wm_classic_trigger_raw(double trigger)
{
	double pressure = 0;
	if (trigger == btnL || trigger == 0)
	{
		// Left
		pressure = (double)GiiMote::dll_instance->wmState->ClassicControllerState.RawTriggerL;

	}
	else
	{
		if (trigger == btnR || trigger == 1)
		{
			// Right
			pressure = (double)GiiMote::dll_instance->wmState->ClassicControllerState.RawTriggerR;
		}
	}

	return ( pressure );
}

export double __stdcall wm_check_extension()
{
	double extension_type;
	switch(GiiMote::dll_instance->wmState->ExtensionType)
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

export double __stdcall wm_set_rumble(double rumbling)
{
	if (rumbling == 0)
	{
		GiiMote::dll_instance->wm->SetRumble(false);
	}
	else
	{
		GiiMote::dll_instance->wm->SetRumble(true);
	}
	return (rumbling);
}
export double __stdcall wm_get_rumble()
{
	return ( (double)GiiMote::dll_instance->wmState->Rumble );
}

export double __stdcall wm_get_accel_x()
{
	return ( (double)GiiMote::dll_instance->wmState->AccelState.X );
}
export double __stdcall wm_get_accel_y()
{
	return ( (double)GiiMote::dll_instance->wmState->AccelState.Y );
}
export double __stdcall wm_get_accel_z()
{
	return ( (double)GiiMote::dll_instance->wmState->AccelState.Z );
}
export double __stdcall wm_get_accel_rawx()
{
	return ( (double)GiiMote::dll_instance->wmState->AccelState.RawX );
}
export double __stdcall wm_get_accel_rawy()
{
	return ( (double)GiiMote::dll_instance->wmState->AccelState.RawY );
}
export double __stdcall wm_get_accel_rawz()
{
	return ( (double)GiiMote::dll_instance->wmState->AccelState.RawZ );
}

export double __stdcall wm_nunchuck_get_accel_x()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.AccelState.X );
}
export double __stdcall wm_nunchuck_get_accel_y()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.AccelState.Y );
}
export double __stdcall wm_nunchuck_get_accel_z()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.AccelState.Z );
}

export double __stdcall wm_nunchuck_get_accel_rawx()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.AccelState.RawX );
}
export double __stdcall wm_nunchuck_get_accel_rawy()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.AccelState.RawY );
}
export double __stdcall wm_nunchuck_get_accel_rawz()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.AccelState.RawZ );
}

export double __stdcall wm_ir_found_dot(double dot_number)
{
	bool found_dot = 0;
	switch ((int)dot_number)
	{
	case 1:
		found_dot = GiiMote::dll_instance->wmState->IRState.Found1;
		break;
	case 2:
		found_dot = GiiMote::dll_instance->wmState->IRState.Found2;
		break;
	default:
		break;
	}
	return ( (double)found_dot );
}

export double __stdcall wm_ir_dot_size(double dot_number)
{
	int size = 0;
	switch ((int)dot_number)
	{
	case 1:
		size = GiiMote::dll_instance->wmState->IRState.Size1;
		break;
	case 2:
		size = GiiMote::dll_instance->wmState->IRState.Size2;
		break;
	default:
		break;
	}
	return ( (double)size );
}

export double __stdcall wm_ir_dot_get_x(double dot_number)
{
	float xx = -1.0;
	switch ((int)dot_number)
	{
	case 1:
		xx = GiiMote::dll_instance->wmState->IRState.X1;
		break;
	case 2:
		xx = GiiMote::dll_instance->wmState->IRState.X2;
		break;
	default:
		break;
	}
	return ( (double)xx );
}

export double __stdcall wm_ir_dot_get_y(double dot_number)
{
	float yy = -1.0;
	switch ((int)dot_number)
	{
	case 1:
		yy = GiiMote::dll_instance->wmState->IRState.Y1;
		break;
	case 2:
		yy = GiiMote::dll_instance->wmState->IRState.Y2;
		break;
	default:
		break;
	}
	return ( (double)yy );
}

export double __stdcall wm_ir_dot_get_rawx(double dot_number)
{
	int xx = -1;
	switch ((int)dot_number)
	{
	case 1:
		xx = GiiMote::dll_instance->wmState->IRState.RawX1;
		break;
	case 2:
		xx = GiiMote::dll_instance->wmState->IRState.RawX2;
		break;
	default:
		break;
	}
	return ( (double)xx );
}

export double __stdcall wm_ir_dot_get_rawy(double dot_number)
{
	int yy = -1;
	switch ((int)dot_number)
	{
	case 1:
		yy = GiiMote::dll_instance->wmState->IRState.RawY1;
		break;
	case 2:
		yy = GiiMote::dll_instance->wmState->IRState.RawY2;
		break;
	default:
		break;
	}
	return ( (double)yy );
}

export double __stdcall wm_get_calibration_x0()
{
	return ( (double)GiiMote::dll_instance->wmState->CalibrationInfo.X0 );
}
export double __stdcall wm_get_calibration_xg()
{
	return ( (double)GiiMote::dll_instance->wmState->CalibrationInfo.XG );
}
export double __stdcall wm_get_calibration_y0()
{
	return ( (double)GiiMote::dll_instance->wmState->CalibrationInfo.Y0 );
}
export double __stdcall wm_get_calibration_yg()
{
	return ( (double)GiiMote::dll_instance->wmState->CalibrationInfo.YG );
}
export double __stdcall wm_get_calibration_z0()
{
	return ( (double)GiiMote::dll_instance->wmState->CalibrationInfo.Z0 );
}
export double __stdcall wm_get_calibration_zg()
{
	return ( (double)GiiMote::dll_instance->wmState->CalibrationInfo.ZG );
}

export double __stdcall wm_nunchuck_get_calibration_x0()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.CalibrationInfo.X0 );
}
export double __stdcall wm_nunchuck_get_calibration_xg()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.CalibrationInfo.XG );
}
export double __stdcall wm_nunchuck_get_calibration_y0()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.CalibrationInfo.Y0 );
}
export double __stdcall wm_nunchuck_get_calibration_yg()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.CalibrationInfo.YG );
}
export double __stdcall wm_nunchuck_get_calibration_z0()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.CalibrationInfo.Z0 );
}
export double __stdcall wm_nunchuck_get_calibration_zg()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.CalibrationInfo.ZG );
}

export double __stdcall wm_nunchuck_get_calibration_maxx()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.CalibrationInfo.MaxX );
}
export double __stdcall wm_nunchuck_get_calibration_maxy()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.CalibrationInfo.MaxY );
}
export double __stdcall wm_nunchuck_get_calibration_midx()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.CalibrationInfo.MidX );
}
export double __stdcall wm_nunchuck_get_calibration_midy()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.CalibrationInfo.MidY );
}
export double __stdcall wm_nunchuck_get_calibration_minx()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.CalibrationInfo.MinX );
}
export double __stdcall wm_nunchuck_get_calibration_miny()
{
	return ( (double)GiiMote::dll_instance->wmState->NunchukState.CalibrationInfo.MinY );
}

export double __stdcall wm_classic_get_calibration_maxtrigger(double trigger)
{
	double returnValue = -1;
	switch ((int)trigger)
	{
	case btnL:
		returnValue = double(GiiMote::dll_instance->wmState->ClassicControllerState.CalibrationInfo.MaxTriggerL);
		break;
	case btnR:
		returnValue = double(GiiMote::dll_instance->wmState->ClassicControllerState.CalibrationInfo.MaxTriggerR);
		break;
	default:
		break;
	}
	return (returnValue);
}

export double __stdcall wm_classic_get_calibration_mintrigger(double trigger)
{
	double returnValue = -1;
	switch ((int)trigger)
	{
	case btnL:
		returnValue = double(GiiMote::dll_instance->wmState->ClassicControllerState.CalibrationInfo.MinTriggerL);
		break;
	case btnR:
		returnValue = double(GiiMote::dll_instance->wmState->ClassicControllerState.CalibrationInfo.MinTriggerR);
		break;
	default:
		break;
	}

	return (returnValue);
}

export double __stdcall wm_classic_get_calibration_maxx(double joystick)
{
	double returnValue = -1;
	switch ((int)joystick)
	{
	case joyL:
		returnValue = double(GiiMote::dll_instance->wmState->ClassicControllerState.CalibrationInfo.MaxXL);
		break;
	case joyR:
		returnValue = double(GiiMote::dll_instance->wmState->ClassicControllerState.CalibrationInfo.MaxXR);
		break;
	default:
		break;
	}

	return (returnValue);
}

export double __stdcall wm_classic_get_calibration_minx(double joystick)
{
	double returnValue = -1;
	switch ((int)joystick)
	{
	case joyL:
		returnValue = double(GiiMote::dll_instance->wmState->ClassicControllerState.CalibrationInfo.MinXL);
		break;
	case joyR:
		returnValue = double(GiiMote::dll_instance->wmState->ClassicControllerState.CalibrationInfo.MinXR);
		break;
	default:
		break;
	}
	return (returnValue);
}

export double __stdcall wm_classic_get_calibration_midx(double joystick)
{
	double returnValue = -1;
	switch ((int)joystick)
	{
	case joyL:
		returnValue = double(GiiMote::dll_instance->wmState->ClassicControllerState.CalibrationInfo.MidXL);
		break;
	case joyR:
		returnValue = double(GiiMote::dll_instance->wmState->ClassicControllerState.CalibrationInfo.MidXR);
		break;
	default:
		break;
	}

	return (returnValue);
}

export double __stdcall wm_classic_get_calibration_midy(double joystick)
{
	double returnValue = -1;
	switch ((int)joystick)
	{
	case joyL:
		returnValue = double(GiiMote::dll_instance->wmState->ClassicControllerState.CalibrationInfo.MidYL);
		break;
	case joyR:
		returnValue = double(GiiMote::dll_instance->wmState->ClassicControllerState.CalibrationInfo.MidYR);
		break;
	default:
		break;
	}
	return (returnValue);
}

export double __stdcall wm_classic_get_calibration_maxy(double joystick)
{
	double returnValue = -1;
	switch ((int)joystick)
	{
	case joyL:
		returnValue = double(GiiMote::dll_instance->wmState->ClassicControllerState.CalibrationInfo.MaxYL);
		break;
	case joyR:
		returnValue = double(GiiMote::dll_instance->wmState->ClassicControllerState.CalibrationInfo.MaxYR);
		break;
	default:
		break;
	}
	return (returnValue);
}

export double __stdcall wm_classic_get_calibration_miny(double joystick)
{
	double returnValue = -1;

	switch ((int)joystick)
	{
	case joyL:
		returnValue = double(GiiMote::dll_instance->wmState->ClassicControllerState.CalibrationInfo.MinYL);
		break;
	case joyR:
		returnValue = double(GiiMote::dll_instance->wmState->ClassicControllerState.CalibrationInfo.MinYR);
		break;
	default:
		break;
	}
	return (returnValue);
}

export double __stdcall wm_bin_read_byte(double address)
{
	double value = -1;
	value = double( (GiiMote::dll_instance->wm->ReadData((int)address,1))[0] );
	return value;
}

export double __stdcall wm_bin_write_byte(double address, double value)
{
	GiiMote::dll_instance->wm->WriteData((int)address,(unsigned char)value);
	return (1);
}