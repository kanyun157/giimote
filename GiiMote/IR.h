// IR.h - Contains functions related to the WM's IR camera and triangulation.

namespace GiiMoteLib {
	/// <summary>Sets the sensitivity of the IR camera</summary>
	/// <param name="sensitivity">Sensitivity level 1-6</param>
	/// <returns>Success as bool or -1 on error</returns>
	double GiiMote::wm_ir_set_sensitivity(double sensitivity)
	{
		switch ((int)sensitivity)
		{
		case 1:
			this->ir_sensitivity = IRSensitivity::WiiLevel1;
			break;
		case 2:
			this->ir_sensitivity = IRSensitivity::WiiLevel2;
			break;
		case 3:
			this->ir_sensitivity = IRSensitivity::WiiLevel3;
			break;
		case 4:
			this->ir_sensitivity = IRSensitivity::WiiLevel4;
			break;
		case 5:
			this->ir_sensitivity = IRSensitivity::WiiLevel5;
			break;
		case 6:
			this->ir_sensitivity = IRSensitivity::Maximum;
			break;
		default:
			return ( 0 );
			break;
		}
		if (wm_connected())
		{
			return (wm_set_report_type(this->report_type, this->continuous));
		}
		else
		{
			return ( 1 );
		}
	}
	/// <summary>Gets the sensitivity of the IR camera</summary>
	/// <returns>The IR camera's sensitivity level (1-6)</returns>
	double GiiMote::wm_ir_get_sensitivity()
	{
		return ( (double)this->ir_sensitivity );
	}
	/// <summary>Checks to see if the given IR dot is visible</summary>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>Dot found as bool or -1 on error</returns>
	double GiiMote::wm_ir_found_dot(double dot_number)
	{
		try
		{
			return (this->wmState->IRState.IRSensors[((int)dot_number) - 1].Found);
		}
		catch(...)
		{
			return ( -1 );
		}
	}

	/// <summary>Checks the size of the given IR dot</summary>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>Dot size from 0 to 15 or -1 on error</returns>
	double GiiMote::wm_ir_dot_size(double dot_number)
	{
		try
		{
			return ((double)this->wmState->IRState.IRSensors[((int)dot_number) - 1].Size);
		}
		catch(...)
		{
			return ( -1.0 );
		}
	}

	/// <summary>Normalized X value of the given dot</summary>
	/// <remarks>Domain: [0.0,1.0]</remarks>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>X value of given dot from 0.0 to 1.0 or -1 on error</returns>
	double GiiMote::wm_ir_dot_get_x(double dot_number)
	{
		try
		{
			return ((double)this->wmState->IRState.IRSensors[((int)dot_number) - 1].Position.X);
		}
		catch(...)
		{
			return ( -1.0 );
		}
	}

	/// <summary>Normalized Y value of the given dot</summary>
	/// <remarks>Domain: [0.0,1.0]</remarks>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>Y value of given dot from 0.0 to 1.0 or -1 on error</returns>
	double GiiMote::wm_ir_dot_get_y(double dot_number)
	{
		try
		{
			return ((double)this->wmState->IRState.IRSensors[((int)dot_number) - 1].Position.Y);
		}
		catch(...)
		{
			return ( -1.0 );
		}
	}

	/// <summary>Raw X value of the given dot</summary>
	/// <remarks>Domain: [0,1023]</remarks>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>X value of the given dot from 0 to 1023 or -1 on error</returns>
	double GiiMote::wm_ir_dot_get_rawx(double dot_number)
	{
		try
		{
			return ((double)this->wmState->IRState.IRSensors[((int)dot_number) - 1].RawPosition.X);
		}
		catch(...)
		{
			return ( -1.0 );
		}
	}

	/// <summary>Raw Y value of the given dot</summary>
	/// <remarks>Domain: [0,1023]</remarks>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>Y value of the given dot from 0 to 1023 or -1 on error</returns>
	double GiiMote::wm_ir_dot_get_rawy(double dot_number)
	{
		try
		{
			return ((double)this->wmState->IRState.IRSensors[((int)dot_number) - 1].RawPosition.Y);
		}
		catch(...)
		{
			return ( -1.0 );
		}
	}

	/// <summary>Normalized midpoint of IR sensors 1 and 2 only along the X-axis</summary>
	/// <remarks>Domain: [0.0,1.0]</remarks>
	/// <returns>Normalized X Midpoint</returns>
	double GiiMote::wm_ir_dot_get_midx()
	{
		return( (double)this->wmState->IRState.Midpoint.X );
	}
	/// <summary>Normalized midpoint of IR sensors 1 and 2 only along the Y-axis</summary>
	/// <remarks>Domain: [0.0,1.0]</remarks>
	/// <returns>Normalized Y Midpoint</returns>
	double GiiMote::wm_ir_dot_get_midy()
	{
		return( (double)this->wmState->IRState.Midpoint.Y );
	}

