// GiiMote.h

#pragma once
///////////////////////
// Define Constants //
/////////////////////

#define export extern "C" __declspec( dllexport ) /*__cdecl*/

#define extClassic 1
#define extNunchuck 2
#define extGuitar 3
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

// Guitar Specific
#define btnBlue 21
#define btnGreen 22
#define btnOrange 23
#define btnRed 24
#define btnYellow 25
#define btnStrumDown 26
#define btnStrumUp 27

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
		/// <summary>A collection of all the Wii Remotes attatched to the system</summary>
		WiimoteCollection^ wc;
		/// <summary>The number of the current Wii Remote</summary>
		int wmIndex;
		/// <summary>The GUID of the current Wii Remote</summary>
		System::Guid^ wmGUID;

		/// <summary>The height of the current display</summary>
		int display_height;
		/// <summary>The width of the current display</summary>
		int display_width;

		/// <summary>The position on the screen the Wii Remote is pointing at</summary>
		cli::array<Point>^ ir_screen_pos;
		
		// Dead Zone's
		/// <summary>Joystick dead-zone value</summary>
		cli::array<double>^ joystick_dead_zone;
		/// <summary>Trigger dead-zone value</summary>
		cli::array<double>^ trigger_dead_zone;
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
		cli::array<double, 2>^ accel_dead_zone;

		/// <summary>The report type of the Wii Remote</summary>
		cli::array<int>^ report_type;
		/// <summary>Report continuously or on update?</summary>
		cli::array<bool>^ continuous;
		/// <summary>The IR camera's sensitivity</summary>
		cli::array<IRSensitivity>^ ir_sensitivity;

		/// <summary>The change in an infrared point's coordinates</summary>
		cli::array<PointF, 2>^ ir_last_pos;
		/// <summary>The change in an infrared point's raw coordinates</summary>
		cli::array<Point, 2>^ ir_last_raw_pos;
		/// <summary>The change in the infrared midpoint's coordinates</summary>
		cli::array<PointF>^ ir_last_mid_pos;
		/// <summary>The change in the infrared midpoint's raw coordinates</summary>
		cli::array<Point>^ ir_last_rawmid_pos;

		 //////////////////
		// Constructors //
	   //////////////////
	public:
		/// <summary>Default constructor</summary>
		/// <returns>Nothing</returns>
		GiiMote()
		{
			this->wmIndex = 0;
			this->wc = gcnew WiimoteCollection();
			if (this->wc->Count > 0)
			{
				this->wmGUID = this->wc[wmIndex]->ID;
			}
			
			// Create all arrays on the heap
			ir_screen_pos = gcnew cli::array<Point>(0);
			joystick_dead_zone = gcnew cli::array<double>(0);
			trigger_dead_zone = gcnew cli::array<double>(0);
			accel_dead_zone = gcnew cli::array<double, 2>(0, 6);
			report_type = gcnew cli::array<int>(0);
			continuous = gcnew cli::array<bool>(0);
			ir_sensitivity = gcnew cli::array<IRSensitivity>(0);
			ir_last_pos = gcnew cli::array<PointF, 2>(0, 4);
			ir_last_raw_pos = gcnew cli::array<Point, 2>(0, 4);
			ir_last_mid_pos = gcnew cli::array<PointF>(0);
			ir_last_rawmid_pos = gcnew cli::array<Point>(0);

			wm_find_all();

			// Get the width and height of the primary display
			this->display_height = System::Windows::Forms::Screen::PrimaryScreen->Bounds.Height;
			this->display_width	 = System::Windows::Forms::Screen::PrimaryScreen->Bounds.Width;
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
			wm_disconnect_all();
			delete ir_screen_pos;
			delete joystick_dead_zone;
			delete trigger_dead_zone;
			delete accel_dead_zone;
			delete report_type;
			delete continuous;
			delete ir_sensitivity;
			delete ir_last_pos;
			delete ir_last_raw_pos;
			delete ir_last_mid_pos;
			delete ir_last_rawmid_pos;
			delete (wc);
		}

		/// <summary>Wii Remote extension state change event</summary>
		/// <param name="sender">Object sending the event</param>
		/// <param name="args">Current extension status</param>
		void wm_OnWiimoteExtensionChanged(System::Object^ sender, WiimoteExtensionChangedEventArgs^ args)
		{
			// When an extension is plugged in or unplugged all reporting stops
			// until we update the report type
			wm_set_report_type(this->report_type[this->wmIndex], this->continuous[this->wmIndex]);
		}

		/// <summary>Wii Remote state change event</summary>
		/// <param name="sender">Object sending the event</param>
		/// <param name="args">Current Wii Remote state</param>
		void wm_OnWiimoteChanged(System::Object^ sender, WiimoteChangedEventArgs^ args)
		{
			int Index = -1;
			int Hash = args->WiimoteState->GetHashCode();
			for (int i = 0; i < this->wc->Count; i++)
			{
				int tHash;
				tHash = this->wc[i]->WiimoteState->GetHashCode();
				if (tHash == Hash)
				{
					Index = i;
					break;
				}
			}

			if (Index = -1)
			{
				throw "It's still -1. Do it again.";
			}

			if (args->WiimoteState->IRState.IRSensors[0].Found && args->WiimoteState->IRState.IRSensors[1].Found)
			{
				this->ir_screen_pos[Index].X = display_width - (int)domain_rescale(this->wc[Index]->WiimoteState->IRState.RawMidpoint.X, 0, 1023, 0, display_width);
				this->ir_screen_pos[Index].Y = (int)domain_rescale(this->wc[Index]->WiimoteState->IRState.RawMidpoint.Y, 0, 767, 0, display_height);
			}
			else
			{
				if (args->WiimoteState->IRState.IRSensors[0].Found)
				{
					this->ir_screen_pos[Index].X -= (int)domain_rescale(wm_ir_dot_get_delta_rawx(1), 0, 1023, 0, display_width);
					this->ir_screen_pos[Index].Y -= (int)domain_rescale(wm_ir_dot_get_delta_rawy(1), 0, 767, 0, display_height);
				}
				else
				{
					if (this->wc[Index]->WiimoteState->IRState.IRSensors[1].Found)
					{
						this->ir_screen_pos[Index].X -= (int)domain_rescale(wm_ir_dot_get_delta_rawx(2), 0, 1023, 0, display_width);
						this->ir_screen_pos[Index].Y -= (int)domain_rescale(wm_ir_dot_get_delta_rawy(2), 0, 767, 0, display_height);
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
						this->ir_screen_pos[Index].X = -1;
						this->ir_screen_pos[Index].Y = -1;
					}
				}
			}

			for(int i = 0; i < 4; i++)
			{
				ir_last_pos[Index, i].X = this->wc[Index]->WiimoteState->IRState.IRSensors[i].Position.X;
				ir_last_pos[Index, i].Y = this->wc[Index]->WiimoteState->IRState.IRSensors[i].Position.Y;
				ir_last_raw_pos[Index, i].X = this->wc[Index]->WiimoteState->IRState.IRSensors[i].RawPosition.X;
				ir_last_raw_pos[Index, i].Y = this->wc[Index]->WiimoteState->IRState.IRSensors[i].RawPosition.Y;
			}

			ir_last_mid_pos[Index].X = this->wc[Index]->WiimoteState->IRState.Midpoint.X;
			ir_last_mid_pos[Index].Y = this->wc[Index]->WiimoteState->IRState.Midpoint.Y;
			ir_last_rawmid_pos[Index].X = this->wc[Index]->WiimoteState->IRState.RawMidpoint.X;
			ir_last_rawmid_pos[Index].Y = this->wc[Index]->WiimoteState->IRState.RawMidpoint.Y;
		}

