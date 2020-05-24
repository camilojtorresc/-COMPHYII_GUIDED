#include <iostream>
#include <cmath>
#include <fstream> // Para las clases ifstream y ofstream
#include <cstdlib> // Necesario para exit()
#include <string>  // Incluye la clase string
#include <iomanip> // Necesario para formatear

#define PI 3.14159265

using namespace std;

// declaración de la clase madre

class Circular
{
private:
  double radio;
  double frecuencia;
  double fase;
public:
  // variables temporales que van a ser necesarias en la clase hija
  double dift;
  double tiempo;
  double tiempoFinal;
  
  Circular(double=1, double=1, double=0.1, double=10, double=100, double=0);  // constructor
  ~Circular(); // destructor
  void xpos(); // función miembro que calcula la posición en x
  void ypos(); // función miembro que calcula la posición en y
};


// sección de implementación clase madre Circular

Circular::Circular(double r, double w, double dt,double t,double tfinal,double alpha) // constructor
{
  radio = r;
  frecuencia = w;
  dift = dt;
  tiempo = t;
  tiempoFinal = tfinal;
  fase = alpha;

  cout << "Se creó un objeto Circulo nuevo.\n";
}

Circular::~Circular()
{
  cout << "Se destruyó un objeto Circulo.\n";
}

void Circular::xpos() // función de implementación posición en x
{
  
  string x_position;
  x_position = "posicion_x.dat"; //pone al frente el nombre de archivo
  
  ofstream archivo_sal;

  archivo_sal.open(x_position.c_str());

  if (archivo_sal.fail())
    {
      std::cout << "El archivo no se abrió con éxito.\n";
      exit(1);
    }

  // establece los formatos del flujo de archivo de salida
  archivo_sal << setiosflags(ios::fixed)
	      << setiosflags(ios::showpoint)
	      << setprecision(3);
  
  for(tiempo = 0.0 ; tiempo <= tiempoFinal ; tiempo = tiempo + dift)
    {
      // envía datos al archivo
      archivo_sal << tiempo << ";" << radio*cos(frecuencia*tiempo+fase) << "\n";
    }
  
  return;
}

void Circular::ypos() // función de implementación posición en y
{
  string y_position;
  y_position = "posicion_y.dat"; //pone al frente el nombre de archivo
  
  ofstream archivo_sal;

  archivo_sal.open(y_position.c_str());

  if (archivo_sal.fail())
    {
      std::cout << "El archivo no se abrió con éxito.\n";
      exit(1);
    }

  // establece los formatos del flujo de archivo de salida
  archivo_sal << setiosflags(ios::fixed)
	      << setiosflags(ios::showpoint)
	      << setprecision(3);
  
  for(tiempo = 0.0 ; tiempo <= tiempoFinal ; tiempo = tiempo + dift)
    {
      // envía datos al archivo
      archivo_sal << tiempo << ";" << radio*sin(frecuencia*tiempo+fase) << "\n";
    }
  
  return;
}

// declaración para la clase hija

class Expiral : public Circular
{
 private:
  double zinicial;
  double velz;
 public:
  Expiral(double r=1, double w=1, double dt=0.1, double t=10, double tfinal=100, double alpha=0, double z0=0, double vz = 0) : Circular(r,w,dt,t,tfinal,alpha),zinicial(z0),velz(vz){}
  void zpos();
};

// sección de implementación para la clase hija Expiral
void Expiral::zpos()
{
  string z_position;
  z_position = "posicion_z.dat"; //pone al frente el nombre de archivo
  
  ofstream archivo_sal;

  archivo_sal.open(z_position.c_str());

  if (archivo_sal.fail())
    {
      std::cout << "El archivo no se abrió con éxito.\n";
      exit(1);
    }

  // establece los formatos del flujo de archivo de salida
  archivo_sal << setiosflags(ios::fixed)
	      << setiosflags(ios::showpoint)
	      << setprecision(3);
  
  for(tiempo = 0.0 ; tiempo <= tiempoFinal ; tiempo = tiempo + dift)
    {
      // envía datos al archivo
      archivo_sal << tiempo << "," << zinicial + velz*tiempo << "\n";
    }
  
  return;
}


int main()
{
  Expiral a(5,1,0.1,15,50,PI/3,5,3);
  
  a.xpos();
  a.ypos();
  a.zpos();
       
  return 0;
}
