#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <valarray>

// dy/dt = v, dv/dt = -w²*y

int main()
{
    const double T0 = 0.0;
    const double TF = 2.0;
    const double M = 0.2;
    const double K = 50.0;
    const double H = 0.01;

    const int N = int((TF - T0)/H);
    double t = T0;
    const double W2 = K/M;

    std::valarray<double> y_euler(2);
    y_euler[0] = 0.1; // x0
    y_euler[1] = 0.0; // v0

    std::valarray<double> y_LF(2);
    y_LF[0] = 0.1; // x0
    y_LF[1] = 0.0; // v0

    std::cout << t << "\t" << y_euler[0] << "\t" << y_euler[1] << "\n";

    //Euler
    for (int i = 0; i < N; i++)
    {
        t = t + H;
        y_euler[0] = y_euler[0] + H*y_euler[1];
        y_euler[1] = y_euler[1] - H*W2*y_euler[0];

        std::cout << t << "\t" << y_euler[0] << "\t" << y_euler[1] << "\n";
    }


    //Leap-Frog
    y_LF[1] = y_LF[1] - 0.5*H*W2*y_LF[0];
    for (int i = 0; i < N; i++)
    {
        t = t + H;
        y_LF[0] = y_LF[0] + H*y_LF[1];
        y_LF[1] = y_LF[1] - H*W2*y_LF[0];

        std::cout << t << "\t" << y_LF[0] << "\t" << y_LF[1] << "\n";
    }

    return 0;
}