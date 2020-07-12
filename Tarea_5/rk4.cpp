#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

namespace RungeKutta
{
  
  void rk4 ( void dydt ( double t, double *u, double *f ), double tspan[2], 
	     double *y0, int n, int m, double *t, double *y )
  /*
    dydt: lado derecho del sistema de ecuaciones.
    tspan[2]: tiempo inicial y tiempo final.
    y0: condiciones iniciales
    n: número de divisiones totales de intervalo
    m: número de ecuaciones diferenciales
    t: tiempo
    y: soluciones
   */
  {
    double dt;  // 

    // conjunto de funciones necesarias para aplicar el método
    double *f0;
    double *f1;
    double *f2;
    double *f3;

    // números para contar
    int i;
    int j;

    // tiempos necesarios para la implementación del método
    double t0;
    double t1;
    double t2;
    double t3;

    // números que se calculan necesarios para la implementación del método
    double *u0;
    double *u1;
    double *u2;
    double *u3;


    // inicialización dinámica de los apuntadores
    f0 = new double[m];
    f1 = new double[m];
    f2 = new double[m];
    f3 = new double[m];
    u0 = new double[m];
    u1 = new double[m];
    u2 = new double[m];
    u3 = new double[m];


    //implementación del método RK4
    dt = ( tspan[1] - tspan[0] ) / ( double ) ( n );
    
    j = 0;
    t[0] = tspan[0];

    
    for ( i = 0; i < m; i++ )
      {
	y[i+j*m] = y0[i];
      }
    
    for ( j = 0; j < n; j++ )
      {
	t0 = t[j];
	
	for ( i = 0; i < m; i++ )
	  {
	    u0[i] = y[i+j*m];
	  }
	
	dydt ( t0, u0, f0 );
	
	t1 = t0 + dt / 2.0;
	
	for ( i = 0; i < m; i++ )
	  {
	    u1[i] = u0[i] + dt * f0[i] / 2.0;
	  }
	
	dydt ( t1, u1, f1 );
	
	t2 = t0 + dt / 2.0;
	for ( i = 0; i < m; i++ )
	  {
	    u2[i] = u0[i] + dt * f1[i] / 2.0;
	  }
	dydt ( t2, u2, f2 );
	
	t3 = t0 + dt;
	
	for ( i = 0; i < m; i++ )
	  {
	    u3[i] = u0[i] + dt * f2[i];
	  }
	
	dydt ( t3, u3, f3 );
	
	t[j+1] = t[j] + dt;
	
	for ( i = 0; i < m; i++ )
	  {
	    y[i+(j+1)*m] = u0[i] + dt * ( f0[i] + 2.0 * f1[i] + 2.0 * f2[i] + f3[i] ) / 6.0;
	  }
	
      }

    //liberar memoria dinámica
    
    delete [] f0;
    delete [] f1;
    delete [] f2;
    delete [] f3;
    delete [] u0;
    delete [] u1;
    delete [] u2;
    delete [] u3;
    
    return;
  }
  
} // final del namespace
