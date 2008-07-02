// GiiMote.h

#pragma once
///////////////////////
// Define Constants //
/////////////////////

const int extClassic		= 1;
const int extNunchuck		= 2;
const int extGuitar			= 3;
const int extBalanceBoard	= 4;
const int extNone			= 0;
const int extUnknown		= -1;

// Wii Remote specific buttons:
const int btnA		= 0;
const int btnB		= 1;
const int btnUp		= 2;
const int btnDown	= 3;
const int btnRight	= 4;
const int btnLeft	= 5;
const int btnOne	= 6;
const int btnTwo	= 7;
const int btnPlus	= 8;
const int btnMinus	= 9;
const int btnHome	= 10;

// Classic Specific
const int btnX	= 11;
const int btnY	= 12;
const int btnL	= 13;
const int btnR	= 14;
const int btnZL = 15;
const int btnZR = 16;

const int joyL = 0;
const int joyR = 1;

// Nunchuck Specific
const int btnC = 19;
const int btnZ = 20;

// Guitar Specific
const int btnBlue		= 21;
const int btnGreen		= 22;
const int btnOrange		= 23;
const int btnRed		= 24;
const int btnYellow		= 25;
const int btnStrumDown	= 26;
const int btnStrumUp	= 27;

// Balance Board Sensors
const int btmLeft	= 0;
const int btmRight	= 1;
const int topLeft	= 2;
const int topRight	= 3;

// Report Types
const int rtAuto				= 0;
const int rtButtons				= 1;
const int rtButtonsAccel		= 2;
const int rtButtonsExtension	= 3;
const int rtExtensionAccel		= 4;
const int rtIRAccel				= 5;
const int rtIRExtensionAccel	= 6;
const int rtReadData			= 7;
const int rtStatus				= 8;

using namespace System;
using namespace WiimoteLib;

/// <summary>Converts a System.String to a char*</summary>
/// <param name="source">The System.String to convert</param>
/// <returns>Source as a char*</returns>
char* toCharArray(System::String^ source)
{
	char* pString = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(source).ToPointer();
	return (pString);
}

////////////////////////////////////////////
// Wii Remote Functions
////////////////////////////////////////////
		// Connection Functions
		exp double	wm_find_all();
		exp double  wm_found();
		exp double  wm_set_using(double wm);
			double  wm_set_using(char* wm);
		exp double  wm_connect();
		exp double  wm_connect_all();
		exp double  wm_exists();
		exp double  wm_connected();
		exp double  wm_disconnect();
		exp double  wm_disconnect_all();
		exp double  wm_set_report_type(double report_type, double continuous);
		exp double  wm_get_report_type();
		exp double  wm_get_report_continuous();
		exp double  wm_get_id();
			double  wm_get_id(double index);
			double  wm_get_id(char* guid);
		exp char*	wm_get_guid(double val);
			char*	wm_get_guid();
		exp	double  wm_get_index(double guid);
			double  wm_get_index();
			double  wm_get_index(char* guid);

		// LED Functions
		exp double wm_get_led(double led_num);
		exp double wm_set_leds(double led1, double led2, double led3, double led4);
		exp double wm_set_leds_int(double val);

		// Status
		exp double wm_get_battery();
		exp double wm_get_status();
		exp double wm_check_extension();
		exp double wm_set_rumble(double rumbling);
		exp double wm_get_rumble();

		// Orientation
		exp double wm_get_moving();
		exp double wm_get_roll();
		exp double wm_get_pitch();
		exp double wm_get_yaw();
		exp double wm_get_altitude();

		// Reading/Writing
		exp double wm_bin_read_byte(double address);
		exp double wm_bin_write_byte(double address, double value);

////////////////////////////////////////////
// Mathematical Functions
////////////////////////////////////////////
		exp double in_domain(double x, double d1, double d2);
		exp double domain_rescale(double val, double minin, double maxin, double minout, double maxout);

