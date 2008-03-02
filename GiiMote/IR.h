// IR.h - Contains functions related to the WM's IR camera and triangulation.

namespace GiiMoteLib {
	
	/// <summary>Checks to see if the given IR dot is visible</summary>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>Dot found as bool</returns>
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
		case 3:
			found_dot = this->wmState->IRState.Found3;
			break;
		case 4:
			found_dot = this->wmState->IRState.Found4;
			break;
		default:
			return ( -1 );
			break;
		}
	return ( (double)found_dot );
	}

	/// <summary>Checks the size of the given IR dot</summary>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>Dot size</returns>
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
		case 3:
			size = this->wmState->IRState.Size3;
			break;
		case 4:
			size = this->wmState->IRState.Size4;
			break;
		default:
			break;
		}
		return ( (double)size );
	}

	/// <summary>Normalized X value of the given dot</summary>
	/// <remarks>Domain: [0.0,1.0]</remarks>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>X value of given dot as double from 0.0 to 1.0</returns>
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
		case 3:
			xx = this->wmState->IRState.X3;
			break;
		case 4:
			xx = this->wmState->IRState.X4;
			break;
		default:
			break;
		}
		return ( (double)xx );
	}

	/// <summary>Normalized Y value of the given dot</summary>
	/// <remarks>Domain: [0.0,1.0]</remarks>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>Y value of given dot as double from 0.0 to 1.0</returns>
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
		case 3:
			yy = this->wmState->IRState.Y3;
			break;
		case 4:
			yy = this->wmState->IRState.Y4;
			break;
		default:
			break;
		}
		return ( (double)yy );
	}

	/// <summary>Raw X value of the given dot</summary>
	/// <remarks>Domain: [0,1023]</remarks>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>X value of the given dot from 0 to 1023</returns>
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
		case 3:
			xx = this->wmState->IRState.RawX3;
			break;
		case 4:
			xx = this->wmState->IRState.RawX4;
			break;
		default:
			break;
		}
		return ( (double)xx );
	}

	/// <summary>Raw Y value of the given dot</summary>
	/// <remarks>Domain: [0,1023]</remarks>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>Y value of the given dot from 0 to 1023</returns>
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
		case 3:
			yy = this->wmState->IRState.RawY3;
			break;
		case 4:
			yy = this->wmState->IRState.RawY4;
			break;
		default:
			break;
		}
		return ( (double)yy );
	}

	/// <summary>Normalized midpoint of IR sensors 1 and 2 only along the X-axis</summary>
	/// <remarks>Domain: [0.0,1.0]</remarks>
	/// <returns>Normalized X Midpoint</returns>
	double GiiMote::wm_ir_dot_get_midx()
	{
		return( (double)this->wmState->IRState.MidX );
	}
	/// <summary>Normalized midpoint of IR sensors 1 and 2 only along the Y-axis</summary>
	/// <remarks>Domain: [0.0,1.0]</remarks>
	/// <returns>Normalized Y Midpoint</returns>
	double GiiMote::wm_ir_dot_get_midy()
	{
		return( (double)this->wmState->IRState.MidY );
	}
	/// <summary>Raw midpoint of IR sensors 1 and 2 only along the X-axis</summary>
	/// <remarks>Domain: [0,1023], [0,767]</remarks>
	/// <returns>Raw X Midpoint</returns>
	double GiiMote::wm_ir_dot_get_rawmidx()
	{
		return ( (double)this->wmState->IRState.RawMidX );
	}
	/// <summary>Raw midpoint of IR sensors 1 and 2 only along the Y-axis</summary>
	/// <remarks>Domain: [0,1023], [0,767]</remarks>
	/// <returns>Raw Y Midpoint</returns>
	double GiiMote::wm_ir_dot_get_rawmidy()
	{
		return ( (double)this->wmState->IRState.RawMidY );
	}

} // namespace GiiMoteLib
