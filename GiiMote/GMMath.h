// GMMath.h - Contains mathematical functions required for the use of the Wii Remote.

namespace GiiMoteLib {
	/// <summary>Checks a number against the given domain</summary>
	/// <remarks>Use -1 for infinity</remarks>
	/// <param name="x">The value to check</param>
	/// <param name="d1">The minimum value</param>
	/// <param name="d2">The maximum value</param>
	/// <returns>The closest number to x in the given domain</returns>
	double GiiMote::in_domain(double x, double d1, double d2)
	{
		double val = x;
		if (x > d2 && d2 != -1) { val = d2; } // -1 = infinity.
		if (x < d1) { val = d1; }

		return (val);
	}

	/// <summary>Rescales a value from one domain to another</summary>
	/// <param name="val">The value to rescale</param>
	/// <param name="minin">The minimum of the input domain</param>
	/// <param name="maxin">The maximum of the input domain</param>
	/// <param name="minout">The minimum of the output domain</param>
	/// <param name="maxout">The maximum of the output domain</param>
	/// <returns>The rescaled value</returns>
	double GiiMote::domain_rescale(double val, double minin, double maxin, double minout, double maxout)
	{
		return (( ( ( (val - minin) / (maxin - minin) ) * (maxout - minout) ) + minout ));
	}

} // namespace GiiMoteLib