///////////////////////////////////////////////
// Buttons, Joysticks, Triggers, and Sensors
///////////////////////////////////////////////
		// Buttons
		exp double wm_guitar_check_button(double key_code);
		exp double wm_nunchuck_check_button(double key_code);
		exp double wm_classic_check_button(double key_code);
		exp double wm_check_button(double key_code);

		// Sensors (Balance Board)
		exp double wm_bb_get_weight_lbs();
		exp double wm_bb_get_weight_kgs();
		exp double wm_bb_get_sensor_raw(double sensor);
		exp double wm_bb_get_sensor_kgs(double sensor);
		exp double wm_bb_get_sensor_lbs(double sensor);

		// Joysticks (General)
		exp double joystick_direction(double xx, double yy);
		exp double joystick_pressure(double xx, double yy);
		exp double wm_set_joystick_dead_zone(double val);
		exp double wm_get_joystick_dead_zone();
		
		// Joysticks (Nunchuck)
		exp double wm_nunchuck_xpos();
		exp double wm_nunchuck_ypos();
		exp double wm_nunchuck_direction();
		exp double wm_nunchuck_pressure();
		exp double wm_nunchuck_rawx();
		exp double wm_nunchuck_rawy();

		// Joysticks (Classic Controller)
		exp double wm_classic_xpos(double stick);
		exp double wm_classic_ypos(double stick);
		exp double wm_classic_rawx(double stick);
		exp double wm_classic_rawy(double stick);
		exp double wm_classic_direction(double stick);
		exp double wm_classic_pressure(double stick);

		// Joysticks (Guitar)
		exp double wm_guitar_xpos();
		exp double wm_guitar_ypos();
		exp double wm_guitar_direction();
		exp double wm_guitar_pressure();
		exp double wm_guitar_rawx();
		exp double wm_guitar_rawy();

		// Triggers (General)
		exp double wm_set_trigger_dead_zone(double val);
		exp double wm_get_trigger_dead_zone();

		// Triggers (Classic Controller)
		exp double wm_classic_trigger_pressure(double trigger);
		exp double wm_classic_trigger_raw(double trigger);

		// Whammy Bar (Guitar)
		exp double wm_guitar_whammybar_pos();
		exp double wm_guitar_whammybar_rawpos();

////////////////////////////////////////////
// Accelerometers and IR
////////////////////////////////////////////
		// Accelerometer (General)
		exp double wm_calc_accel(float accel, int dz_index);

		// Accelerometer (Wii Remote)
		exp double wm_get_accel_x();
		exp double wm_get_accel_y();
		exp double wm_get_accel_z();
		exp double wm_get_accel_rawx();
		exp double wm_get_accel_rawy();
		exp double wm_get_accel_rawz();
		exp double wm_set_accel_dead_zone_x(double val);
		exp double wm_set_accel_dead_zone_y(double val);
		exp double wm_set_accel_dead_zone_z(double val);
		exp double wm_get_accel_dead_zone_x();
		exp double wm_get_accel_dead_zone_y();
		exp double wm_get_accel_dead_zone_z();

		// Accelerometer (Nunchuck)
		exp double wm_nunchuck_get_accel_x();
		exp double wm_nunchuck_get_accel_y();
		exp double wm_nunchuck_get_accel_z();
		exp double wm_nunchuck_get_accel_rawx();
		exp double wm_nunchuck_get_accel_rawy();
		exp double wm_nunchuck_get_accel_rawz();
		exp double wm_nunchuck_set_accel_dead_zone_x(double val);
		exp double wm_nunchuck_set_accel_dead_zone_y(double val);
		exp double wm_nunchuck_set_accel_dead_zone_z(double val);
		exp double wm_nunchuck_get_accel_dead_zone_x();
		exp double wm_nunchuck_get_accel_dead_zone_y();
		exp double wm_nunchuck_get_accel_dead_zone_z();

		// Infrared
		exp double wm_ir_set_sensitivity(double sensitivity);
		exp double wm_ir_get_sensitivity();
		exp double wm_ir_found_dot(double dot_number);
		exp double wm_ir_dot_size(double dot_number);
		exp double wm_ir_dot_get_x(double dot_number);
		exp double wm_ir_dot_get_y(double dot_number);
		exp double wm_ir_dot_get_rawx(double dot_number);
		exp double wm_ir_dot_get_rawy(double dot_number);
		exp double wm_ir_dot_get_midx();
		exp double wm_ir_dot_get_midy();
		exp double wm_ir_dot_get_rawmidx();
		exp double wm_ir_dot_get_rawmidy();
		exp double wm_ir_dot_get_delta_x(double dot_number);
		exp double wm_ir_dot_get_delta_y(double dot_number);
		exp double wm_ir_dot_get_delta_rawx(double dot_number);
		exp double wm_ir_dot_get_delta_rawy(double dot_number);
		exp double wm_ir_dot_get_delta_midx();
		exp double wm_ir_dot_get_delta_midy();
		exp double wm_ir_dot_get_delta_rawmidx();
		exp double wm_ir_dot_get_delta_rawmidy();
		exp double wm_ir_display_get_x();
		exp double wm_ir_display_get_y();

