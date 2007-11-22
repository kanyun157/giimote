// GMMath.h - Contains mathematical functions required for the use of the Wii Remote.

namespace GiiMoteLib {
	
	double GiiMote::in_domain(double x, double d1,double d2)
	{
		double val = x;
		if (x > d2 && d2 != -1) { val = d2; } // -1 = infinity.
		if (x < d1) { val = d1; }

		return (val);
	}

} // namespace GiiMoteLib