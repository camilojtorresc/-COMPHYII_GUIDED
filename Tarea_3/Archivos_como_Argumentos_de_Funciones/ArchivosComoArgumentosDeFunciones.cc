// Crea y escribe en un archivo de texto 5  desde la terminal

#include <iostream> 
#include <fstream>  
#include <cstdlib>
#include <string>
using namespace std;

//Declara una función que recive un archivo de salida para abrir este
void getOpen(ofstream& salArchivo)
{
  string nombre;

  std::cout << "\nIntroduzca el nombre de un archivo en el que quiera escribir: ";
  getline(std::cin, nombre);

  salArchivo.open(nombre.c_str());

  if (salArchivo.fail()) // comprueba una apertura exitosa
    {
      std::cout << "No se pudo abrir el archivo\n";
      exit(1);
    }
  else
    {
    return;
    }
}

// Declara una función que recive un archivo de salida para escribir en este 
void inOut(ofstream& salArchivo)
{
  const int NUMLINEAS = 5; // número de líneas
  int cuenta;
  string linea;

  std::cout << "Por favor introduzca cinco líneas de texto.\n";

  for (cuenta = 0; cuenta < NUMLINEAS; cuenta++)
    {
      getline(std::cin, linea);
      salArchivo << linea << "\n";
    }
  std::cout << "\nEl archivo se ha escrito correctamente. \n";
  return;
}

int main()
{
  ofstream archivo_sal;   // da nombre a un archivo de salida

  getOpen(archivo_sal);   // abre el archivo de salida
  inOut(archivo_sal);     // escribe en el archivo de salida
  
  return 0;
}