////////////////////////////////////////////
// Calibration
////////////////////////////////////////////
		// Nunchuck Get
		exp double wm_nunchuck_get_calibration_x0();
		exp double wm_nunchuck_get_calibration_xg();
		exp double wm_nunchuck_get_calibration_y0();
		exp double wm_nunchuck_get_calibration_yg();
		exp double wm_nunchuck_get_calibration_z0();
		exp double wm_nunchuck_get_calibration_zg();
		exp double wm_nunchuck_get_calibration_maxx();
		exp double wm_nunchuck_get_calibration_maxy();
		exp double wm_nunchuck_get_calibration_midx();
		exp double wm_nunchuck_get_calibration_midy();
		exp double wm_nunchuck_get_calibration_minx();
		exp double wm_nunchuck_get_calibration_miny();
		// Nunchuck Set
		exp double wm_nunchuck_set_calibration_x0(double val);
		exp double wm_nunchuck_set_calibration_xg(double val);
		exp double wm_nunchuck_set_calibration_y0(double val);
		exp double wm_nunchuck_set_calibration_yg(double val);
		exp double wm_nunchuck_set_calibration_z0(double val);
		exp double wm_nunchuck_set_calibration_zg(double val);
		exp double wm_nunchuck_set_calibration_maxx(double val);
		exp double wm_nunchuck_set_calibration_maxy(double val);
		exp double wm_nunchuck_set_calibration_midx(double val);
		exp double wm_nunchuck_set_calibration_midy(double val);
		exp double wm_nunchuck_set_calibration_minx(double val);
		exp double wm_nunchuck_set_calibration_miny(double val);
		// Classic Controller Get
		exp double wm_classic_get_calibration_maxtrigger(double trigger);
		exp double wm_classic_get_calibration_mintrigger(double trigger);
		exp double wm_classic_get_calibration_maxx(double joystick);
		exp double wm_classic_get_calibration_minx(double joystick);
		exp double wm_classic_get_calibration_midx(double joystick);
		exp double wm_classic_get_calibration_midy(double joystick);
		exp double wm_classic_get_calibration_maxy(double joystick);
		exp double wm_classic_get_calibration_miny(double joystick);
		// Classic Controller Set
		exp double wm_classic_set_calibration_maxtrigger(double trigger, double val);
		exp double wm_classic_set_calibration_mintrigger(double trigger, double val);
		exp double wm_classic_set_calibration_maxx(double joystick, double val);
		exp double wm_classic_set_calibration_minx(double joystick, double val);
		exp double wm_classic_set_calibration_midx(double joystick, double val);
		exp double wm_classic_set_calibration_midy(double joystick, double val);
		exp double wm_classic_set_calibration_maxy(double joystick, double val);
		exp double wm_classic_set_calibration_miny(double joystick, double val);
		// Wii Remote Get
		exp double wm_get_calibration_x0();
		exp double wm_get_calibration_xg();
		exp double wm_get_calibration_y0();
		exp double wm_get_calibration_yg();
		exp double wm_get_calibration_z0();
		exp double wm_get_calibration_zg();
		// Wii Remote Set
		exp double wm_set_calibration_x0(double val);
		exp double wm_set_calibration_xg(double val);
		exp double wm_set_calibration_y0(double val);
		exp double wm_set_calibration_yg(double val);
		exp double wm_set_calibration_z0(double val);
		exp double wm_set_calibration_zg(double val);
		// Balance Board Get
		exp double wm_bb_get_calibration_kg0(double sensor);
		exp double wm_bb_get_calibration_kg17(double sensor);
		exp double wm_bb_get_calibration_kg34(double sensor);
		// Balance Board Set
		exp double wm_bb_set_calibration_kg0(double sensor, double val);
		exp double wm_bb_set_calibration_kg17(double sensor, double val);
		exp double wm_bb_set_calibration_kg34(double sensor, double val);

