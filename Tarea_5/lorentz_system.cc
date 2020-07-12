#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "rk4.cpp"

// prototipos de funciones necesarias
void rk4_lorentz();    
void lorentz_deriv( double t, double *u, double *f);
void lorentz_data(int n, int m, double *t, double *y);

int main()
{
  
  rk4_lorentz();

  return 0;
}

void rk4_lorentz() // función para aplicar el método RK4 al sistema de Lorentz
{
  int m = 3;
  int n = 10000;
  double *t;
  double tspan[2];
  double *y;
  double *y0;

  t = new double[n+1];
  y = new double[(n+1)*m];
  y0 = new double[m];

  tspan[0] = 0.0;
  tspan[1] = 100.0;
  
  y0[0] = 0.0;
  y0[1] = 1.0;
  y0[2] = 0.0;

  RungeKutta::rk4(lorentz_deriv, tspan, y0, n, m, t, y);

  lorentz_data(n, m, t, y);
  
  // Liberar espacio en la memoria.
  delete [] t;
  delete [] y;
  delete [] y0;
  
  return;
}

void lorentz_deriv(double t, double *y, double *f)
//función que determina a qué funciones equivalen los lados derechos de las ODEs
{
  double dxdt;
  double dydt;
  double dzdt;

  double X;
  double Y;
  double Z;

  X = y[0];
  Y = y[1];
  Z = y[2];

  double sigma = 10.0;
  double beta = 8/3;
  double alpha = sqrt((4/beta) - 1);
  double ro = 28.0;
  double kappa = 0.35;

  dxdt = -sigma*X+sigma*Y;
  dydt = -X*Z+ro*X-Y; 
  dzdt =  X*Y-beta*Z;

  f[0] = dxdt;
  f[1] = dydt;
  f[2] = dzdt;
  
  return;
}

void lorentz_data(int n, int m, double *t, double *y)
//función que sirve para crear un archivo de texto con la solución a las ODEs 
{
  string data_filename;
  data_filename = "data_lorentz.txt";
  
  ofstream output_data;

  output_data.open(data_filename.c_str());

  // para crear el archivo de datos
  for(int g = 0; g <= n; g++)
    {
      output_data << t[g]
		  << ";" << y[0+g*m]
		  << ";" << y[1+g*m]
		  << ";" << y[2+g*m] << "\n";
    }
    
  return;
}
