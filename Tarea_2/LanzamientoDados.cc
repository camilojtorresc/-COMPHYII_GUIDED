#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
using namespace std;

//This program simulates two dices to play a gamble game

int dinero, dado1, dado2, suma_dados, apuesta, salida;

int SumaDados()
{
  //Calculate the random numbers for the dices and the sume of its
  srand(time(NULL));
  dado1 = int(((double) rand() / RAND_MAX)*6.0+1);
  dado2 = int(((double) rand() / RAND_MAX)*6.0+1);
  suma_dados = dado1 + dado2;
  
  return suma_dados;
}

void Apuesta()
{
  dinero = 10;
  cout << "\nTienes 10 monedas";
  
  do
    {
      cout << "\n\n¿Cuánto dinero deseas apostar?\n"
	   << "(Si ingresa un valor de 0 monedas se retirará del juego):\n";
      cin >> apuesta;
      
      if (apuesta<=dinero && apuesta>0)
	{
	  
	  //Gamble and play with the dices
	  dinero = dinero - apuesta;
	  SumaDados();
	  
	  //Tells when someone wins the game
	  if(suma_dados==7 || suma_dados==11)
	    {
	      cout << "\n--------------------------------------------------------------------------------------\n"
		   << "\n¡Felicidades.! La suma de los dados fue: " << suma_dados
		   << "\nHas ganado " << apuesta << " monedas.\n\n";
	      dinero = dinero + 2*apuesta;
	      cout << "Tienes un total de " << dinero << " monedas.\n";
		   
	    }
	  
	  else if (dinero == 0)
	    {
	      cout << "\nLa suma de los dados fue: " << suma_dados << endl;
	      salida = 1; 
	      break;
	    }
	  
	  else
	    {
	      cout << "\n--------------------------------------------------------------------------------------\n"
		   << "\n¡Buen intento!. La suma de los dados fue: " << suma_dados
		   << "\nHas perdido.\n\n"
		   << "Tienes un total de " << dinero << " monedas.\n";
		   
	    }

	
	}
      
      
      else if(apuesta == 0)
	{
	  cout<< "\n--------------------------------------------------------------------------------------\n"
	      << "\nTe has retirado del juego. ¡Vuelve pronto!\n";
	  break;
	}
      
      else if(apuesta<0)
	{ 
	  cout<< "\n--------------------------------------------------------------------------------------\n"
	      << "\nNo puedes apostar un número de monedas negativas. Tienes " << dinero << "monedas.\n"
	      << "\n¡Apuesta nuevamente!\n";
	}
      
      else
	{ 
	  cout<< "\n--------------------------------------------------------------------------------------\n"
	      << "\nNo tienes suficientes monedas para apostar (Actualmente tienes " << dinero << " monedas).\n"
	      << "¡Apuesta nuevamente!\n";
	}
      
  }while(dinero < 20);
  if(salida==1)
    {
      cout << "\nHas perdido todo tu dinero. ¡Vuelve Pronto!\n\n";
    }
  else
    {
      cout << "\nTe has retirado con " << dinero << " monedas.\n\n" << endl;
    }
  return;
}

int main()
{
  
  cout << "\nEste es un juego de apuestas que consta en lanzar dos dados.\n\n"
       << "Reglas: \n"
       << "1. Se empieza con un total de 10 monedas.\n"
       << "2. Solo se puede apostar un máximo de 10 monedas.\n"
       << "3. Se gana cuando la suma de los dos dados lanzados sumen 11 o 7.\n"
       << "4. Al ganar se duplica el total de dinero apostado.\n"
       << "5. Al momento de ganar 20 o más monedas el juego se acaba.\n"
       << "6. Se puede retirar en cualquier momento del juego antes de hacer una nueva apuesta.\n"
       << "7. Si apuesta 0 monedas se retira del juego.\n"
       << "\n--------------------------------------------------------------------------------------\n";
  
  Apuesta();
  return 0;
}
