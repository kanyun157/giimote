// BlanaceBoard.h - Contains functions to deal with the Balance Board (dummy Wii Remote
//					with dummy extension)
// Copyright 2007 Sam Whited
//
//    This file is part of GiiMote.
//
//    GiiMote is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Lesser General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    GiiMote is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Lesser General Public License for more details.
//
//    You should have received a copy of the GNU Lesser General Public License
//    along with GiiMote.  If not, see <http://www.gnu.org/licenses/>.

	/// <summary>Total pounds on the balance board</summary>
	/// <returns>Total weight in pounds</returns>
	double wm_bb_get_weight_lbs()
	{
		float weight;
		try
		{
			weight = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.WeightLb;
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( (double)weight );
	}

	/// <summary>Total kilograms on the balance board</summary>
	/// <returns>Total mass in kilograms</returns>
	double wm_bb_get_weight_kgs()
	{
		float weight;
		try
		{
			weight = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.WeightKg;
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( (double)weight );
	}

	/// <summary>Calculates the center of gravity of the ojbect on the balance board</summary>
	/// <returns>X value of the center of gravity of the object on the balance board</returns>
	double wm_bb_get_center_of_gravity_x()
	{
		return ( (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CenterOfGravity.X );
	}

	/// <summary>Calculates the center of gravity of the ojbect on the balance board</summary>
	/// <returns>Y value of the center of gravity of the object on the balance board</returns>
	double wm_bb_get_center_of_gravity_y()
	{
		return ( (double)GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CenterOfGravity.Y );
	}

	/// <summary>Returns the raw value on the specified sensor</summary>
	/// <param name="sensor">The sensor to read from</param>
	/// <returns>Raw weight</returns>
	double wm_bb_get_sensor_raw(double sensor)
	{
		short weight;
		try
		{
			switch ((int)sensor)
			{
			case btmLeft:
				weight = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.SensorValuesRaw.BottomLeft;
				break;
			case btmRight:
				weight = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.SensorValuesRaw.BottomRight;
				break;
			case topLeft:
				weight = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.SensorValuesRaw.TopLeft;
				break;
			case topRight:
				weight = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.SensorValuesRaw.TopRight;
				break;
			default:
				throw;
				break;
			}
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( (double)weight );
	}

	/// <summary>Returns the kilograms on the specified sensor</summary>
	/// <param name="sensor">The sensor to read from</param>
	/// <returns>Kilograms</returns>
	double wm_bb_get_sensor_kgs(double sensor)
	{
		float weight;
		try
		{
			switch ((int)sensor)
			{
			case btmLeft:
				weight = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.SensorValuesKg.BottomLeft;
				break;
			case btmRight:
				weight = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.SensorValuesKg.BottomRight;
				break;
			case topLeft:
				weight = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.SensorValuesKg.TopLeft;
				break;
			case topRight:
				weight = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.SensorValuesKg.TopRight;
				break;
			default:
				throw;
				break;
			}
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( (double)weight );
	}

	/// <summary>Returns the pounds on the specified sensor</summary>
	/// <param name="sensor">The sensor to read from</param>
	/// <returns>Pounds</returns>
	double wm_bb_get_sensor_lbs(double sensor)
	{
		float weight;
		try
		{
			switch ((int)sensor)
			{
			case btmLeft:
				weight = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.SensorValuesLb.BottomLeft;
				break;
			case btmRight:
				weight = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.SensorValuesLb.BottomRight;
				break;
			case topLeft:
				weight = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.SensorValuesLb.TopLeft;
				break;
			case topRight:
				weight = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.SensorValuesLb.TopRight;
				break;
			default:
				throw;
				break;
			}
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( (double)weight );
	}

	//////////////////
	// Calibration
	//////////////////

	/// <summary>Gets calibration info for a given sensor</summary>
	/// <param name="sensor">The sensor to read from</param>
	/// <return>Calibraiton info at 0kg</return>
	double wm_bb_get_calibration_kg0(double sensor)
	{
		short val;
		try
		{
			switch ( (int)sensor )
			{
			case btmLeft:
				val = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg0.BottomLeft;
				break;
			case btmRight:
				val = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg0.BottomRight;
				break;
			case topLeft:
				val = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg0.TopLeft;
				break;
			case topRight:
				val = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg0.TopRight;
				break;
			default:
				throw;
				break;
			}
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( (double)val );
	}

	/// <summary>Gets calibration info for a given sensor</summary>
	/// <param name="sensor">The sensor to read from</param>
	/// <return>Calibraiton info at 17kg</return>
	double wm_bb_get_calibration_kg17(double sensor)
	{
		short val;
		try
		{
			switch ( (int)sensor )
			{
			case btmLeft:
				val = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg17.BottomLeft;
				break;
			case btmRight:
				val = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg17.BottomRight;
				break;
			case topLeft:
				val = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg17.TopLeft;
				break;
			case topRight:
				val = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg17.TopRight;
				break;
			default:
				throw;
				break;
			}
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( (double)val );
	}

	/// <summary>Gets calibration info for a given sensor</summary>
	/// <param name="sensor">The sensor to read from</param>
	/// <return>Calibraiton info at 34kg</return>
	double wm_bb_get_calibration_kg34(double sensor)
	{
		short val;
		try
		{
			switch ( (int)sensor )
			{
			case btmLeft:
				val = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg34.BottomLeft;
				break;
			case btmRight:
				val = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg34.BottomRight;
				break;
			case topLeft:
				val = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg34.TopLeft;
				break;
			case topRight:
				val = GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg34.TopRight;
				break;
			default:
				throw;
				break;
			}
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( (double)val );
	}

	/// <summary>Sets 0kg calibration info for a given sensor</summary>
	/// <param name="sensor">The sensor to use</param>
	/// <param name="val">The calibration data</param>
	/// <return>Success</return>
	double wm_bb_set_calibration_kg0(double sensor, double val)
	{
		try
		{
			switch ( (int)sensor )
			{
			case btmLeft:
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg0.BottomLeft = (short)val;
				break;
			case btmRight:
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg0.BottomRight = (short)val;
				break;
			case topLeft:
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg0.TopLeft = (short)val;
				break;
			case topRight:
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg0.TopRight = (short)val;
				break;
			default:
				throw;
				break;
			}
		}
		catch(...)
		{
			return ( 0 );
		}

		return ( 1 );
	}

	/// <summary>Sets 17kg calibration info for a given sensor</summary>
	/// <param name="sensor">The sensor to use</param>
	/// <param name="val">The calibration data</param>
	/// <return>Success</return>
	double wm_bb_set_calibration_kg17(double sensor, double val)
	{
		try
		{
			switch ( (int)sensor )
			{
			case btmLeft:
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg17.BottomLeft = (short)val;
				break;
			case btmRight:
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg17.BottomRight = (short)val;
				break;
			case topLeft:
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg17.TopLeft = (short)val;
				break;
			case topRight:
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg17.TopRight = (short)val;
				break;
			default:
				throw;
				break;
			}
		}
		catch(...)
		{
			return ( 0 );
		}

		return ( 1 );
	}

	/// <summary>Sets 34kg calibration info for a given sensor</summary>
	/// <param name="sensor">The sensor to use</param>
	/// <param name="val">The calibration data</param>
	/// <return>Success</return>
	double wm_bb_set_calibration_kg34(double sensor, double val)
	{
		try
		{
			switch ( (int)sensor )
			{
			case btmLeft:
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg34.BottomLeft = (short)val;
				break;
			case btmRight:
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg34.BottomRight = (short)val;
				break;
			case topLeft:
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg34.TopLeft = (short)val;
				break;
			case topRight:
				GiiMote::gm->wc[GiiMote::gm->wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg34.TopRight = (short)val;
				break;
			default:
				throw;
				break;
			}
		}
		catch(...)
		{
			return ( 0 );
		}

		return ( 1 );
	}
