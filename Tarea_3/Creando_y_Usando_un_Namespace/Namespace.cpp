//Crear tu propio namespace:


#include <iostream>
#include <string>
#include <math.h>

using namespace std;

namespace CompararNumeros
{
  double division;
  void Comparar(double a,double b)
  {
    
    if (b==0)
      {
	if (a>0)
	  {
	    std::cout << "El número " << a << " es mayor que el número " << b <<"\n";
	  }
        else if (a<0)
	  {
	    std::cout << "El número " << a << " es menor que el número " << b <<"\n";
	  }
	else
	  {
	    std::cout << "Los números " << a << " y " << b << " son iguales \n";
	  }
      }
    else
      {
	division = a/b;
	
	if (division==0)
	  {
	    if (b>0)
	      {
		std::cout << "El número " << a << " es menor que el número " << b <<"\n";
	      }
	    else
	      {
		std::cout << "El número " << a << " es mayor que el número " << b <<"\n";
	      }
	  }
	else if (division>0)
	  {
	    if (division==1)
	      {
		std::cout << "Los números " << a << " y " << b << " son iguales \n";
	      }
	    else if (division< 1 && a>0 && b>0)
	      {
		std::cout << "El número " << a << " es menor que el número " << b <<"\n";
	      }
	    else if (division<1 && a<0 && b<0)
	      {
		std::cout << "El número " << a << " es mayor que el número " << b <<"\n";
	      }
	    else if (division > 1 && a>0 && b>0)
	      {
	    std::cout << "El número " << a << " es mayor que el número " << b <<"\n";
	      }
	    else if(division>1 && a<0 && b<0)
	      {
		std::cout << "El número " << a << " es menor que el número " << b <<"\n";
	      }
	  }
	else if (division<0)
	  {
	    if (abs(division)==1)
	      {
		std::cout << "Los números " << a << " y " << b << " son iguales \n";
	      }
	  
	    else if (abs(division)< 1 && a>0 && b>0)
	      {
		std::cout << "El número " << a << " es mayor que el número " << b <<"\n";
	      }
	    else if (abs(division)<1 && a<0 && b<0)
	      {
		std::cout << "El número " << a << " es menor que el número " << b <<"\n";
	      }
	    else if (abs(division) > 1 && a>0 && b>0)
	      {
	    std::cout << "El número " << a << " es menor que el número " << b <<"\n";
	      }
	    else if(abs(division)>1 && a<0 && b<0)
	      {
		std::cout << "El número " << a << " es mayor que el número " << b <<"\n";
	      }
	    
	  }
      
      }
  }
}// fin del namespace
