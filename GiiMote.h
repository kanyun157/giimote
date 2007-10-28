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

#include "mii.h"

namespace GiiMoteLib {

	public ref class GiiMote
	{
	public:
		// static GiiMote^ dll_instance;
		Wiimote^ wm;
		WiimoteState^ wmState;
		bool connected;
		double dead_zone;
		double trigger_dead_zone;
		double accel_dead_zone;
		

		 //////////////////
		// Constructors //
	   //////////////////
	public:
		GiiMote()
		{
			// GiiMote::dll_instance = this;
			wm = gcnew Wiimote;
			this->connected = false;
			this->dead_zone = 0;
		}
		~GiiMote()
		{
			// Cleanup after sloppy users.
			// Actually, I think the Wiimote class does this for you as well.
			if (wm_connected())
			{
				wm_disconnect();
			}
			// Do I need to delete these or does it destruct them?
			// delete this->wm->WiimoteChanged;
			// delete this->wm->WiimoteExtensionChanged;
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

		 //////////////////
		//  Functions   //
	   //////////////////
	public:
		double wm_connected(void)
		{
			return ((double)this->connected);
		}

////////////////////////////////////////////
// Wiimote Class Wrapper Functions
////////////////////////////////////////////

double wm_connect()
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

double wm_set_write_method(double alt_write_method)
{
	this->wm->AltWriteMethod = (alt_write_method > 0);
	return ( 1 );
}

double wm_disconnect(void)
{
	if (wm_connected())
	{
		this->wm->Disconnect();
		this->connected = false;
	}
	return (!wm_connected());
}

double in_domain(double x, double d1,double d2)
{
	double val = x;
	if (x > d2 && d2 != -1) { val = d2; } // -1 = infinity.
	if (x < d1) { val = d1; }

	return (val);

}

double wm_set_dead_zone(double num, double type)
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


double wm_get_led(double led_num)
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

double wm_set_leds(double led1, double led2, double led3, double led4)
{
	bool bLed1,bLed2,bLed3,bLed4;
	bLed1 = (led1 > 0);
	bLed2 = (led2 > 0);
	bLed3 = (led3 > 0);
	bLed4 = (led4 > 0);

	this->wm->SetLEDs(bLed1,bLed2,bLed3,bLed4);

	return ( 1 );
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
	this->wm->GetStatus();
	return ( (double)this->wmState->Battery );
}

double wm_nunchuck_xpos()
{
	double xx = (double)this->wmState->NunchukState.X;

	if ( System::Math::Abs(xx) < (this->dead_zone) )
	{
		xx = 0;
	}
	
	return ( xx );
}

double wm_nunchuck_ypos()
{
	double yy = (double)this->wmState->NunchukState.Y;

	if ( System::Math::Abs(yy) < (this->dead_zone) )
	{
		yy = 0;
	}
	
	return ( yy );
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
	return (joystick_direction(wm_nunchuck_xpos(),wm_nunchuck_ypos()));
}

double joystick_direction(double xx, double yy)
{
	return ( System::Math::Atan2(yy,xx) );
}

double wm_classic_xpos(double stick)
{
	double xx;

	switch ((int)stick)
	{
	case joyL:
		xx = (this->wmState->ClassicControllerState.XL);
		break;
	case joyR:
		xx = (this->wmState->ClassicControllerState.XR);
		break;
	default:
		xx = -1;
		break;
	}

	if ( System::Math::Abs(xx) < (this->dead_zone) )
	{
		xx = 0;
	}
	
	return ( xx );
}

double wm_classic_ypos(double stick)
{
	double yy;

	switch ((int)stick)
	{
	case joyL:
		yy = (this->wmState->ClassicControllerState.YL);
		break;
	case joyR:
		yy = (this->wmState->ClassicControllerState.YR);
		break;
	default:
		yy = -1;
		break;
	}

	if ( System::Math::Abs(yy) < (this->dead_zone) )
	{
		yy = 0;
	}
	
	return ( yy );
}

double wm_classic_rawx(double stick)
{
	if (stick == joyL)
	{
		return (this->wmState->ClassicControllerState.RawXL);
	}
	if (stick == joyR)
	{
		return (this->wmState->ClassicControllerState.RawXR);
	}
	return (-1);
}

double wm_classic_rawy(double stick)
{

	if (stick == joyL)
	{
		return (this->wmState->ClassicControllerState.RawYL);
	}
	if (stick == joyR)
	{
		return (this->wmState->ClassicControllerState.RawYR);
	}
	return (-1);
}

double wm_classic_direction(double stick)
{
	if (stick == joyR || stick == joyL)
	{
		return (joystick_direction( wm_classic_xpos(stick) , wm_classic_ypos(stick) ));
	}
	else
	{
		return (0);
	}
}

double wm_classic_trigger_pressure(double trigger)
{
	double val = -1;
	if (trigger == btnL || trigger == 0)
	{
		// Left
		val = (double)this->wmState->ClassicControllerState.TriggerL;
	}
	if (trigger == btnR || trigger == 1)
	{
		// Right
		val = (double)this->wmState->ClassicControllerState.TriggerR;
	}
	if (val < this->trigger_dead_zone && val != -1)
	{
		val = 0;
	}
	if (val > (1 - this->trigger_dead_zone) )
	{
		val = 1;
	}
	return ( val );
}

double wm_classic_trigger_raw(double trigger)
{
	if (trigger == btnL || trigger == 0)
	{
		// Left
		return( (double)this->wmState->ClassicControllerState.RawTriggerL );

	}
	if (trigger == btnR || trigger == 1)
	{
		// Right
		return( (double)this->wmState->ClassicControllerState.RawTriggerR );
	}

	return ( -1 );
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

double wm_get_rumble()
{
	return ( (double)this->wmState->Rumble );
}

double wm_calc_accel(float accel)
{
	double val = (double)accel;
	if (val < this->accel_dead_zone && val > -(this->accel_dead_zone))
	{
		val = 0;
	}
	return ( val );
}

double wm_get_accel_x()
{
	return ( wm_calc_accel(this->wmState->AccelState.X) );
}
double wm_get_accel_y()
{
	return ( wm_calc_accel(this->wmState->AccelState.Y) );
}
double wm_get_accel_z()
{
	return ( wm_calc_accel(this->wmState->AccelState.Z) );
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
	return ( wm_calc_accel(this->wmState->NunchukState.AccelState.X) );
}
double wm_nunchuck_get_accel_y()
{
	return ( wm_calc_accel(this->wmState->NunchukState.AccelState.Y) );
}
double wm_nunchuck_get_accel_z()
{
	return ( wm_calc_accel(this->wmState->NunchukState.AccelState.Z) );
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

double wm_ir_dot_get_midx()
{
	return( (double)this->wmState->IRState.MidX );
}

double wm_ir_dot_get_midy()
{
	return( (double)this->wmState->IRState.MidY );
}

double wm_ir_dot_get_rawmidx()
{
	return ( (double)this->wmState->IRState.RawMidX );
}

double wm_ir_dot_get_rawmidy()
{
	return ( (double)this->wmState->IRState.RawMidY );
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
	return ( (double)this->wmState->AccelCalibrationInfo.X0 );
}
double wm_get_calibration_xg()
{
	return ( (double)this->wmState->AccelCalibrationInfo.XG );
}
double wm_get_calibration_y0()
{
	return ( (double)this->wmState->AccelCalibrationInfo.Y0 );
}
double wm_get_calibration_yg()
{
	return ( (double)this->wmState->AccelCalibrationInfo.YG );
}
double wm_get_calibration_z0()
{
	return ( (double)this->wmState->AccelCalibrationInfo.Z0 );
}
double wm_get_calibration_zg()
{
	return ( (double)this->wmState->AccelCalibrationInfo.ZG );
}

double wm_nunchuck_get_calibration_x0()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.X0 );
}
double wm_nunchuck_get_calibration_xg()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.XG );
}
double wm_nunchuck_get_calibration_y0()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.Y0 );
}
double wm_nunchuck_get_calibration_yg()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.YG );
}
double wm_nunchuck_get_calibration_z0()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.Z0 );
}
double wm_nunchuck_get_calibration_zg()
{
	return ( (double)this->wmState->NunchukState.CalibrationInfo.AccelCalibration.ZG );
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
	return ( value );
}