////////////////////////////////////////////
// Mii Functions
////////////////////////////////////////////
		exp double wm_mii_data_dump(char* fName, double miiBlock, double miiNumber);
		exp double wm_mii_data_inject(char* fName,double miiBlock, double miiNumber);
		exp double wm_mii_update_crc(char* fName);
		cli::array<unsigned char,1>^ wm_mii_data_update(cli::array<unsigned char,1>^ miiData);


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
		/// <summary>A static pointer to "this"</summary>
		static GiiMoteLib::GiiMote^ gm;

		 //////////////////
		// Constructors //
	   //////////////////
	public:
		/// <summary>Default constructor</summary>
		/// <returns>Nothing</returns>
		GiiMote()
		{
			GiiMote::gm = this;
			this->wmIndex = 0;
			this->wc = gcnew WiimoteCollection();
			
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
			// Since I'm not sure how to identify which Wii Remote is triggering the event
			// and this one doesn't happen often, update all of them.
			int tIndex = wmIndex;
			for(int i = 0; i < this->wc->Count; i++)
			{
				this->wmIndex = i;
				// When an extension is plugged in or unplugged all reporting stops
				// until we update the report type
				wm_set_report_type(this->report_type[this->wmIndex], this->continuous[this->wmIndex]);
			}
			this->wmIndex = tIndex;
		}

		/// <summary>Wii Remote state change event</summary>
		/// <param name="sender">Object sending the event</param>
		/// <param name="args">Current Wii Remote state</param>
		void wm_OnWiimoteChanged(System::Object^ sender, WiimoteChangedEventArgs^ args)
		{
			// Update only the calling Wii Remote
			int Index = -1;
			for(int i = 0; i < this->wc->Count; i++)
			{
				if (args->WiimoteState->GetHashCode() == this->wc[i]->WiimoteState->GetHashCode())
				{
					Index = i;
					break;
				}
			}
			if (Index == -1)
			{
				return;
			}

			if (this->report_type[Index] == rtAuto || this->report_type[Index] == rtIRAccel || this->report_type[Index] == rtIRExtensionAccel)
			{

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
					this->ir_last_pos[Index, i].X = this->wc[Index]->WiimoteState->IRState.IRSensors[i].Position.X;
					this->ir_last_pos[Index, i].Y = this->wc[Index]->WiimoteState->IRState.IRSensors[i].Position.Y;
					this->ir_last_raw_pos[Index, i].X = this->wc[Index]->WiimoteState->IRState.IRSensors[i].RawPosition.X;
					this->ir_last_raw_pos[Index, i].Y = this->wc[Index]->WiimoteState->IRState.IRSensors[i].RawPosition.Y;
				}

				this->ir_last_mid_pos[Index].X = this->wc[Index]->WiimoteState->IRState.Midpoint.X;
				this->ir_last_mid_pos[Index].Y = this->wc[Index]->WiimoteState->IRState.Midpoint.Y;
				this->ir_last_rawmid_pos[Index].X = this->wc[Index]->WiimoteState->IRState.RawMidpoint.X;
				this->ir_last_rawmid_pos[Index].Y = this->wc[Index]->WiimoteState->IRState.RawMidpoint.Y;
			}
		}

	};
}