public:
////////////////////////////////////////////
// Wii Remote Functions
////////////////////////////////////////////
		// Connection Functions
		double  wm_find_all();
		double  wm_set_wm(double wm);
		double  wm_set_wm(System::String^ wm);
		double  wm_connect();
		double  wm_connect_all();
		double  wm_exists();
		double  wm_connected();
		double  wm_disconnect();
		double  wm_disconnect_all();
		double  wm_set_report_type(double report_type, double continuous);
		double  wm_get_report_type();
		double  wm_get_report_continuous();
		double  wm_get_id();
		String^ wm_get_guid();
		double  wm_get_index(System::String^ guid);
		double  wm_get_index(double id);

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
		double wm_get_moving();
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
		double wm_guitar_check_button(double key_code);
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

		// Joysticks (Guitar)
		double wm_guitar_xpos();
		double wm_guitar_ypos();
		double wm_guitar_direction();
		double wm_guitar_pressure();
		double wm_guitar_rawx();
		double wm_guitar_rawy();

		// Triggers (General)
		double wm_set_trigger_dead_zone(double val);
		double wm_get_trigger_dead_zone();

		// Triggers (Classic Controller)
		double wm_classic_trigger_pressure(double trigger);
		double wm_classic_trigger_raw(double trigger);

		// Whammy Bar (Guitar)
		double wm_guitar_whammybar_pos();
		double wm_guitar_whammybar_rawpos();

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
		double wm_ir_set_sensitivity(double sensitivity);
		double wm_ir_get_sensitivity();
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
