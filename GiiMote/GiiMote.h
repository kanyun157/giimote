// GiiMote.h

#pragma once
///////////////////////
// Define Constants //
/////////////////////

#define export extern "C" __declspec( dllexport ) /*__cdecl*/

#define extClassic 1
#define extNunchuck 2
#define extNone 0
#define extUnknown -1

// Wii Remote specific buttons:
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

// Classic Specific
#define btnX 11
#define btnY 12
#define btnL 13
#define btnR 14
#define btnZL 15
#define btnZR 16

#define joyL 0
#define joyR 1

// Nunchuck Specific
#define btnC 19
#define btnZ 20

// Report Types
#define rtAuto 0
#define rtButtons 1
#define	rtButtonsAccel 2
#define rtButtonsExtension 3
#define rtExtensionAccel 4
#define rtIRAccel 5
#define rtIRExtensionAccel 6
#define rtReadData 7
#define rtStatus 8

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
		/// <summary>The current state of the Wii Remote</summary>
		WiimoteState^ wmState;

		/// <summary>The height of the current display</summary>
		int display_height;
		/// <summary>The width of the current display</summary>
		int display_width;

		/// <summary>The X position on the screen the Wii Remote is pointing at</summary>
		int ir_screen_x;
		/// <summary>The Y position on the screen the Wii Remote is pointing at</summary>
		int ir_screen_y;
		
		// Dead Zone's
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

		/// <summary>The report type of the Wii Remote</summary>
		int report_type;

		/// <summary>The change in an infrared point's x value</summary>
		cli::array<float>^ ir_last_x;
		/// <summary>The change in an infrared point's y value</summary>
		cli::array<float>^ ir_last_y;
		/// <summary>The change in an infrared point's raw x value</summary>
		cli::array<int>^ ir_last_rawx;
		/// <summary>The change in an infrared point's raw y value</summary>
		cli::array<int>^ ir_last_rawy;
		/// <summary>The change in the infrared midpoint's x value</summary>
		float ir_last_midx;
		/// <summary>The change in the infrared midpoint's y value</summary>
		float ir_last_midy;
		/// <summary>The change in the infrared midpoint's raw x value</summary>
		int ir_last_rawmidx;
		/// <summary>The change in the infrared midpoint's raw y value</summary>
		int ir_last_rawmidy;

		 //////////////////
		// Constructors //
	   //////////////////
	public:
		/// <summary>Default constructor</summary>
		/// <returns>Nothing</returns>
		GiiMote()
		{
			this->wm = gcnew Wiimote;

			ir_last_x = gcnew cli::array<float>(4);
			ir_last_y = gcnew cli::array<float>(4);
			ir_last_rawx = gcnew cli::array<int>(4);
			ir_last_rawy = gcnew cli::array<int>(4);
			ir_last_midx = 0;
			ir_last_midy = 0;
			ir_last_rawmidx = 0;
			ir_last_rawmidy = 0;

			// Default dead-zones to 0
			this->accel_dead_zone->Resize(this->accel_dead_zone, 6);
			for(int i = 0; i <= 5; i++)
			{
				this->accel_dead_zone[i] = 0;
			}
			this->joystick_dead_zone = this->trigger_dead_zone = 0;

			// Get the width and height of the primary display
			this->display_height = System::Windows::Forms::Screen::PrimaryScreen->Bounds.Height;
			this->display_width	 = System::Windows::Forms::Screen::PrimaryScreen->Bounds.Width;

			// Set the current X and Y position on the display to 0
			this->ir_screen_x = this->ir_screen_y = 0;

			// Default the report type to rt_auto
			this->report_type = rtAuto;
		}
		/// <summary>Default destructor</summary>
		/// <remarks>
		/// The GiiMote destructor (~GiiMote) is not bound late.
		/// If you introduce a class into this library which inherits from GiiMote
		/// you will need to make the destructor bind late using the keyword "virtual."
		/// </remarks>
		/// <returns>Nothing</returns>
		~GiiMote()
		{
			wm_disconnect();
			delete ir_last_x;
			delete ir_last_y;
			delete ir_last_rawx;
			delete ir_last_rawy;
			delete (wm);
		}

		/// <summary>Wii Remote extension state change event</summary>
		/// <param name="sender">Object sending the event</param>
		/// <param name="args">Current extension status</param>
		void wm_OnWiimoteExtensionChanged(System::Object^ sender, WiimoteExtensionChangedEventArgs^ args)
		{
			if (this->report_type == rtAuto)
			{
				wm_set_report_type(rtAuto);
			}
		}

		/// <summary>Wii Remote state change event</summary>
		/// <param name="sender">Object sending the event</param>
		/// <param name="args">Current Wii Remote state</param>
		void wm_OnWiimoteChanged(System::Object^ sender, WiimoteChangedEventArgs^ args)
		{
			this->wmState = args->WiimoteState;

			if (this->wmState->IRState.Found1 && this->wmState->IRState.Found2)
			{
				this->ir_screen_x = display_width - (int)domain_rescale(this->wmState->IRState.RawMidX, 0, 1023, 0, display_width);
				this->ir_screen_y = (int)domain_rescale(this->wmState->IRState.RawMidY, 0, 767, 0, display_height);
			}
			else
			{
				if (this->wmState->IRState.Found1)
				{
					this->ir_screen_x -= (int)domain_rescale(wm_ir_dot_get_delta_rawx(1), 0, 1023, 0, display_width);
					this->ir_screen_y -= (int)domain_rescale(wm_ir_dot_get_delta_rawy(1), 0, 767, 0, display_height);
				}
				else
				{
					if (this->wmState->IRState.Found2)
					{
						this->ir_screen_x -= (int)domain_rescale(wm_ir_dot_get_delta_rawx(2), 0, 1023, 0, display_width);
						this->ir_screen_y -= (int)domain_rescale(wm_ir_dot_get_delta_rawy(2), 0, 767, 0, display_height);
					}
					else
					{
						// When the sensor bar is not visible we have a few options...
						// The Wii simply hides the cursor until the IR points are
						// visible again. However, we could also double integrate
						// the accelerometer data to estimate the change in
						// position. However, if the IR is not visible that most likely
						// means we are not facing the screen anyways, and integrating the acceleration
						// is not very accurate.
						this->ir_screen_x = -1;
						this->ir_screen_y = -1;
					}
				}
			}

			ir_last_x[0] = this->wmState->IRState.X1;
			ir_last_x[1] = this->wmState->IRState.X2;
			ir_last_x[2] = this->wmState->IRState.X3;
			ir_last_x[3] = this->wmState->IRState.X4;

			ir_last_y[0] = this->wmState->IRState.Y1;
			ir_last_y[1] = this->wmState->IRState.Y2;
			ir_last_y[2] = this->wmState->IRState.Y3;
			ir_last_y[3] = this->wmState->IRState.Y4;


			ir_last_rawx[0] = this->wmState->IRState.RawX1;
			ir_last_rawx[1] = this->wmState->IRState.RawX2;
			ir_last_rawx[2] = this->wmState->IRState.RawX3;
			ir_last_rawx[3] = this->wmState->IRState.RawX4;

			ir_last_rawy[0] = this->wmState->IRState.RawY1;
			ir_last_rawy[1] = this->wmState->IRState.RawY2;
			ir_last_rawy[2] = this->wmState->IRState.RawY3;
			ir_last_rawy[3] = this->wmState->IRState.RawY4;

			ir_last_midx = this->wmState->IRState.MidX;
			ir_last_midy = this->wmState->IRState.MidX;
			ir_last_rawmidx = this->wmState->IRState.RawMidX;
			ir_last_rawmidy = this->wmState->IRState.RawMidX;
		}

