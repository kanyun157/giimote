// IR.h - Contains functions related to the WM's IR camera and triangulation.

	/// <summary>Sets the sensitivity of the IR camera</summary>
	/// <param name="sensitivity">Sensitivity level 1-6</param>
	/// <returns>Success as bool or -1 on error</returns>
	double wm_ir_set_sensitivity(double sensitivity)
	{
		switch ((int)sensitivity)
		{
		case 1:
			GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex] = IRSensitivity::WiiLevel1;
			break;
		case 2:
			GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex] = IRSensitivity::WiiLevel2;
			break;
		case 3:
			GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex] = IRSensitivity::WiiLevel3;
			break;
		case 4:
			GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex] = IRSensitivity::WiiLevel4;
			break;
		case 5:
			GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex] = IRSensitivity::WiiLevel5;
			break;
		case 6:
			GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex] = IRSensitivity::Maximum;
			break;
		default:
			return ( 0 );
			break;
		}
		if (wm_connected())
		{
			return (wm_set_report_type(GiiMote::gm->report_type[GiiMote::gm->wmIndex], GiiMote::gm->continuous[GiiMote::gm->wmIndex]));
		}
		else
		{
			return ( 1 );
		}
	}
	/// <summary>Gets the sensitivity of the IR camera</summary>
	/// <returns>The IR camera's sensitivity level (1-6)</returns>
	double wm_ir_get_sensitivity()
	{
		return ( (double)GiiMote::gm->ir_sensitivity[GiiMote::gm->wmIndex] );
	}
	/// <summary>Checks to see if the given IR dot is visible</summary>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>Dot found as bool or -1 on error</returns>
	double wm_ir_found_dot(double dot_number)
	{
		try
		{
			return (GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[((int)dot_number) - 1].Found);
		}
		catch(...)
		{
			return ( -1 );
		}
	}

	/// <summary>Checks the size of the given IR dot</summary>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>Dot size from 0 to 15 or -1 on error</returns>
	double wm_ir_dot_size(double dot_number)
	{
		try
		{
			return ((double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[((int)dot_number) - 1].Size);
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
	double wm_ir_dot_get_x(double dot_number)
	{
		try
		{
			return ((double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[((int)dot_number) - 1].Position.X);
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
	double wm_ir_dot_get_y(double dot_number)
	{
		try
		{
			return ((double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[((int)dot_number) - 1].Position.Y);
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
	double wm_ir_dot_get_rawx(double dot_number)
	{
		try
		{
			return ((double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[((int)dot_number) - 1].RawPosition.X);
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
	double wm_ir_dot_get_rawy(double dot_number)
	{
		try
		{
			return ((double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[((int)dot_number) - 1].RawPosition.Y);
		}
		catch(...)
		{
			return ( -1.0 );
		}
	}

	/// <summary>Normalized midpoint of IR sensors 1 and 2 only along the X-axis</summary>
	/// <remarks>Domain: [0.0,1.0]</remarks>
	/// <returns>Normalized X Midpoint</returns>
	double wm_ir_dot_get_midx()
	{
		return( (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.Midpoint.X );
	}
	/// <summary>Normalized midpoint of IR sensors 1 and 2 only along the Y-axis</summary>
	/// <remarks>Domain: [0.0,1.0]</remarks>
	/// <returns>Normalized Y Midpoint</returns>
	double wm_ir_dot_get_midy()
	{
		return( (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.Midpoint.Y );
	}

	/// <summary>Raw midpoint of IR sensors 1 and 2 only along the X-axis</summary>
	/// <remarks>Domain: [0,1023]</remarks>
	/// <returns>Raw X Midpoint</returns>
	double wm_ir_dot_get_rawmidx()
	{
		return ( (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.RawMidpoint.X );
	}

	/// <summary>Raw midpoint of IR sensors 1 and 2 only along the Y-axis</summary>
	/// <remarks>Domain: [0,767]</remarks>
	/// <returns>Raw Y Midpoint</returns>
	double wm_ir_dot_get_rawmidy()
	{
		return ( (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.RawMidpoint.Y );
	}

	/// <summary>Change in x value of the given dot</summary>
	/// <remarks>Domain: [0,1]</remarks>
	/// <param name="dot_number">Dot 1-4</param>
	/// <returns>Delta x</returns>
	double wm_ir_dot_get_delta_x(double dot_number)
	{
		int dot = (int)dot_number - 1;
		try
		{
			return (GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[dot].Position.X - GiiMote::gm->ir_last_pos[GiiMote::gm->wmIndex, dot].X);
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
	double wm_ir_dot_get_delta_y(double dot_number)
	{
		int dot = (int)dot_number - 1;
		try
		{
			return (GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[dot].Position.Y - GiiMote::gm->ir_last_pos[GiiMote::gm->wmIndex, dot].Y);
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
	double wm_ir_dot_get_delta_rawx(double dot_number)
	{
		int dot = (int)dot_number - 1;
		try
		{	
			return (GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[dot].RawPosition.X - GiiMote::gm->ir_last_raw_pos[GiiMote::gm->wmIndex, dot].X);
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
	double wm_ir_dot_get_delta_rawy(double dot_number)
	{
		int dot = (int)dot_number - 1;
		try
		{	
			return (GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.IRSensors[dot].RawPosition.Y - GiiMote::gm->ir_last_raw_pos[GiiMote::gm->wmIndex, dot].Y);
		}
		catch(...)
		{
			return ( -1.0 );
		}
	}

	/// <summary>Change in midx value</summary>
	/// <remarks>Domain: [0,1]</remarks>
	/// <returns>Delta midx</returns>
	double wm_ir_dot_get_delta_midx()
	{
		return ( double(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.Midpoint.X - GiiMote::gm->ir_last_mid_pos[GiiMote::gm->wmIndex].X) );
	}

	/// <summary>Change in midy value</summary>
	/// <remarks>Domain: [0,1]</remarks>
	/// <returns>Delta midy</returns>
	double wm_ir_dot_get_delta_midy()
	{
		return ( double(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.Midpoint.Y - GiiMote::gm->ir_last_mid_pos[GiiMote::gm->wmIndex].Y) );
	}

	/// <summary>Change in raw midx value</summary>
	/// <remarks>Domain: [0,1023]</remarks>
	/// <returns>Delta raw midx</returns>
	double wm_ir_dot_get_delta_rawmidx()
	{
		return ( double(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.RawMidpoint.X - GiiMote::gm->ir_last_rawmid_pos[GiiMote::gm->wmIndex].X) );
	}

	/// <summary>Change in raw midy value</summary>
	/// <remarks>Domain: [0,767]</remarks>
	/// <returns>Delta raw midy</returns>
	double wm_ir_dot_get_delta_rawmidy()
	{
		return ( double(GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->IRState.RawMidpoint.Y - GiiMote::gm->ir_last_rawmid_pos[GiiMote::gm->wmIndex].Y) );
	}

	/// <summary>X coordinate of the screen that the Wii Remote is pointing at</summary>
	/// <returns>X coordinate relative to screen</returns>
	double wm_ir_display_get_x()
	{
		return ((double)GiiMote::gm->ir_screen_pos[GiiMote::gm->wmIndex].X);
	}

	/// <summary>Y coordinate of the screen that the Wii Remote is pointing at</summary>
	/// <returns>Y coordinate relative to screen</returns>
	double wm_ir_display_get_y()
	{
		return ((double)GiiMote::gm->ir_screen_pos[GiiMote::gm->wmIndex].Y);
	}

