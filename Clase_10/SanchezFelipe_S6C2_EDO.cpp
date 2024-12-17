#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <valarray>


// dy/dt = f(t, y) = -y = -tn - k1/2

int main()
{
    const double T0 = 0.0;
    const double TF = 2.0;
    const double H = 0.01;

    const int N = int((TF - T0)/H);

    std::valarray<double> y_euler(N);
    std::valarray<double>y_rk(N);
    std::valarray<double> t(N);
    t[0] = T0;
    y_euler[0] = 1.0;
    y_rk[0] = 1.0;

    //Euler
    for (int i = 0; i < N-1; i++)
    {
        t[i+1] = t[i] + H;
        y_euler[i+1] = y_euler[i] - H*y_euler[i];
    }

    //RK4
    for (int i = 0; i < N-1; i++)
    {
        double k1 = -H*y_rk[i];
        double k2 = -H*(y_rk[i] + k1/2.0);
        double k3 = -H*(y_rk[i] + k2/2.0);
        double k4 = -H*(y_rk[i] + k3);

        y_rk[i+1] = y_rk[i] + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);
    }
    
    
    for (int i = 0; i < N; i++)
    {
        std::cout << t[i] << "\t" << y_euler[i] << "\t" << y_rk[i] << "\n";
    }
    

    return 0;
}