	/// <summary>Raw midpoint of IR sensors 1 and 2 only along the X-axis</summary>
	/// <remarks>Domain: [0,1023]</remarks>
	/// <returns>Raw X Midpoint</returns>
	double GiiMote::wm_ir_dot_get_rawmidx()
	{
		return ( (double)this->wmState->IRState.RawMidpoint.X );
	}

	/// <summary>Raw midpoint of IR sensors 1 and 2 only along the Y-axis</summary>
	/// <remarks>Domain: [0,767]</remarks>
	/// <returns>Raw Y Midpoint</returns>
	double GiiMote::wm_ir_dot_get_rawmidy()
	{
		return ( (double)this->wmState->IRState.RawMidpoint.Y );
	}

	/// <summary>Change in x value of the given dot</summary>
	/// <remarks>Domain: [0,1]</remarks>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>Delta x</returns>
	double GiiMote::wm_ir_dot_get_delta_x(double dot_number)
	{
		int dot = (int)dot_number - 1;
		try
		{
			return (this->wmState->IRState.IRSensors[dot].Position.X - ir_last_pos[dot]->X);
		}
		catch(...)
		{
			return ( -1.0 );
		}
	}

	/// <summary>Change in y value of the given dot</summary>
	/// <remarks>Domain: [0,1]</remarks>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>Delta y</returns>
	double GiiMote::wm_ir_dot_get_delta_y(double dot_number)
	{
		int dot = (int)dot_number - 1;
		try
		{
			return (this->wmState->IRState.IRSensors[dot].Position.Y - ir_last_pos[dot]->Y);
		}
		catch(...)
		{
			return ( -1.0 );
		}
	}

	/// <summary>Change in raw x value of the given dot</summary>
	/// <remarks>Domain: [0,1023]</remarks>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>Delta rawx</returns>
	double GiiMote::wm_ir_dot_get_delta_rawx(double dot_number)
	{
		int dot = (int)dot_number - 1;
		try
		{	
			return (this->wmState->IRState.IRSensors[dot].RawPosition.X - ir_last_raw_pos[dot]->X);
		}
		catch(...)
		{
			return ( -1.0 );
		}
	}

	/// <summary>Change in raw y value of the given dot</summary>
	/// <remarks>Domain: [0,767]</remarks>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>Delta rawy</returns>
	double GiiMote::wm_ir_dot_get_delta_rawy(double dot_number)
	{
		int dot = (int)dot_number - 1;
		try
		{	
			return (this->wmState->IRState.IRSensors[dot].RawPosition.Y - ir_last_raw_pos[dot]->Y);
		}
		catch(...)
		{
			return ( -1.0 );
		}
	}

	/// <summary>Change in midx value</summary>
	/// <remarks>Domain: [0,1]</remarks>
	/// <returns>Delta midx</returns>
	double GiiMote::wm_ir_dot_get_delta_midx()
	{
		return ( double(this->wmState->IRState.Midpoint.X - ir_last_mid_pos->X) );
	}

	/// <summary>Change in midy value</summary>
	/// <remarks>Domain: [0,1]</remarks>
	/// <returns>Delta midy</returns>
	double GiiMote::wm_ir_dot_get_delta_midy()
	{
		return ( double(this->wmState->IRState.Midpoint.Y - ir_last_mid_pos->Y) );
	}

	/// <summary>Change in raw midx value</summary>
	/// <remarks>Domain: [0,1023]</remarks>
	/// <returns>Delta raw midx</returns>
	double GiiMote::wm_ir_dot_get_delta_rawmidx()
	{
		return ( double(this->wmState->IRState.RawMidpoint.X - ir_last_rawmid_pos->X) );
	}

	/// <summary>Change in raw midy value</summary>
	/// <remarks>Domain: [0,767]</remarks>
	/// <returns>Delta raw midy</returns>
	double GiiMote::wm_ir_dot_get_delta_rawmidy()
	{
		return ( double(this->wmState->IRState.RawMidpoint.Y - ir_last_rawmid_pos->Y) );
	}

	/// <summary>X coordinate of the screen that the Wii Remote is pointing at</summary>
	/// <returns>X coordinate relative to screen</returns>
	double GiiMote::wm_ir_display_get_x()
	{
		return ((double)this->ir_screen_pos.X);
	}

	/// <summary>Y coordinate of the screen that the Wii Remote is pointing at</summary>
	/// <returns>Y coordinate relative to screen</returns>
	double GiiMote::wm_ir_display_get_y()
	{
		return ((double)this->ir_screen_pos.Y);
	}

} // namespace GiiMoteLib
