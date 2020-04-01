#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
  int number1 = 3987565;
  
  std::string string1 = "Hola a todos";
  std::string string2 = "Hola a nadie";

  std::cout << "El string1 es: " << string1 << "\n"
	    << "El string2 es: " << string2 << "\n"
	    << "El número es:  " << number1 << "\n\n";
  
  //Longitud de un string string string.length() o string.size()
  std::cout << "Longitud del string1 es: " <<  string1.length() << "\n";
  std::cout << "Longitud del string2 es: " <<  string2.length() << "\n";
  std::cout << "Longitud del número es: " << std::to_string(number1).length() << "\n\n";

  std::cout << "El cuarto caracter del string1 es: ";
  //Devuelve el caracter del número especificado std::string.at(int index)
  std::cout << string1.at(3) << "\n\n";

  std::cout << "comparando el 'tamaño' del string1 con el string2: " 
  //Comparar dos "tamaños" entre dos strings std::string1.compare()
	    << string1.compare(string2) << "\n\n";

  std::cout << "Devolver el string1 terminado en null el string1: "
  //Devuelve el string como una cadena de C terminada en null
	    << string1.c_str() << "\n\n";

  std::cout << "¿El string1 está vacío?: \n";
  if(string1.empty()) //Devuelve true si el string está vacío; sino devuelve false
    {
      std::cout << "El string1 está vacío." << "\n\n";
    }
  else
    {
      std::cout << "El string1 no está vacío y es: " << string1 << "\n\n";
    }

  std::cout << "Eliminando cuatro caracteres desde el cuarto caracter del string1: " 
  //Elimina n caracteres de la cadena empezando en ind std::string.erase(ind, n)
	    << string1.erase(3, 4) << "\n\n";

  string1 = "Hola a todos";
  std::cout << "Eliminando todos los caracteres desde el sexto caracter, el string1 es: "
    //Elimina todos los caracteres desde el ind std::string.erase(ind)
	    << string1.erase(6) << "\n\n";

  string1 = "Hola a todos";
  std::cout << "El primer caracter 'o' se encuentra en la posición: "
    //Encuentra la posición del primer caracter deseado en el string1
	    << string1.find("o") + 1  << "\n";

  std::cout << "El primer caracter 't' se encuentra en la posición: "
    //Encuentra la posición del primer caracter deseado en el string1
	    << string1.find("t") + 1 << "\n\n";

  std::cout << "Eliminando 5 caracteres desde el 6to caracter y añadiendo el string ' ustede' en el string1: "
    //Elimina n caracteres comenzando en ind por el tring str std::string.replace(ind, n, str)
	    << string1.replace(6, 5, " ustede") << "\n\n";

  string1 = "Hola a todos";
  //Intercambia los caracteres con el objeto str std::string.swap(str)
  string1.swap(string2);
  std::cout << "El string1 ahora es : " << string1 << "\n\n";

  std::cout << "Otra forma de hallar el caracter en la cuarta posición en el string1 es: "
  //Devuelve el caracter en el índice string[ind]
	    << string1[3] << "\n\n";
 
  return 0;
}
