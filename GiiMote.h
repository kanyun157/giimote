// GiiMote.h

/**********************************************************************************

///////////////////////////////////
// GED Function Definitions
///////////////////////////////////

// kind dll-cdecl
kind dll-stdcall
hfunction gm_init():real
hfunction gm_cleanup():real
function wm_connect(use_alt_write_method:real):real
function wm_disconnect():real
function wm_connected():real
function wm_get_led(led:real):real
function wm_set_led(led:real,on:real):real
function wm_check_button(wm_button:real):real
function wm_classic_check_button(wm_button:real):real
function wm_nunchuck_check_button(wm_button:real):real
function wm_get_battery():real
function wm_nunchuck_xpos():real
function wm_nunchuck_ypos():real
hfunction wm_nunchuck_rawx():real
hfunction wm_nunchuck_rawy():real
function wm_nunchuck_direction():real
function wm_classic_xpos(wm_joystick:real):real
function wm_classic_ypos(wm_joystick:real):real
hfunction wm_classic_rawx(wm_joystick:real):real
hfunction wm_classic_rawy(wm_joystick:real):real
function wm_classic_direction(wm_joystick:real):real
function wm_classic_trigger_pressure(trigger:real):real
hfunction wm_classic_trigger_raw(trigger:real):real
function wm_check_extension():real
function wm_set_rumble(rumbling:real):real
function wm_get_rumble():real
function wm_get_accel_x():real
function wm_get_accel_y():real
function wm_get_accel_z():real
hfunction wm_get_accel_rawx():real
hfunction wm_get_accel_rawy():real
hfunction wm_get_accel_rawz():real
function wm_nunchuck_get_accel_x():real
function wm_nunchuck_get_accel_y():real
function wm_nunchuck_get_accel_z():real
hfunction wm_nunchuck_get_accel_rawx():real
hfunction wm_nunchuck_get_accel_rawy():real
hfunction wm_nunchuck_get_accel_rawz():real
function wm_ir_found_dot(dot:real):real
function wm_ir_dot_size(dot:real):real
function wm_ir_dot_get_x(dot:real):real
function wm_ir_dot_get_y(dot:real):real
hfunction wm_ir_dot_get_rawx(dot:real):real
hfunction wm_ir_dot_get_rawy(dot:real):real
function wm_get_calibration_x0():real
function wm_get_calibration_xg():real
function wm_get_calibration_y0():real
function wm_get_calibration_yg():real
function wm_get_calibration_z0():real
function wm_get_calibration_zg():real
function wm_nunchuck_get_calibration_x0():real
function wm_nunchuck_get_calibration_xg():real
function wm_nunchuck_get_calibration_y0():real
function wm_nunchuck_get_calibration_yg():real
function wm_nunchuck_get_calibration_z0():real
function wm_nunchuck_get_calibration_zg():real
function wm_nunchuck_get_calibration_maxx():real
function wm_nunchuck_get_calibration_maxy():real
function wm_nunchuck_get_calibration_midx():real
function wm_nunchuck_get_calibration_midy():real
function wm_nunchuck_get_calibration_minx():real
function wm_nunchuck_get_calibration_miny():real
function wm_classic_get_calibration_maxtrigger(trigger:real):real
function wm_classic_get_calibration_mintrigger(trigger:real):real
function wm_classic_get_calibration_maxx(joystick:real):real
function wm_classic_get_calibration_minx(joystick:real):real
function wm_classic_get_calibration_midx(joystick:real):real
function wm_classic_get_calibration_maxy(joystick:real):real
function wm_classic_get_calibration_miny(joystick:real):real
function wm_classic_get_calibration_midy(joystick:real):real
function wm_bin_read_byte(address:real):real
function wm_bin_write_byte(address:real,byte:real):real

///////////////////////////////////
// GED Constant Definitions
///////////////////////////////////

// General Buttons
const wm_a = 0
const wm_b = 1
const wm_up = 2
const wm_down = 3
const wm_right = 4
const wm_left = 5
const wm_one = 6
const wm_two = 7
const wm_plus = 8
const wm_minus = 9
const wm_home = 10

// Classic Specific
const wm_x = 6
const wm_y = 7
const wm_l = 11
const wm_r = 12
const wm_zl = 13
const wm_zr = 14

const wm_joy_left = 0
const wm_joy_right = 1

// Nunchuck Specific
const wm_c = 0
const wm_z = 1

// Extension Types
const ext_classic = 1
const ext_nunchuck = 2
const ext_none = 0
const ext_unknown = -1


**********************************************************************************/

