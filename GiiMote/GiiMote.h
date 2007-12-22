// GiiMote.h

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
		Wiimote^ wm;
		WiimoteState^ wmState;
		// bool connected;
		double dead_zone;
		double trigger_dead_zone;
		double accel_dead_zone;
		cli::array<double>^ IRCalibration;
		

		 //////////////////
		// Constructors //
	   //////////////////
	public:
		GiiMote()
		{
			wm = gcnew Wiimote;
			// this->connected = false;
			this->dead_zone = 0;
			IRCalibration->Resize(IRCalibration,5);
			IRCalibration = gcnew cli::array<double>(5);
		}
		// Developers Note:
		// The GiiMote destructor (~GiiMote) is not bound late.
		// If you introduce a subclass into this library which inherits from GiiMote
		// you will need to make the destructor bind late using the keyword "virtual"
		// It is not late bound here to avoid the small amount of overhead introduced by late binding.
		~GiiMote()
		{
			// Cleanup after sloppy users.
			// Actually, I think the Wiimote class does this for you as well.
			if (wm_connected())
			{
				wm_disconnect();
			}
			// Do I need to destruct these here?
			delete this->wm->WiimoteChanged;
			delete this->wm->WiimoteExtensionChanged;
			delete (wm);
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

public:
////////////////////////////////////////////
// Wii Remote Functions
////////////////////////////////////////////
		// Connection Functions
		double wm_connect();
		double wm_exists();
		double wm_set_write_method(double alt_write_method);
		double wm_connected(void);
		double wm_disconnect(void);
		
		double wm_set_dead_zone(double num, double type);

		// LED Functions
		double wm_get_led(double led_num);
		double wm_set_leds(double led1, double led2, double led3, double led4);
		double wm_set_leds_int(double val);

		// Status
		double wm_get_battery();
		double wm_get_status();
		double wm_check_extension();
		double wm_set_rumble(double rumbling);
		double wm_get_rumble();

		// Reading/Writing
		double wm_bin_read_byte(double address);
		double wm_bin_write_byte(double address, double value);

////////////////////////////////////////////
// Mathematical Functions
////////////////////////////////////////////
		double in_domain(double x, double d1,double d2);

////////////////////////////////////////////
// Buttons, Joysticks, and Triggers
////////////////////////////////////////////
		// Buttons
		double wm_nunchuck_check_button(double key_code);
		double wm_classic_check_button(double key_code);
		double wm_check_button(double key_code);
		
		// Joysticks (Nunchuck)
		double wm_nunchuck_xpos();
		double wm_nunchuck_ypos();
		double wm_nunchuck_direction();
		double wm_nunchuck_rawx();
		double wm_nunchuck_rawy();

		// Joysticks (General)
		double joystick_direction(double xx, double yy);

		// Joysticks (Classic Controller)
		double wm_classic_xpos(double stick);
		double wm_classic_ypos(double stick);
		double wm_classic_rawx(double stick);
		double wm_classic_rawy(double stick);
		double wm_classic_direction(double stick);

		// Triggers (Classic Controller)
		double wm_classic_trigger_pressure(double trigger);
		double wm_classic_trigger_raw(double trigger);

////////////////////////////////////////////
// Accelerometers and IR
////////////////////////////////////////////
		// Accelerometer (General)
		double wm_calc_accel(float accel);

		// Accelerometer (Wii Remote)
		double wm_get_accel_x();
		double wm_get_accel_y();
		double wm_get_accel_z();
		double wm_get_accel_rawx();
		double wm_get_accel_rawy();
		double wm_get_accel_rawz();

		// Accelerometer (Nunchuck)
		double wm_nunchuck_get_accel_x();
		double wm_nunchuck_get_accel_y();
		double wm_nunchuck_get_accel_z();
		double wm_nunchuck_get_accel_rawx();
		double wm_nunchuck_get_accel_rawy();
		double wm_nunchuck_get_accel_rawz();

		// Infrared
		double wm_ir_found_dot(double dot_number);
		double wm_ir_dot_size(double dot_number);
		double wm_ir_dot_get_x(double dot_number);
		double wm_ir_dot_get_y(double dot_number);
		double wm_ir_dot_get_rawx(double dot_number);
		double wm_ir_dot_get_rawy(double dot_number);
		double wm_ir_dot_get_midx();
		double wm_ir_dot_get_midy();
		double wm_ir_dot_get_rawmidx();
		double wm_ir_dot_get_rawmidy();
		//double wm_ir_display_get_x(double display_width);
		//double wm_ir_display_get_y(double display_height);

////////////////////////////////////////////
// Calibration
////////////////////////////////////////////
		// IR Set
		// double wm_ir_set_calibration_right(double val);
		// double wm_ir_set_calibration_left(double val);
		// double wm_ir_set_calibration_top(double val);
		// double wm_ir_set_calibration_bottom(double val);
		// double wm_ir_sensor_bar_set_pos(double pos);
		// IR Get
		// double wm_ir_get_calibration_right();
		// double wm_ir_get_calibration_left();
		// double wm_ir_get_calibration_top();
		// double wm_ir_get_calibration_bottom();
		// double wm_ir_sensor_bar_get_pos();
		// Nunchuck Get
		double wm_nunchuck_get_calibration_x0();
		double wm_nunchuck_get_calibration_xg();
		double wm_nunchuck_get_calibration_y0();
		double wm_nunchuck_get_calibration_yg();
		double wm_nunchuck_get_calibration_z0();
		double wm_nunchuck_get_calibration_zg();
		double wm_nunchuck_get_calibration_maxx();
		double wm_nunchuck_get_calibration_maxy();
		double wm_nunchuck_get_calibration_midx();
		double wm_nunchuck_get_calibration_midy();
		double wm_nunchuck_get_calibration_minx();
		double wm_nunchuck_get_calibration_miny();
		// Nunchuck Set
		double wm_nunchuck_set_calibration_x0(double val);
		double wm_nunchuck_set_calibration_xg(double val);
		double wm_nunchuck_set_calibration_y0(double val);
		double wm_nunchuck_set_calibration_yg(double val);
		double wm_nunchuck_set_calibration_z0(double val);
		double wm_nunchuck_set_calibration_zg(double val);
		double wm_nunchuck_set_calibration_maxx(double val);
		double wm_nunchuck_set_calibration_maxy(double val);
		double wm_nunchuck_set_calibration_midx(double val);
		double wm_nunchuck_set_calibration_midy(double val);
		double wm_nunchuck_set_calibration_minx(double val);
		double wm_nunchuck_set_calibration_miny(double val);
		// Classic Controller Get
		double wm_classic_get_calibration_maxtrigger(double trigger);
		double wm_classic_get_calibration_mintrigger(double trigger);
		double wm_classic_get_calibration_maxx(double joystick);
		double wm_classic_get_calibration_minx(double joystick);
		double wm_classic_get_calibration_midx(double joystick);
		double wm_classic_get_calibration_midy(double joystick);
		double wm_classic_get_calibration_maxy(double joystick);
		double wm_classic_get_calibration_miny(double joystick);
		// Classic Controller Set
		double wm_classic_set_calibration_maxtrigger(double trigger, double val);
		double wm_classic_set_calibration_mintrigger(double trigger, double val);
		double wm_classic_set_calibration_maxx(double joystick, double val);
		double wm_classic_set_calibration_minx(double joystick, double val);
		double wm_classic_set_calibration_midx(double joystick, double val);
		double wm_classic_set_calibration_midy(double joystick, double val);
		double wm_classic_set_calibration_maxy(double joystick, double val);
		double wm_classic_set_calibration_miny(double joystick, double val);
		// Wii Remote Get
		double wm_get_calibration_x0();
		double wm_get_calibration_xg();
		double wm_get_calibration_y0();
		double wm_get_calibration_yg();
		double wm_get_calibration_z0();
		double wm_get_calibration_zg();
		// Wii Remote Set
		double wm_set_calibration_x0(double val);
		double wm_set_calibration_xg(double val);
		double wm_get_calibration_y0(double val);
		double wm_get_calibration_yg(double val);
		double wm_get_calibration_z0(double val);
		double wm_get_calibration_zg(double val);

////////////////////////////////////////////
// Mii Functions
////////////////////////////////////////////
		double wm_mii_data_dump(System::String^ fName,double miiBlock, double miiNumber);
		double wm_mii_data_inject(System::String^ fName,double miiBlock, double miiNumber);
		double wm_mii_update_crc(System::String^ fName);
		cli::array<unsigned char,1>^ wm_mii_data_update(cli::array<unsigned char,1>^ miiData);

	};

}
