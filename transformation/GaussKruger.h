#ifndef GaussConformalProjection_H
#define GaussConformalProjection_H

// C++ includes
#include <cmath>
#include <math.h>
#include <utility> // std::pair
#include <iostream>
#include <iomanip> //setprecision
#include <limits> //maxprecision

namespace GaussKruger
{

const long double deg_to_rad = M_PI / 180.0;
const long double rad_to_deg = 180.0 / M_PI;

// GRS 80 parameter values
const long double axis = 6378137.0;                 // equatorial radius
const long double flattening = 1.0 / 298.257222101; // (a-b)/a = (equatorial_radius - polar_radius) / equatorial_radius

// Sweref 99 18 00
const long double false_northing = 0.0;             // N_0
const long double false_easting = 150000.0;         // E_0
// Sweref 99 Planar parameters (Central meridian is passed as argument)

const long double scale = 1.0;

const long double e2 = flattening*(2.0 - flattening);   // epsilon^2 // first eccentricity squared
const long double n = flattening / (2.0 - flattening);  // second flattering n
const long double axis_hat = axis / (1 + n) * (1 + pow(n,2)/4.0 + pow(n,4)/64.0);

const long double A = e2;
const long double B = (5.0*pow(e2,2) - pow(e2,3))/6.0;
const long double C = (104.0*pow(e2,3) - 45.0*pow(e2,4))/120.0;
const long double D = (1237.0*pow(e2,4))/1260.0;

const long double beta1 = 0.5*n - 2.0*pow(n,2)/3.0 + 5.0*pow(n,3)/16.0 + 41.0*pow(n,4)/180.0;
const long double beta2 = 13.0*pow(n,2)/48.0 - 3.0*pow(n,3)/5.0 + 557.0*pow(n,4)/1440.0;
const long double beta3 = 61.0*pow(n,3)/240.0 - 103.0*pow(n,4)/140.0;
const long double beta4 = 49561.0*pow(n,4)/161280.0;

// inverse transform
const long double k0 = scale;

const double long A_star = e2 + pow(e2, 2) + pow(e2, 3) + pow(e2, 4);
const double long B_star = -1.0/6.0 * (7.0 * pow(e2,2) + 17.0 * pow(e2,3) + 30.0 * pow(e2,4));
const double long C_star = 1.0 / 120.0 * (224.0 * pow(e2,3) + 889.0 * pow(e2,4));
const double long D_star = -1.0 / 1260.0 * (4279.0 * pow(e2,4));

const double long delta1 = 0.5 * n - 2.0/3.0 * pow(n,2) + 37.0/96.0 * pow(n,3) - 1.0/360.0 * pow(n,4);
const double long delta2 = 1.0/48.0 * pow(n,2) + 1.0/15.0 * pow(n,3) - 437.0/1440.0 * pow(n,4);
const double long delta3 = 17.0/480.0 * pow(n,3) - 37.0/840.0 * pow(n,4);
const double long delta4 = 4397.0/161280.0 * pow(n,4);

/**
   * \brief Converts from geodesic to planar coordinates
   *
   * Takes longitude and latitude and converts them through SWEREF99
   * into planar coordinates.
   *
   * \param latitude 
   * \param longitude 
   * \param central_meridian The offset to be used for different regions
   * 
   */
std::pair <double, double> geo2plane(long double latitude, long double longitude, 
    long double central_meridian = 18.00);
std::pair <double, double> lat_lon_to_n_e(long double latitude, long double longitude);
std::pair <double, double> plane2geo_v2(double N, double E,
    long double central_meridian = 18.00);
std::pair <double, double> n_e_to_lat_lon(long double north, long double east);

} // End namespace

#endif