#pragma once
///////////////////////
// Define Constants //
/////////////////////

#define export extern "C" __declspec( dllexport ) /*__cdecl*/


#define expClassic 1
#define expNunchuck 2
#define expNone 0
#define expUnknown -1
#define btnA 0
#define btnB 1
#define btnUp 2
#define btnDown 3
#define btnRight 4
#define btnLeft 5
#define btnOne 6
#define btnTwo 7
#define btnPlus 8
#define btnMinus 9
#define btnHome 10
#define btnX 6
#define btnY 7
#define btnL 11
#define btnR 12
#define btnZL 13
#define btnZR 14
#define btnC 0
#define btnZ 1
#define joyL 0
#define joyR 1

using namespace System;
using namespace WiimoteLib;

namespace GiiMoteLib {

	public ref class GiiMote
	{
	public:
		static GiiMote^ dll_instance;
		Wiimote^ wm;
		WiimoteState^ wmState;
		static bool created = false;
		static bool connected = false;
		

		 //////////////////
		// Constructors //
	   //////////////////
	public:
		GiiMote()
		{
			GiiMote::dll_instance = this;
			this->wm = gcnew Wiimote;
			GiiMote::connected = false;
			GiiMote::created = true;
		}
		~GiiMote()
		{
			// Cleanup after sloppy users.
			if (GiiMote::connected)
			{
				gm_disconnect();
			}
			// delete this->wm->OnWiimoteChanged;
			// delete this->wm->OnWiimoteExtensionChanged;
			delete this->wm;
			GiiMote::created = 0;
		}

		void wm_OnWiimoteExtensionChanged(System::Object^ sender, WiimoteExtensionChangedEventArgs^ args)
		{
			if(args->Inserted)
			{
				this->wm->SetReportType(Wiimote::InputReport::IRExtensionAccel, true);
			}
			else
			{
				this->wm->SetReportType(Wiimote::InputReport::IRAccel, true);
			}
		}

		void wm_OnWiimoteChanged(System::Object^ sender, WiimoteChangedEventArgs^ args)
		{
			this->wmState = args->WiimoteState;
		}

		/*static void gm_create()
		{
			if (!GiiMote::created)
			{
				gcnew GiiMote();
				// this->created = true;
			}
		}

		static void gm_destroy()
		{
			if (GiiMote::created)
			{
				delete this;
			}
		}*/

		/*static*/ void gm_connect(bool use_alt_write_method)
		{
			// System::Windows::Forms::MessageBox::Show(this->connected.ToString());
			if (!GiiMote::connected)
			{
				this->wm->AltWriteMethod = use_alt_write_method;
				this->wm->Connect();
				this->wm->SetReportType(Wiimote::InputReport::IRAccel, true);
				this->wm->OnWiimoteChanged += (gcnew WiimoteChangedEventHandler(this,&GiiMote::wm_OnWiimoteChanged));
				this->wm->OnWiimoteExtensionChanged += (gcnew WiimoteExtensionChanged(this,&GiiMote::wm_OnWiimoteExtensionChanged));
				this->wm->SetLEDs(false, false, false, false);
				this->wm->GetBatteryLevel();
				GiiMote::connected = 1;
			}
		}

		/*static*/ void gm_disconnect()
		{
			if (GiiMote::connected)
			{
				this->wm->Disconnect();
				GiiMote::connected = false;
			}
		}

		 //////////////////
		//  Functions   //
	   //////////////////
public:
/*double gm_init()
{
	GiiMote::gm_create();
	return (1);
}*/

/*double gm_cleanup()
{
	GiiMote::gm_destroy();
	return (1);
}*/

double wm_connect(double use_alt_write_method)
{
	if (!this->connected)
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

	return ((double)this->connected);
}

double wm_disconnect(void)
{
	GiiMote::gm_disconnect();
	return (double(!this->connected));
}

double wm_connected(void)
{
	return ((double)this->connected);
}

////////////////////////////////////////////
// GiiMote Class Wrapper Functions
////////////////////////////////////////////



////////////////////////////////////////////
// Wiimote Class Wrapper Functions
////////////////////////////////////////////

double wm_get_led(double led_num)
{
	// GiiMote^ this = this;
	int led = (int)led_num;
	if (led > 4) { led = 4; }
	if (led < 1) { led = 1; }
	switch(led)
	{
	case 1:
		led = this->wmState->LEDs.LED1;
		break;
	case 2:
		led = this->wmState->LEDs.LED2;
		break;
	case 3:
		led = this->wmState->LEDs.LED3;
		break;
	case 4:
		led = this->wmState->LEDs.LED4;
		break;
	default:
		led = 0;
		break;
	}

	return ((double)led);
}

double wm_set_led(double led_num, double led_on)
{
	int led = (int)led_num;
	if (led > 4) { led = 4; }
	if (led < 1) { led = 1; }

	bool led_status = 0;
	if (led_on == 0) { led_status = 0; } else { led_status = 1; }

	bool led1, led2, led3, led4;
	led1 = this->wmState->LEDs.LED1;
	led2 = this->wmState->LEDs.LED2;
	led3 = this->wmState->LEDs.LED3;
	led4 = this->wmState->LEDs.LED4;

	switch (led)
	{
	case 1:
		this->wm->SetLEDs(led_status,led2,led3,led4);
		break;
	case 2:
		this->wm->SetLEDs(led1,led_status,led3,led4);
		break;
	case 3:
		this->wm->SetLEDs(led1,led2,led_status,led4);
		break;
	case 4:
		this->wm->SetLEDs(led1,led2,led3,led_status);
		break;
	}
	return (led);
}

double wm_check_button(double key_code)
{
	bool is_pressed = 0;
	switch ((int)key_code)
	{
	case btnA:
		is_pressed = this->wmState->ButtonState.A;
		break;
	case btnB:
		is_pressed = this->wmState->ButtonState.B;
		break;
	case btnUp:
		is_pressed = this->wmState->ButtonState.Up;
		break;
	case btnDown:
		is_pressed = this->wmState->ButtonState.Down;
		break;
	case btnRight:
		is_pressed = this->wmState->ButtonState.Right;
		break;
	case btnLeft:
		is_pressed = this->wmState->ButtonState.Left;
		break;
	case btnOne:
		is_pressed = this->wmState->ButtonState.One;
		break;
	case btnTwo:
		is_pressed = this->wmState->ButtonState.Two;
		break;
	case btnPlus:
		is_pressed = this->wmState->ButtonState.Plus;
		break;
	case btnMinus:
		is_pressed = this->wmState->ButtonState.Minus;
		break;
	case btnHome:
		is_pressed = this->wmState->ButtonState.Home;
		break;
	default:
		is_pressed = false;
		break;
	}
	return ((double)is_pressed);
}

double wm_classic_check_button(double key_code)
{
	// GiiMote^ this = this;
	bool is_pressed = 0;
	switch ((int)key_code)
	{
	case btnA:
		is_pressed = this->wmState->ClassicControllerState.ButtonState.A;
		break;
	case btnB:
		is_pressed = this->wmState->ClassicControllerState.ButtonState.B;
		break;
	case btnUp:
		is_pressed = this->wmState->ClassicControllerState.ButtonState.Up;
		break;
	case btnDown:
		is_pressed = this->wmState->ClassicControllerState.ButtonState.Down;
		break;
	case btnRight:
		is_pressed = this->wmState->ClassicControllerState.ButtonState.Right;
		break;
	case btnLeft:
		is_pressed = this->wmState->ClassicControllerState.ButtonState.Left;
		break;
	case btnX:
		is_pressed = this->wmState->ClassicControllerState.ButtonState.X;
		break;
	case btnY:
		is_pressed = this->wmState->ClassicControllerState.ButtonState.Y;
		break;
	case btnPlus:
		is_pressed = this->wmState->ClassicControllerState.ButtonState.Plus;
		break;
	case btnMinus:
		is_pressed = this->wmState->ClassicControllerState.ButtonState.Minus;
		break;
	case btnHome:
		is_pressed = this->wmState->ClassicControllerState.ButtonState.Home;
		break;
	case btnL:
		is_pressed = this->wmState->ClassicControllerState.ButtonState.TriggerL;
		break;
	case btnR:
		is_pressed = this->wmState->ClassicControllerState.ButtonState.TriggerR;
		break;
	case btnZL:
		is_pressed = this->wmState->ClassicControllerState.ButtonState.ZL;
		break;
	case btnZR:
		is_pressed = this->wmState->ClassicControllerState.ButtonState.ZR;
		break;
	default:
		is_pressed = false;
		break;
	}
	return ((double)is_pressed);
}

double wm_nunchuck_check_button(double key_code)
{
	// GiiMote^ this = this;
	bool is_pressed = 0;
	switch ((int)key_code)
	{
	case btnC:
		is_pressed = this->wmState->NunchukState.C;
		break;
	case btnZ:
		is_pressed = this->wmState->NunchukState.Z;
		break;
	default:
		is_pressed = false;
		break;
	}
	return ((double)is_pressed);
}

double wm_get_battery()
{
	this->wm->GetBatteryLevel();
	return ( (double)this->wmState->Battery );
}

double wm_nunchuck_xpos()
{
	return ( (double)this->wmState->NunchukState.X );
}

double wm_nunchuck_ypos()
{
	return ( (double)this->wmState->NunchukState.Y );
}

double wm_nunchuck_rawx()
{
	return ( (double)this->wmState->NunchukState.RawX );
}

double wm_nunchuck_rawy()
{
	return ( (double)this->wmState->NunchukState.RawY );
}

double wm_nunchuck_direction()
{
	double yy = wm_nunchuck_ypos();
	double xx = wm_nunchuck_xpos();
	return ( System::Math::Atan( yy/xx ) );
}

double wm_classic_xpos(double stick)
{
	// GiiMote^ this = this;
	if (stick == joyL)
	{
		return (this->wmState->ClassicControllerState.XL);
	}
	else
	{
		return (this->wmState->ClassicControllerState.XR);
	}
}

double wm_classic_ypos(double stick)
{
	if (stick == joyL)
	{
		return (this->wmState->ClassicControllerState.YL);
	}
	else
	{
		return (this->wmState->ClassicControllerState.YR);
	}
}

double wm_classic_rawx(double stick)
{
	if (stick == joyL)
	{
		return (this->wmState->ClassicControllerState.RawXL);
	}
	else
	{
		return (this->wmState->ClassicControllerState.RawXR);
	}
}

double wm_classic_rawy(double stick)
{
	if (stick == joyL)
	{
		return (this->wmState->ClassicControllerState.RawYL);
	}
	else
	{
		return (this->wmState->ClassicControllerState.RawYR);
	}
}

double wm_classic_direction(double stick)
{
	double yy = wm_classic_ypos(stick);
	double xx = wm_classic_xpos(stick);
	return ( System::Math::Atan( yy/xx ) );
}

double wm_classic_trigger_pressure(double trigger)
{
	double pressure = 0;
	if (trigger == btnL || trigger == 0)
	{
		// Left
		pressure = (double)this->wmState->ClassicControllerState.TriggerL;

	}
	else
	{
		if (trigger == btnR || trigger == 1)
		{
			// Right
			pressure = (double)this->wmState->ClassicControllerState.TriggerR;
		}
	}

	return ( pressure );
}

double wm_classic_trigger_raw(double trigger)
{
	double pressure = 0;
	if (trigger == btnL || trigger == 0)
	{
		// Left
		pressure = (double)this->wmState->ClassicControllerState.RawTriggerL;

	}
	else
	{
		if (trigger == btnR || trigger == 1)
		{
			// Right
			pressure = (double)this->wmState->ClassicControllerState.RawTriggerR;
		}
	}

	return ( pressure );
}

double wm_check_extension()
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

double wm_set_rumble(double rumbling)
{
	if (rumbling == 0)
	{
		this->wm->SetRumble(false);
	}
	else
	{
		this->wm->SetRumble(true);
	}
	return (rumbling);
}
double wm_get_rumble()
{
	return ( (double)this->wmState->Rumble );
}

double wm_get_accel_x()
{
	return ( (double)this->wmState->AccelState.X );
}
double wm_get_accel_y()
{
	return ( (double)this->wmState->AccelState.Y );
}
double wm_get_accel_z()
{
	return ( (double)this->wmState->AccelState.Z );
}
double wm_get_accel_rawx()
{
	return ( (double)this->wmState->AccelState.RawX );
}
double wm_get_accel_rawy()
{
	return ( (double)this->wmState->AccelState.RawY );
}
double wm_get_accel_rawz()
{
	return ( (double)this->wmState->AccelState.RawZ );
}

double wm_nunchuck_get_accel_x()
{
	return ( (double)this->wmState->NunchukState.AccelState.X );
}
double wm_nunchuck_get_accel_y()
{
	return ( (double)this->wmState->NunchukState.AccelState.Y );
}
double wm_nunchuck_get_accel_z()
{
	return ( (double)this->wmState->NunchukState.AccelState.Z );
}

double wm_nunchuck_get_accel_rawx()
{
	return ( (double)this->wmState->NunchukState.AccelState.RawX );
}
double wm_nunchuck_get_accel_rawy()
{
	return ( (double)this->wmState->NunchukState.AccelState.RawY );
}
double wm_nunchuck_get_accel_rawz()
{
	return ( (double)this->wmState->NunchukState.AccelState.RawZ );
}

double wm_ir_found_dot(double dot_number)
{
	bool found_dot = 0;
	switch ((int)dot_number)
	{
	case 1:
		found_dot = this->wmState->IRState.Found1;
		break;
	case 2:
		found_dot = this->wmState->IRState.Found2;
		break;
	default:
		break;
	}
	return ( (double)found_dot );
}

double wm_ir_dot_size(double dot_number)
{
	int size = 0;
	switch ((int)dot_number)
	{
	case 1:
		size = this->wmState->IRState.Size1;
		break;
	case 2:
		size = this->wmState->IRState.Size2;
		break;
	default:
		break;
	}
	return ( (double)size );
}

double wm_ir_dot_get_x(double dot_number)
{
	float xx = -1.0;
	switch ((int)dot_number)
	{
	case 1:
		xx = this->wmState->IRState.X1;
		break;
	case 2:
		xx = this->wmState->IRState.X2;
		break;
	default:
		break;
	}
	return ( (double)xx );
}

double wm_ir_dot_get_y(double dot_number)
{
	float yy = -1.0;
	switch ((int)dot_number)
	{
	case 1:
		yy = this->wmState->IRState.Y1;
		break;
	case 2:
		yy = this->wmState->IRState.Y2;
		break;
	default:
		break;
	}
	return ( (double)yy );
}

double wm_ir_dot_get_rawx(double dot_number)
{
	int xx = -1;
	switch ((int)dot_number)
	{
	case 1:
		xx = this->wmState->IRState.RawX1;
		break;
	case 2:
		xx = this->wmState->IRState.RawX2;
		break;
	default:
		break;
	}
	return ( (double)xx );
}

double wm_ir_dot_get_rawy(double dot_number)
{
	int yy = -1;
	switch ((int)dot_number)
	{
	case 1:
		yy = this->wmState->IRState.RawY1;
		break;
	case 2:
		yy = this->wmState->IRState.RawY2;
		break;
	default:
		break;
	}
	return ( (double)yy );
}

double wm_get_calibration_x0()
{
	return ( (double)this->wmState->CalibrationInfo.X0 );
}
double wm_get_calibration_xg()
{
	return ( (double)this->wmState->CalibrationInfo.XG );
}
double wm_get_calibration_y0()
{
	return ( (double)this->wmState->CalibrationInfo.Y0 );
}
double wm_get_calibration_yg()
{
	return ( (double)this->wmState->CalibrationInfo.YG );
}
double wm_get_calibration_z0()
{
	return ( (double)this->wmState->CalibrationInfo.Z0 );
}
double wm_get_calibration_zg()
{
	return ( (double)this->wmState->CalibrationInfo.ZG );
}

double wm_nunchuck_get_calibration_x0()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.X0 );
}
double wm_nunchuck_get_calibration_xg()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.XG );
}
double wm_nunchuck_get_calibration_y0()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.Y0 );
}
double wm_nunchuck_get_calibration_yg()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.YG );
}
double wm_nunchuck_get_calibration_z0()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.Z0 );
}
double wm_nunchuck_get_calibration_zg()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.ZG );
}

