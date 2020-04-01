#include <iostream>
#include <fstream>  // para las clases ifstream y ofstream
#include <cstdlib>  // necesario para exit
#include <string>   // incluye la clase string
using namespace std;
int main()
{
  string archivoUno = "info.txt"; // pone al frente el nombre del archivo
  string archivoDos = "info.bak";
  char ch;
  ifstream archivo_entr;
  ofstream archivo_sal;

  try // este bloque trata de abrir el archivo de entrada, sino, devuelve un error
    {
      // abre un flujo de entrada básico
      archivo_entr.open(archivoUno.c_str());
      
      if (archivo_entr.fail())
	{
	  throw archivoUno;
	}
    }//fin del bloque try exterior
  catch (string entrar) // catch para el bloque try exterior
    {
      std::cout << "El archivo de entrada " << entrar
		<< " no se abrió con éxito." << "\n"
		<< " No se hizo el respaldo." << "\n";
      exit(1) ;
    }

  try // este bloque trata de abrir el archivo de salida y ejecuta el procesamiento del archivo
    {
      archivo_sal.open(archivoDos.c_str());

      if (archivo_sal.fail())
	{
	  throw archivoDos;
	}
      // Escribe en el archivo de salida mientras el caracter en el archivo de entrada no sea EOF (Caracter especial que denota el final de un archivco de datos)   
      while ((ch = archivo_entr.get()) != EOF)
	{
	  archivo_sal.put(ch);  // Pone un caracter en el archivo de salida
	  archivo_sal.put('.'); // Pone el caracter "." en el archivo de salida
	}

      archivo_entr.close();
      archivo_sal.close();
    }
  
  catch (string salir) //catch para el anterior bloque try
    {
      cout << "El archivo de respaldo " << salir
	   << " no se abrió con éxito.\n";
      exit(1);
    }

  cout << "Un respaldo exitoso de " << archivoUno
       << " llamado " << archivoDos << " se realizó correctamente, separando cada caracter con un punto.\n";
  return 0;
}