double wm_bin_write_byte(double address, double value)
{
	this->wm->WriteData((int)address,(unsigned char)value);
	return ( 1 );
}

// Mii Functions
double wm_mii_data_dump(System::String^ fName,double miiBlock)
{
	int start = MII_DATA_START + ( MII_BLOCK_SIZE * (miiBlock >= 2) );
	int end	  = start + MII_BLOCK_SIZE + ( (MII_BLOCK_SIZE) * (miiBlock<=0) ); 
	System::IO::FileStream^ miiFile = gcnew System::IO::FileStream(fName,System::IO::FileMode::Create);
	for(int i = start; i < end; i++)
	{
		miiFile->WriteByte(wm->ReadData(i,1)[0]);
	}
	miiFile->Close();
	return ( 1 );
}

double wm_mii_data_inject(System::String^ fName,double miiBlock)
{
	cli::array<unsigned char,1>^ miiBuffer;
	System::IO::FileStream^ miiFile = gcnew System::IO::FileStream(fName,System::IO::FileMode::Open);
	miiBuffer->Resize(miiBuffer,MII_BLOCK_SIZE);
	int start = MII_DATA_START + (MII_BLOCK_SIZE*(miiBlock>=2));

	// Check to see how many blocks the file contains.
	switch (miiFile->Length)
	{
	case MII_DATA_LENGTH:
		if (miiBlock == 0)
		{
			miiBuffer->Resize(miiBuffer,MII_DATA_LENGTH);
			miiFile->Read(miiBuffer,0,MII_DATA_LENGTH);
		}
		else
		{
			miiFile->Read(miiBuffer,MII_BLOCK_SIZE*(miiBlock >= 2),MII_BLOCK_SIZE);
		}
		break;
	case MII_BLOCK_SIZE:
		miiFile->Read(miiBuffer,0,MII_BLOCK_SIZE);
		break;
	default:
		return (-1);
		break;
	}
	miiFile->Close();

	// Update the CRC and other info.
	switch (miiBuffer->Length)
	{
	case MII_BLOCK_SIZE:
		miiBuffer = wm_mii_data_update(miiBuffer);
		break;
	case MII_DATA_LENGTH:
		cli::array<unsigned char,1>^ tBuff1 = gcnew cli::array<unsigned char,1>(MII_BLOCK_SIZE);
		cli::array<unsigned char,1>^ tBuff2 = gcnew cli::array<unsigned char,1>(MII_BLOCK_SIZE);
		System::Array::Copy(miiBuffer,0,tBuff1,0,MII_BLOCK_SIZE);
		System::Array::Copy(miiBuffer,MII_BLOCK_SIZE,tBuff2,0,MII_BLOCK_SIZE);

		tBuff1 = wm_mii_data_update(tBuff1);
		tBuff2 = wm_mii_data_update(tBuff2);

		miiBuffer[750] = tBuff1[750];
		miiBuffer[751] = tBuff1[751];
		miiBuffer[1502] = tBuff2[750];
		miiBuffer[1503] = tBuff2[751];
		delete tBuff1;
		delete tBuff2;
		break;
	}

	switch (miiBuffer->Length)
	{
	case MII_BLOCK_SIZE:
		for(int c=0;c<MII_BLOCK_SIZE;c++)
		{
			this->wm->WriteData(start + c,miiBuffer[c]);
		}
		//this->wm->WriteData(start, 500, miiBuffer);
		break;
	case MII_DATA_LENGTH:
		for(int c=0;c<MII_DATA_LENGTH;c++)
		{
			this->wm->WriteData(MII_DATA_START + c,miiBuffer[c]);
		}
		break;
	default:
		return ( 0 );
		break;
	}

	return ( 1 );
}