double wm_nunchuck_get_calibration_maxx()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.MaxX );
}
double wm_nunchuck_get_calibration_maxy()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.MaxY );
}
double wm_nunchuck_get_calibration_midx()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.MidX );
}
double wm_nunchuck_get_calibration_midy()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.MidY );
}
double wm_nunchuck_get_calibration_minx()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.MinX );
}
double wm_nunchuck_get_calibration_miny()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.MinY );
}

double wm_classic_get_calibration_maxtrigger(double trigger)
{
	double returnValue = -1;
	switch ((int)trigger)
	{
	case btnL:
		returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MaxTriggerL);
		break;
	case btnR:
		returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MaxTriggerR);
		break;
	default:
		break;
	}
	return (returnValue);
}

double wm_classic_get_calibration_mintrigger(double trigger)
{
	double returnValue = -1;
	switch ((int)trigger)
	{
	case btnL:
		returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MinTriggerL);
		break;
	case btnR:
		returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MinTriggerR);
		break;
	default:
		break;
	}

	return (returnValue);
}

double wm_classic_get_calibration_maxx(double joystick)
{
	double returnValue = -1;
	switch ((int)joystick)
	{
	case joyL:
		returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MaxXL);
		break;
	case joyR:
		returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MaxXR);
		break;
	default:
		break;
	}

	return (returnValue);
}

