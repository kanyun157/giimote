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

		GiiMote()
		{
			System::Windows::Forms::MessageBox::Show("Start");
			GiiMote::dll_instance = this;
			System::Windows::Forms::MessageBox::Show("Middle");
			this->wm = gcnew Wiimote;
			System::Windows::Forms::MessageBox::Show("End");
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
			// delete dll_instance->wm->OnWiimoteChanged;
			// delete dll_instance->wm->OnWiimoteExtensionChanged;
			delete dll_instance->wm;
			GiiMote::created = 0;
		}

		void wm_OnWiimoteExtensionChanged(System::Object^ sender, WiimoteExtensionChangedEventArgs^ args)
		{
			if(args->Inserted)
			{
				dll_instance->wm->SetReportType(Wiimote::InputReport::IRExtensionAccel, true);
			}
			else
			{
				dll_instance->wm->SetReportType(Wiimote::InputReport::IRAccel, true);
			}
		}

		void wm_OnWiimoteChanged(System::Object^ sender, WiimoteChangedEventArgs^ args)
		{
			dll_instance->wmState = args->WiimoteState;
		}

		static void gm_create()
		{
			System::Windows::Forms::MessageBox::Show("CC");
			if (!GiiMote::created)
			{
				System::Windows::Forms::MessageBox::Show("C");
				gcnew GiiMote();
				// GiiMote::dll_instance->created = true;
				System::Windows::Forms::MessageBox::Show("created: "+GiiMote::created.ToString());
			}
		}

		static void gm_destroy()
		{
			if (GiiMote::created)
			{
				System::Windows::Forms::MessageBox::Show("D:");
				delete GiiMote::dll_instance;
				System::Windows::Forms::MessageBox::Show("Destroyed:");
			}
		}

		static void gm_connect(bool use_alt_write_method)
		{
			// System::Windows::Forms::MessageBox::Show(dll_instance->connected.ToString());
			if (!GiiMote::connected)
			{
				GiiMote::dll_instance->wm->AltWriteMethod = use_alt_write_method;
				dll_instance->wm->Connect();
				dll_instance->wm->SetReportType(Wiimote::InputReport::IRAccel, true);
				dll_instance->wm->OnWiimoteChanged += (gcnew WiimoteChangedEventHandler(dll_instance,&GiiMote::wm_OnWiimoteChanged));
				dll_instance->wm->OnWiimoteExtensionChanged += (gcnew WiimoteExtensionChanged(dll_instance,&GiiMote::wm_OnWiimoteExtensionChanged));
				dll_instance->wm->SetLEDs(false, false, false, false);
				dll_instance->wm->GetBatteryLevel();
				GiiMote::connected = 1;
			}
		}

		static void gm_disconnect()
		{
			if (GiiMote::connected)
			{
				dll_instance->wm->Disconnect();
				GiiMote::connected = false;
			}
		}

		 //////////////////
		//  Functions   //
	   //////////////////

	};
}