double wm_mii_update_crc(System::String^ fName)
{
	System::IO::FileStream^ miiFile = gcnew System::IO::FileStream(fName,System::IO::FileMode::Open);
	cli::array<unsigned char,1>^ miiBuffer;
	miiBuffer->Resize(miiBuffer,(int)miiFile->Length);
	miiFile->Read(miiBuffer,0,(int)miiFile->Length);

	switch (miiBuffer->Length)
	{
	case MII_BLOCK_SIZE:
		miiBuffer = wm_mii_data_update(miiBuffer);
		miiFile->SetLength(MII_BLOCK_SIZE - 2);
		miiFile->WriteByte(miiBuffer[750]);
		miiFile->WriteByte(miiBuffer[751]);
		break;
	case (MII_BLOCK_SIZE * 2):

		cli::array<unsigned char,1>^ tBuff1;
		cli::array<unsigned char,1>^ tBuff2;
		miiBuffer->ConstrainedCopy(miiBuffer,0,tBuff2,0,MII_BLOCK_SIZE);
		miiBuffer->ConstrainedCopy(miiBuffer,MII_BLOCK_SIZE,tBuff2,0,MII_BLOCK_SIZE);

		tBuff1 = wm_mii_data_update(tBuff1);
		tBuff2 = wm_mii_data_update(tBuff2);

		miiBuffer[750] = tBuff1[750];
		miiBuffer[751] = tBuff1[751];
		miiBuffer[1502] = tBuff2[750];
		miiBuffer[1503] = tBuff2[751];

		miiFile->SetLength(0);
		miiFile->Write(miiBuffer,0,miiBuffer->Length);
		break;
	}

	miiFile->Close();
	return (1);
}

