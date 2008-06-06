// Joystick.h - Contains functions to use joysticks that expand the functionality
//				of the Wii Remote.

namespace GiiMoteLib {

	/////////////////////////
	// General
	/////////////////////////

	/// <summary>Calculates the direction of a joystick</summary>
	/// <param name="xx">The normalized X value of the joystick</param>
	/// <param name="yy">The normalized Y value of the joystick</param>
	/// <returns>The direction of the Joystick in degrees</returns>
	double GiiMote::joystick_direction(double xx, double yy)
	{
		return ( System::Math::Atan2(yy,xx) * ( 180 / System::Math::PI ) );
	}

	/// <summary>Calculates the pressure on a joystick</summary>
	/// <param name="xx">The normalized X value of the joystick</param>
	/// <param name="yy">The normalized Y value of the joystick</param>
	/// <returns>The pressure on the joystick</returns>
	double GiiMote::joystick_pressure(double xx, double yy)
	{
		return ( System::Math::Sqrt( System::Math::Pow(xx, 2) + System::Math::Pow(yy, 2) ) * 2 );
	}

	/// <summary>Sets the dead-zone value</summary>
	/// <remarks>Domain: [0.0,0.5]</remarks>
	/// <param name="val">The dead-zone value</param>
	/// <returns>1</returns>
	double GiiMote::wm_set_joystick_dead_zone(double val)
	{
		this->joystick_dead_zone = in_domain(val, 0, 0.5);
		return ( 1 );
	}

	/// <summary>Gets the dead-zone value</summary>
	/// <returns>Joystick dead-zone value</returns>
	double GiiMote::wm_get_joystick_dead_zone()
	{
		return ( this->joystick_dead_zone );
	}

} // namespace GiiMoteLib