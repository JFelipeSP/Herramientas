#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <valarray>
#include <fstream>
#include <string>

// FMm/r² = ma

void euler_solve(std::string fname, std::valarray<double> x, std::valarray<double> y, double ti, double tf, double g, double m1, double m2, double h);
void euler_2bodies_solve(std::string fname, std::valarray<double> x1, std::valarray<double> y1, std::valarray<double> x2, std::valarray<double> y2, double ti, double tf, double g, double m1, double m2, double h);


int main()
{
    const double T0 = 0.0;
    const double TF = 3.0; // years
    const double M_earth = 1.0; // Earth Masses
    const double M_sun = 332942.75; 
    const double G = 1.185e-4;
    const double H = 0.01;

    std::valarray<double> X_earth(2);
    X_earth[0] = 1.0; // x0 [AU]
    X_earth[1] = 0.0; // vx0 [AU/yr]
    std::valarray<double> Y_earth(2);
    Y_earth[0] = 0.0; // y0
    Y_earth[1] = 6.286; //vy0

    std::valarray<double> X_sun(2);
    X_sun[0] = 0.0;
    X_sun[1] = 0.0;
    std::valarray<double> Y_sun(2);
    Y_sun[0] = 0.0;
    Y_sun[1] = 0.0;

    //Euler
    std::string out_euler = "Earth_euler.dat";
    euler_solve(out_euler, X_earth, Y_earth, T0, TF, G, M_earth, M_sun, H);

    std::string out_euler_2 = "SunEarth_euler.dat";
    euler_2bodies_solve(out_euler_2, X_earth, Y_earth, X_sun, Y_sun, T0, TF, G, M_earth, M_sun, H);
    

    //Leap-FroG
    //double r2_earth = std::pow(X_earth[0], 2.0) + std::pow(Y_earth[0], 2.0);
    double r2 = std::pow(X_earth[0]-X_sun[0], 2.0) + std::pow(Y_earth[0]-Y_sun[0], 2.0);
    X_earth[1] = X_earth[1] - 0.5*(H*G*M_sun*(X_earth[0]-X_sun[0]))/(std::pow(r2, 3.0/2.0)); // vx0 shift
    Y_earth[1] = Y_earth[1] - 0.5*(H*G*M_sun*(Y_earth[0]-Y_sun[0]))/(std::pow(r2, 3.0/2.0)); // vy0 shift
    X_sun[1] = X_sun[1] - 0.5*(H*G*M_earth*(X_sun[0]-X_earth[0]))/(std::pow(r2, 3.0/2.0));
    Y_sun[1] = Y_sun[1] - 0.5*(H*G*M_earth*(Y_sun[0]-Y_earth[0]))/(std::pow(r2, 3.0/2.0));

    std::string out_LF = "Earth_LF.dat";
    euler_solve(out_LF, X_earth, Y_earth, T0, TF, G, M_earth, M_sun, H);

    std::string out_LF_2 = "SunEarth_LF.dat";
    euler_2bodies_solve(out_LF_2, X_earth, Y_earth, X_sun, Y_sun, T0, TF, G, M_earth, M_sun, H);
    


    return 0;
}


void euler_solve(std::string fname, std::valarray<double> x, std::valarray<double> y, double ti, double tf, double g, double m1, double m2, double h)
{
    const int n = int((tf - ti)/h);
    std::ofstream euler_out;
    euler_out.open(fname);
    euler_out << ti << "\t" << x[0] << "\t" << y[0] << "\t" << x[1] << "\t" << y[1] << "\n";

    for (int i = 0; i < n; i++)
    {
        ti = ti + h;
        x[0] = x[0] + h*x[1];
        y[0] = y[0] + h*y[1];
        double r2 = std::pow(x[0], 2.0) + std::pow(y[0], 2.0);
        
        x[1] = x[1] - (h*g*m2*x[0])/(std::pow(r2, 3.0/2.0));
        y[1] = y[1] - (h*g*m2*y[0])/(std::pow(r2, 3.0/2.0));

        euler_out << ti << "\t" << x[0] << "\t" << y[0] << "\t" << x[1] << "\t" << y[1] << "\n";
    }
    euler_out.close();
}

void euler_2bodies_solve(std::string fname, std::valarray<double> x1, std::valarray<double> y1, std::valarray<double> x2, std::valarray<double> y2, double ti, double tf, double g, double m1, double m2, double h)
{
    const int n = int((tf - ti)/h);
    std::ofstream euler_out;
    euler_out.open(fname);
    euler_out << ti << "\t" << x1[0] << "\t" << y1[0] << "\t" << x2[0] << "\t" << y2[0] << "\t"
                            << x1[1] << "\t" << y1[1] << "\t" << x2[1] << "\t" << y2[1] << "\n";

    for (int i = 0; i < n; i++)
    {
        ti = ti + h;
        x1[0] = x1[0] + h*x1[1];
        y1[0] = y1[0] + h*y1[1];

        x2[0] = x2[0] + h*x2[1];
        y2[0] = y2[0] + h*y2[1];

        double r2 = std::pow(x1[0]-x2[0], 2.0) + std::pow(y1[0]-y2[0], 2.0);

        x1[1] = x1[1] - (h*g*m2*(x1[0]-x2[0]))/(std::pow(r2, 3.0/2.0));
        y1[1] = y1[1] - (h*g*m2*(y1[0]-y2[0]))/(std::pow(r2, 3.0/2.0));

        x2[1] = x2[1] - (h*g*m1*(x2[0]-x1[0]))/(std::pow(r2, 3.0/2.0));
        y2[1] = y2[1] - (h*g*m1*(y2[0]-y1[0]))/(std::pow(r2, 3.0/2.0));

        euler_out << ti << "\t" << x1[0] << "\t" << y1[0] << "\t" << x2[0] << "\t" << y2[0] << "\t"
                                << x1[1] << "\t" << y1[1] << "\t" << x2[1] << "\t" << y2[1] << "\n";

    }
    euler_out.close();

}


