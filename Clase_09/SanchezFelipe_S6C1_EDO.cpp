
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <valarray>


// dy/dt = f(t, y) = -y

int main()
{
    const double T0 = 0.0;
    const double TF = 2.0;
    const double H = 0.01;

    const int N = int((TF - T0)/H);

    std::valarray<double> y(N);
    std::valarray<double> t(N);
    t[0] = T0;
    y[0] = 1.0;

    //Euler
    for (int i = 0; i < N-1; i++)
    {
        t[i+1] = t[i] + H;
        y[i+1] = y[i] - H*y[i];
    }
    
    for (int i = 0; i < N; i++)
    {
        std::cout << t[i] << "\t" << y[i] << "\n";
    }
    

    return 0;
}





