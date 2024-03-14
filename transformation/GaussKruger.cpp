#include <GaussKruger.h>

std::pair <double, double> GaussKruger::geo2plane(long double latitude, 
    long double longitude, long double central_meridian)
{
    
    long double phi = latitude * deg_to_rad;
    long double lambda = longitude * deg_to_rad;
    long double lambda_zero = central_meridian * deg_to_rad;
    long double phi_star = phi - sin(phi)*cos(phi)*(A + 
                        B*pow(sin(phi),2) + 
                        C*pow(sin(phi),4) + 
                        D*pow(sin(phi),6));

    long double delta_lambda = lambda - lambda_zero;
    long double xi = atan(tan(phi_star) / cos(delta_lambda));
    long double eta = atanh(cos(phi_star) * sin(delta_lambda));
    double y = scale * axis_hat * (xi +
                    beta1 * sin(2.0 * xi) * cosh(2.0 * eta) +
                    beta2 * sin(4.0 * xi) * cosh(4.0 * eta) +
                    beta3 * sin(6.0 * xi) * cosh(6.0 * eta) +
                    beta4 * sin(8.0 * xi) * cosh(8.0 * eta)) +
                    false_northing;
    double x = scale * axis_hat * (eta +
                    beta1 * cos(2.0 * xi) * sinh(2.0 * eta) +
                    beta2 * cos(4.0 * xi) * sinh(4.0 * eta) +
                    beta3 * cos(6.0 * xi) * sinh(6.0 * eta) +
                    beta4 * cos(8.0 * xi) * sinh(8.0 * eta)) +
                    false_easting;

    // x is east & y is north
    return {x,y};                         
}

std::pair <double, double> GaussKruger::lat_lon_to_n_e(long double latitude, 
    long double longitude)
{
    std::pair <double, double> result_e_n = geo2plane(latitude, longitude);
    return {result_e_n.second, result_e_n.first};
}

std::pair <double, double> GaussKruger::plane2geo_v2(double N, double E, 
    long double central_meridian)
{
    // as described in https://www.lantmateriet.se/globalassets/geodata/gps-och-geodetisk-matning/gauss_conformal_projection.pdf
    double long xi = (N - false_northing) / (k0 * axis_hat);
    double long nu = (E - false_easting) / (k0 * axis_hat);


    double long xi_tick = xi - delta1 * sin(2*xi) * cosh(2*nu)
                 - delta2 * sin(4*xi) * cosh(4*nu)
                 - delta3 * sin(6*xi) * cosh(6*nu)
                 - delta4 * sin(8*xi) * cosh(8*nu);
    double long nu_tick = nu - delta1 * cos(2*xi) * sinh(2 * nu)
                 - delta2 * cos(4*xi) * sinh(4 * nu)
                 - delta3 * cos(6*xi) * sinh(6 * nu)
                 - delta4 * cos(8*xi) * sinh(8 * nu);

    double long phi_star = asin(sin(xi_tick) / cosh(nu_tick));
    double long delta_lambda = atan(sinh(nu_tick) / cos(xi_tick));


    double long phi = phi_star + sin(phi_star) * cos(phi_star) * 
        (A_star 
        + B_star * pow(sin(phi_star),2) 
        + C_star * pow(sin(phi_star),4) 
        + D_star * pow(sin(phi_star),6) );
    
    double long lambda_zero = central_meridian * deg_to_rad;
    double long lambda = lambda_zero + delta_lambda;

    return{rad_to_deg*phi, rad_to_deg*lambda};
}

std::pair <double, double> GaussKruger::n_e_to_lat_lon(long double north, long double east)
{
    return plane2geo_v2(north, east);
}
