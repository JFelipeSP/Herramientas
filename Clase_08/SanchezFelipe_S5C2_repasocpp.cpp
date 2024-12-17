#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <array>
/*
1) Inicializar dos variables globales (con valores escogidos por ustedes), una entera y otra flotante.


2) Imprimir los valores de las variables en un mensaje: "la primera tiene un valor de XX y la segunda variable tiene un valor de YY"

3) Calcular el valor de la segunda variable dividida por la primera e imprimir : "El resultado es ZZ" 

4) Crear un arreglo con 300 números enteros aleatorios entre 0 y 900. 
(ejemplos en: https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/ o https://www.cplusplus.com/reference/cstdlib/rand/ o rand - C++ Reference entre otros)

5) Hacer una iteración para recorrer dicho arreglo e imprimir todos sus elementos. 

6) Imprimir el quinto elemento del arreglo

7) Obtener la longitud del arreglo e imprimir: "la longitud del arreglo es XX" (use la función size(), mire cppreference)

8) Haga una función que reciba dos variables una flotante llamada mivarflotante y una entera llamada mivarentera y retorne la variable flotante dividida por la variable entera.    
                    
9) Llame su función desde la función main e imprima lo que retorna su función para mivarflotante=17.5 y mivarentera=5.

10) Haga una función que retorne el mínimo del arreglo de números aleatorios antes creado

11) Haga una función que reciba el arreglo de números aleatorios antes creado, imprima los números impares y pare de imprimir al encontrar un número mayor a 800

*/

int a = 2;
float b = 1.5;

float div_float_int(float mivarflotante, int mivarentera);
int min(int int_array[]);
void even_odd(int int_array[]);

int main()
{
    std::cout << "la primera tiene un valor de " << a << " y la segunda variable tiene un valor de " << b << "\n";
    float z = b/a;
    std::cout << "El resultado es " << z << "\n";

    int iarray[300];
    for (int i = 0; i < 300; i++)
    {
        iarray[i] = std::rand() % 901;
        std::cout << iarray[i] << ", ";
    }
    std::cout << "\n";
    
    std::cout << "quinto elemento: " << iarray[4] << "\n";
    int size = std::size(iarray);
    std::cout << "la longitud del arreglo es " << size << "\n";
    std::cout << "funcion(17.5, 5) = " << div_float_int(17.5, 5) << "\n";
    std::cout << "the minimum is " << min(iarray) << "\n";
    even_odd(iarray);

    return 0;
}


float div_float_int(float mivarflotante, int mivarentera)
{
    return mivarflotante/mivarentera;
}

int min(int int_array[])
{
    int minimum = int_array[0];
    for (int i = 1; i < 300; i++)
    {
        if (int_array[i] < minimum)
        {
            minimum = int_array[i];
        }  
    }

    return minimum;
}

void even_odd(int int_array[])
{
    for (int i = 0; i < 300; i++)
    {
        if (int_array[i]%2 == 1)
        {
            std::cout << int_array[i] << ", ";
        }
        
    }
    std::cout << "\n";
}


/*para ver mas ejemplos: https://www.w3schools.com/CPP/cpp_variables.asp*/





