// GMMath.h - Contains mathematical functions required for the use of the Wii Remote.
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

	/// <summary>Checks a number against the given domain</summary>
	/// <remarks>Use -1 for infinity</remarks>
	/// <param name="x">The value to check</param>
	/// <param name="d1">The minimum value</param>
	/// <param name="d2">The maximum value</param>
	/// <returns>The closest number to x in the given domain</returns>
	double in_domain(double x, double d1, double d2)
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
	double domain_rescale(double val, double minin, double maxin, double minout, double maxout)
	{
		return (( ( ( (val - minin) / (maxin - minin) ) * (maxout - minout) ) + minout ));
	}
