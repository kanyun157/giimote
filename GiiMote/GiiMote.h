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

/// <summary>Functionality to communicate with a Nintendo Wii Remote from Game Maker</summary>
namespace GiiMoteLib {

	/// <summary>The class embodying GiiMote</summary>
	public ref class GiiMote
	{
	public:
		/// <summary>The Wii Remote</summary>
		Wiimote^ wm;
		/// <summary>The current Wii Remote state</summary>
		WiimoteState^ wmState;

		/// <summary>Joystick dead-zone value</summary>
		double joystick_dead_zone;


		/// <summary>Trigger dead-zone value</summary>
		double trigger_dead_zone;

		/// <summary>Accelerometer dead-zone values</summary>
		/// <remarks>
		/// <list type="bullet">
		///     <listheader>
		///         <term>Index</term>
		///         <description>Dead Zone</description>
		///     </listheader>
		///     <item>
		///			<term>0</term>
		///         <description>Wii Remote X-axis</description>
		///     </item>
		///     <item>
		///			<term>1</term>
		///         <description>Wii Remote Y-axis</description>
		///     </item>
		///     <item>
		///			<term>2</term>
		///         <description>Wii Remote Z-axis</description>
		///     </item>
		///     <item>
		///			<term>3</term>
		///         <description>Nunchuck X-axis</description>
		///     </item>
		///     <item>
		///			<term>4</term>
		///         <description>Nunchuck Y-axis</description>
		///     </item>
		///     <item>
		///			<term>5</term>
		///         <description>Nunchuck Z-axis</description>
		///     </item>
		/// </list>
		/// </remarks>
		cli::array<double>^ accel_dead_zone;
		

		 //////////////////
		// Constructors //
	   //////////////////
	public:
		/// <summary>Default constructor</summary>
		GiiMote()
		{
			wm = gcnew Wiimote;

			// Default dead-zones to 0
			this->accel_dead_zone->Resize(this->accel_dead_zone, 6);
			for(int i = 0; i <= 5; i++)
			{
				this->accel_dead_zone[i] = 0;
			}
			this->joystick_dead_zone = 0;
			this->trigger_dead_zone = 0;
		}
		/// <summary>Default destructor</summary>
		/// <remarks>
		/// The GiiMote destructor (~GiiMote) is not bound late.
		/// If you introduce a class into this library which inherits from GiiMote
		/// you will need to make the destructor bind late using the keyword "virtual."
		/// </remarks>
		~GiiMote()
		{
			// Cleanup after sloppy users.
			// I think WiimoteLib does this for you as well.
			if (wm_connected())
			{
				wm_disconnect();
			}
			// Do I need to destruct these here?
			// delete (this->wm->WiimoteChanged);
			// delete (this->wm->WiimoteExtensionChanged);
			// delete (this->IRCalibration);
			delete (wm);
		}

		/// <summary>Wii Remote extension state change event</summary>
		/// <param name="sender">Object sending the event</param>
		/// <param name="args">Current extension status</param>
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

		/// <summary>Wii Remote state change event</summary>
		/// <param name="sender">Object sending the event</param>
		/// <param name="args">Current Wii Remote state</param>
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

		// Joysticks (General)
		double joystick_direction(double xx, double yy);
		double joystick_pressure(double xx, double yy);
		double wm_set_joystick_dead_zone(double val);
		double wm_get_joystick_dead_zone();
		
		// Joysticks (Nunchuck)
		double wm_nunchuck_xpos();
		double wm_nunchuck_ypos();
		double wm_nunchuck_direction();
		double wm_nunchuck_pressure();
		double wm_nunchuck_rawx();
		double wm_nunchuck_rawy();

		// Joysticks (Classic Controller)
		double wm_classic_xpos(double stick);
		double wm_classic_ypos(double stick);
		double wm_classic_rawx(double stick);
		double wm_classic_rawy(double stick);
		double wm_classic_direction(double stick);
		double wm_classic_pressure(double stick);

		// Triggers (General)
		double wm_set_trigger_dead_zone(double val);
		double wm_get_trigger_dead_zone();

		// Triggers (Classic Controller)
		double wm_classic_trigger_pressure(double trigger);
		double wm_classic_trigger_raw(double trigger);

////////////////////////////////////////////
// Accelerometers and IR
////////////////////////////////////////////
		// Accelerometer (General)
		double wm_calc_accel(float accel, int dz_index);

		// Accelerometer (Wii Remote)
		double wm_get_accel_x();
		double wm_get_accel_y();
		double wm_get_accel_z();
		double wm_get_accel_rawx();
		double wm_get_accel_rawy();
		double wm_get_accel_rawz();
		double wm_set_accel_dead_zone_x(double val);
		double wm_set_accel_dead_zone_y(double val);
		double wm_set_accel_dead_zone_z(double val);
		double wm_get_accel_dead_zone_x();
		double wm_get_accel_dead_zone_y();
		double wm_get_accel_dead_zone_z();

		// Accelerometer (Nunchuck)
		double wm_nunchuck_get_accel_x();
		double wm_nunchuck_get_accel_y();
		double wm_nunchuck_get_accel_z();
		double wm_nunchuck_get_accel_rawx();
		double wm_nunchuck_get_accel_rawy();
		double wm_nunchuck_get_accel_rawz();
		double wm_nunchuck_set_accel_dead_zone_x(double val);
		double wm_nunchuck_set_accel_dead_zone_y(double val);
		double wm_nunchuck_set_accel_dead_zone_z(double val);
		double wm_nunchuck_get_accel_dead_zone_x();
		double wm_nunchuck_get_accel_dead_zone_y();
		double wm_nunchuck_get_accel_dead_zone_z();

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

////////////////////////////////////////////
// Calibration
////////////////////////////////////////////
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
		double wm_set_calibration_y0(double val);
		double wm_set_calibration_yg(double val);
		double wm_set_calibration_z0(double val);
		double wm_set_calibration_zg(double val);

////////////////////////////////////////////
// Mii Functions
////////////////////////////////////////////
		double wm_mii_data_dump(System::String^ fName,double miiBlock, double miiNumber);
		double wm_mii_data_inject(System::String^ fName,double miiBlock, double miiNumber);
		double wm_mii_update_crc(System::String^ fName);
		cli::array<unsigned char,1>^ wm_mii_data_update(cli::array<unsigned char,1>^ miiData);

	};

}
