#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Este programa halla el determinante de dos tipos de matrices una 2x2 o 3x3,
//ingresando los valores de las matrices a mano.

//Esta función halla el determinante de una matriz 2x2
double det2(double a, double b, double c, double d)
{
  double det22 = a*d-c*b;
  return det22;
}

//Esta función halla el determinante de una matriz 3x3
double det3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33)
{
  double det33 = a11*det2(a22,a23,a32,a33)-a21*det2(a12,a13,a32,a33)+a31*det2(a12,a13,a22,a23);
  return det33; 
}

int main()
{
  int dim_matriz;
  double num1, num2, num3, num4, num5, num6, num7, num8, num9;
  
  cout << "Ingrese 2 si desea hallar el determinante de una matriz 2x2.\n"
       << "ingrese 3 si desea hallar el determinante de una matriz 3x3.\n";
  cin >> dim_matriz;
  cout << "\n---------------------------------------------------------------------\n\n";
  
  // Calcula el determinante si la matriz es 2x2
  if(dim_matriz == 2)
    {
      //Ingresar los valores de la matriz 2x2 a mano
      cout << "Ingrese los elementos de la matriz 2x2.\n\n"
	   << "| a11   a12 |\n"
	   << "| a21   a22 |\n\n"
	   << "a11 = ";
      cin >> num1;
      cout << "a12 = ";
      cin >> num2;
      cout << "a21 = ";
      cin >> num3;
      cout << "a22 = ";
      cin >> num4;
      

      cout << "\nEl determinante de la matriz 2x2 es: " << det2(num1, num2, num3, num4) << "\n\n"
	   << "---------------------------------------------------------------------\n\n";
    }
  // Calcula el determinante si la matriz es 3x3
  else if(dim_matriz == 3)
    {
      //Ingresa los valores de la matriz 3x3 a mano
      cout << "Ingrese los elementos de la matriz 3x3.\n\n"
	   << "| a11   a12   a13 |\n"
	   << "| a21   a22   a23 |\n"
	   << "| a31   a32   a33 |\n\n"
	   << "a11 = ";
      cin >> num1;
      cout << "a12 = ";
      cin >> num2;
      cout << "a13 = ";
      cin >> num3;
      cout << "a21 = ";
      cin >> num4;
      cout << "a22 = ";
      cin >> num5;
      cout << "a23 = ";
      cin >> num6;
      cout << "a31 = ";
      cin >> num7;
      cout << "a32 = ";
      cin >> num8;
      cout << "a33 = ";
      cin >> num9;

      cout << "\nEl determinante de la matriz 3x3 es: " << det3(num1, num2, num3, num4, num5, num6, num7, num8, num9) << "\n\n"
	   << "---------------------------------------------------------------------\n\n";
    }
  
  else
    {
      //Muestra un mensaje de error si se escoje otro valor para la dimensión de la matriz
      cout << "¡Error!\nEste programa solo sirve para hallar determinantes de matrices 2x2 o 3x3." << endl;
    }
  
  return 0;
}
