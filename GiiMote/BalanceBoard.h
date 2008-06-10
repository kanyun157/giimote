// BlanaceBoard.h - Contains functions to deal with the Balance Board (dummy Wii Remote
//					with dummy extension)

namespace GiiMoteLib {

	/// <summary>Total pounds on the balance board</summary>
	/// <returns>Total weight in pounds</returns>
	double GiiMote::wm_bb_get_weight_lbs()
	{
		float weight;

		try
		{
			weight = this->wc[wmIndex]->WiimoteState->BalanceBoardState.WeightLb;
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( (double)weight );
	}

	/// <summary>Total kilograms on the balance board</summary>
	/// <returns>Total mass in kilograms</returns>
	double GiiMote::wm_bb_get_weight_kgs()
	{
		float weight;

		try
		{
			weight = this->wc[wmIndex]->WiimoteState->BalanceBoardState.WeightKg;
		}
		catch(...)
		{
			return ( -1 );
		}

		return ( (double)weight );
	}

	/// <summary>Returns the raw value on the specified sensor</summary>
	/// <returns>Raw weight</returns>
	double GiiMote::wm_bb_get_sensor_raw(double sensor)
	{
		short weight;
		try
		{
			switch ((int)sensor)
			{
			case btmLeft:
				weight = this->wc[wmIndex]->WiimoteState->BalanceBoardState.SensorValuesRaw.BottomLeft;
				break;
			case btmRight:
				weight = this->wc[wmIndex]->WiimoteState->BalanceBoardState.SensorValuesRaw.BottomRight;
				break;
			case topLeft:
				weight = this->wc[wmIndex]->WiimoteState->BalanceBoardState.SensorValuesRaw.TopLeft;
				break;
			case topRight:
				weight = this->wc[wmIndex]->WiimoteState->BalanceBoardState.SensorValuesRaw.TopRight;
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
	/// <returns>Kilograms</returns>
	double GiiMote::wm_bb_get_sensor_kgs(double sensor)
	{
		float weight;
		try
		{
			switch ((int)sensor)
			{
			case btmLeft:
				weight = this->wc[wmIndex]->WiimoteState->BalanceBoardState.SensorValuesKg.BottomLeft;
				break;
			case btmRight:
				weight = this->wc[wmIndex]->WiimoteState->BalanceBoardState.SensorValuesKg.BottomRight;
				break;
			case topLeft:
				weight = this->wc[wmIndex]->WiimoteState->BalanceBoardState.SensorValuesKg.TopLeft;
				break;
			case topRight:
				weight = this->wc[wmIndex]->WiimoteState->BalanceBoardState.SensorValuesKg.TopRight;
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
	/// <returns>Pounds</returns>
	double GiiMote::wm_bb_get_sensor_lbs(double sensor)
	{
		float weight;
		try
		{
			switch ((int)sensor)
			{
			case btmLeft:
				weight = this->wc[wmIndex]->WiimoteState->BalanceBoardState.SensorValuesLb.BottomLeft;
				break;
			case btmRight:
				weight = this->wc[wmIndex]->WiimoteState->BalanceBoardState.SensorValuesLb.BottomRight;
				break;
			case topLeft:
				weight = this->wc[wmIndex]->WiimoteState->BalanceBoardState.SensorValuesLb.TopLeft;
				break;
			case topRight:
				weight = this->wc[wmIndex]->WiimoteState->BalanceBoardState.SensorValuesLb.TopRight;
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
	/// <return>Calibraiton info at 0kg</return>
	double GiiMote::wm_bb_get_calibration_kg0(double sensor)
	{
		short val;
		try
		{
			switch ( (int)sensor )
			{
			case btmLeft:
				val = this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg0.BottomLeft;
				break;
			case btmRight:
				val = this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg0.BottomRight;
				break;
			case topLeft:
				val = this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg0.TopLeft;
				break;
			case topRight:
				val = this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg0.TopRight;
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
	/// <return>Calibraiton info at 17kg</return>
	double GiiMote::wm_bb_get_calibration_kg17(double sensor)
	{
		short val;
		try
		{
			switch ( (int)sensor )
			{
			case btmLeft:
				val = this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg17.BottomLeft;
				break;
			case btmRight:
				val = this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg17.BottomRight;
				break;
			case topLeft:
				val = this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg17.TopLeft;
				break;
			case topRight:
				val = this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg17.TopRight;
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
	/// <return>Calibraiton info at 34kg</return>
	double GiiMote::wm_bb_get_calibration_kg34(double sensor)
	{
		short val;
		try
		{
			switch ( (int)sensor )
			{
			case btmLeft:
				val = this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg34.BottomLeft;
				break;
			case btmRight:
				val = this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg34.BottomRight;
				break;
			case topLeft:
				val = this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg34.TopLeft;
				break;
			case topRight:
				val = this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg34.TopRight;
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
	/// <return>Success</return>
	double GiiMote::wm_bb_set_calibration_kg0(double sensor, double val)
	{
		try
		{
			switch ( (int)sensor )
			{
			case btmLeft:
				this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg0.BottomLeft = (short)val;
				break;
			case btmRight:
				this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg0.BottomRight = (short)val;
				break;
			case topLeft:
				this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg0.TopLeft = (short)val;
				break;
			case topRight:
				this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg0.TopRight = (short)val;
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
	/// <return>Success</return>
	double GiiMote::wm_bb_set_calibration_kg17(double sensor, double val)
	{
		try
		{
			switch ( (int)sensor )
			{
			case btmLeft:
				this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg17.BottomLeft = (short)val;
				break;
			case btmRight:
				this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg17.BottomRight = (short)val;
				break;
			case topLeft:
				this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg17.TopLeft = (short)val;
				break;
			case topRight:
				this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg17.TopRight = (short)val;
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
	/// <return>Success</return>
	double GiiMote::wm_bb_set_calibration_kg34(double sensor, double val)
	{
		try
		{
			switch ( (int)sensor )
			{
			case btmLeft:
				this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg34.BottomLeft = (short)val;
				break;
			case btmRight:
				this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg34.BottomRight = (short)val;
				break;
			case topLeft:
				this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg34.TopLeft = (short)val;
				break;
			case topRight:
				this->wc[wmIndex]->WiimoteState->BalanceBoardState.CalibrationInfo.Kg34.TopRight = (short)val;
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

}