public:
////////////////////////////////////////////
// Wii Remote Functions
////////////////////////////////////////////
		// Connection Functions
		double wm_connect();
		double wm_exists();
		double wm_set_write_method(double alt_write_method);
		double wm_connected();
		double wm_disconnect();
		double wm_set_report_type(double report_type);
		double wm_get_report_type();

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

		// Orientation
		double wm_get_roll();
		double wm_get_pitch();
		double wm_get_yaw();
		double wm_get_altitude();

		// Reading/Writing
		double wm_bin_read_byte(double address);
		double wm_bin_write_byte(double address, double value);

////////////////////////////////////////////
// Mathematical Functions
////////////////////////////////////////////
		double in_domain(double x, double d1, double d2);
		double domain_rescale(double val, double minin, double maxin, double minout, double maxout);

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
		double wm_ir_dot_get_delta_x(double dot_number);
		double wm_ir_dot_get_delta_y(double dot_number);
		double wm_ir_dot_get_delta_rawx(double dot_number);
		double wm_ir_dot_get_delta_rawy(double dot_number);
		double wm_ir_dot_get_delta_midx();
		double wm_ir_dot_get_delta_midy();
		double wm_ir_dot_get_delta_rawmidx();
		double wm_ir_dot_get_delta_rawmidy();
		double wm_ir_display_get_x();
		double wm_ir_display_get_y();

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