double wm_classic_get_calibration_minx(double joystick)
{
	double returnValue = -1;
	switch ((int)joystick)
	{
	case joyL:
		returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MinXL);
		break;
	case joyR:
		returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MinXR);
		break;
	default:
		break;
	}
	return (returnValue);
}

double wm_classic_get_calibration_midx(double joystick)
{
	double returnValue = -1;
	switch ((int)joystick)
	{
	case joyL:
		returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MidXL);
		break;
	case joyR:
		returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MidXR);
		break;
	default:
		break;
	}

	return (returnValue);
}

double wm_classic_get_calibration_midy(double joystick)
{
	double returnValue = -1;
	switch ((int)joystick)
	{
	case joyL:
		returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MidYL);
		break;
	case joyR:
		returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MidYR);
		break;
	default:
		break;
	}
	return (returnValue);
}

double wm_classic_get_calibration_maxy(double joystick)
{
	double returnValue = -1;
	switch ((int)joystick)
	{
	case joyL:
		returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MaxYL);
		break;
	case joyR:
		returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MaxYR);
		break;
	default:
		break;
	}
	return (returnValue);
}

double wm_classic_get_calibration_miny(double joystick)
{
	double returnValue = -1;

	switch ((int)joystick)
	{
	case joyL:
		returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MinYL);
		break;
	case joyR:
		returnValue = double(this->wmState->ClassicControllerState.CalibrationInfo.MinYR);
		break;
	default:
		break;
	}
	return (returnValue);
}

double wm_bin_read_byte(double address)
{
	double value = -1;
	value = double( (this->wm->ReadData((int)address,1))[0] );
	return value;
}

double wm_bin_write_byte(double address, double value)
{
	this->wm->WriteData((int)address,(unsigned char)value);
	return (1);
}

	};
}