cli::array<unsigned char,1>^ wm_mii_data_update(cli::array<unsigned char,1>^ miiData)
{
	cli::array<unsigned char,1>^ text = miiData;
	unsigned short st = 0x0000;
	unsigned short good_crc = st;
	unsigned short bad_crc = st;
	unsigned short text_length = 750;
	int off = 0;

	// go
    // unsigned short ch;
	unsigned short i, v, xor_flag;

    for(int j=0; j<(text_length-off); j++) {
        //update_good_crc(text[j+off]);
		// update-good-crc
    /*
    Align test bit with leftmost bit of the message byte.
    */
    v = 0x80;

    for (i=0; i<8; i++)
    {
        if (good_crc & 0x8000)
        {
            xor_flag= 1;
        }
        else
        {
            xor_flag= 0;
        }
        good_crc = good_crc << 1;

        if (text[j+off] & v)
        {
            /*
            Append next bit of message to end of CRC if it is not zero.
            The zero bit placed there by the shift above need not be
            changed if the next bit of the message is zero.
            */
            good_crc= good_crc + 1;
        }

        if (xor_flag)
        {
            good_crc = good_crc ^ poly;
        }

        /*
        Align test bit with next bit of the message byte.
        */
        v = v >> 1;
	}
		// update-good-crc-end
    }
    // augment_message_for_good_crc();
	    for (i=0; i<16; i++)
    {
        if (good_crc & 0x8000)
        {
            xor_flag= 1;
        }
        else
        {
            xor_flag= 0;
        }
        good_crc = good_crc << 1;

        if (xor_flag)
        {
            good_crc = good_crc ^ poly;
        }
    }
	// augment-message-for-good-crc-end
	// end-go

	text[750] = (good_crc&0xFF00)>>8;
    text[751] = (good_crc&0x00FF);
	
	return (text);
}

	};

}
