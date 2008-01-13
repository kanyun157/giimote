// IR.h - Contains functions related to the WM's IR camera and triangulation.
#define LEFT 3
#define RIGHT 2
#define TOP 0
#define BOTTOM 1
#define BAR_POS 4

namespace GiiMoteLib {
	
	double GiiMote::wm_ir_found_dot(double dot_number)
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
			return ( -1 );
			break;
		}
	return ( (double)found_dot );
	}

	double GiiMote::wm_ir_dot_size(double dot_number)
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

	double GiiMote::wm_ir_dot_get_x(double dot_number)
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

	double GiiMote::wm_ir_dot_get_y(double dot_number)
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

	double GiiMote::wm_ir_dot_get_rawx(double dot_number)
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

	double GiiMote::wm_ir_dot_get_rawy(double dot_number)
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

	double GiiMote::wm_ir_dot_get_midx()
	{
		return( (double)this->wmState->IRState.MidX );
	}

	double GiiMote::wm_ir_dot_get_midy()
	{
		return( (double)this->wmState->IRState.MidY );
	}

	double GiiMote::wm_ir_dot_get_rawmidx()
	{
		return ( (double)this->wmState->IRState.RawMidX );
	}

	double GiiMote::wm_ir_dot_get_rawmidy()
	{
		return ( (double)this->wmState->IRState.RawMidY );
	}
	/*double GiiMote::wm_ir_display_get_x(double display_width)
	{
		return ( ( -((double)this->wmState->IRState.MidX) + 1 ) * display_width );
	}
	double GiiMote::wm_ir_display_get_y(double display_height)
	{
		return ( double(this->wmState->IRState.MidY) * display_height );
	}
	double GiiMote::wm_ir_set_calibration_right(double val)
	{
		IRCalibration[RIGHT] = val;
		return ( 1 );
	}
	double GiiMote::wm_ir_get_calibration_right()
	{
		return ( IRCalibration[RIGHT] );
	}
	double GiiMote::wm_ir_set_calibration_left(double val)
	{
		IRCalibration[LEFT] = val;
		return ( 1 );
	}
	double GiiMote::wm_ir_get_calibration_left()
	{
		return ( IRCalibration[LEFT] );
	}
	double GiiMote::wm_ir_set_calibration_top(double val)
	{
		IRCalibration[TOP] = val;
		return ( 1 );
	}
	double GiiMote::wm_ir_get_calibration_top()
	{
		return ( IRCalibration[TOP] );
	}
	double GiiMote::wm_ir_set_calibration_bottom(double val)
	{
		IRCalibration[BOTTOM] = val;
		return ( 1 );
	}
	double GiiMote::wm_ir_get_calibration_bottom()
	{
		return ( IRCalibration[BOTTOM] );
	}
	double GiiMote::wm_ir_sensor_bar_set_pos(double pos)
	{
		switch ((int)pos)
		{
			case BOTTOM:
				IRCalibration[BAR_POS] = BOTTOM;
				break;
			case TOP:
				IRCalibration[BAR_POS] = TOP;
				break;
			default:
				return ( -1 );
				break;
		}
		return ( 1 );
	}
	double GiiMote::wm_ir_sensor_bar_get_pos()
	{
		return ( IRCalibration[BAR_POS] );
	}*/

} // namespace GiiMoteLib