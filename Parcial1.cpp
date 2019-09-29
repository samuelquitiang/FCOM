#include <iostream> //Se incluye libreria para entrada y salida de datos
#include <vector> //Se incluye libreria para manejo de vectores
#include <cstdlib>
#include <unistd.h>
using namespace std; //Esta linea sirve para no tener que llamar cada vez a iostream

class Matriz   //Defino la clase Matriz, que va a ser la encargada de generar la matriz nxn.
{
public:         // Definimos las cantidades de la clase, que en este caso son públicas para tener acceso a ellas desde cualquier otro lugar.
  int filas;    // Definimos las filas de la matriz como un número entero.
  int columnas; // Definimos las columnas de la matriz como un número entero. 
  int vecinos0; // Definimos los vecinos que tienen valor 0.
  int vecinos1; // Definimos los vecinos que tienen valor 1.
  int vecinos2; // Definimos los vecinos que tienen valor 2.
  
  vector<vector<int> > matriz; // Definimos el vector que se va a convertir en la matriz nxn.

  Matriz(int f, int c);            //Defino la matriz donde sus entradas son f=filas, c=columnas.
  int analizarvecinos0(int posf,int posc);  // Definimos una función entera que analiza las posiciones de los vecinos, si estan en
                                      //filas (posf) y si estan en columnas (posc).
  int analizarvecinos1(int posf, int posc);
  int analizarvecinos2(int posf, int posc);
  void Mostrar();                  //Definimos una función que muestre en pantalla la organización de las células.
  void ciclo();                    //Definimos una función que hace evolucionar el sistema.
};

Matriz::Matriz(int f, int c)  // Creamos una instancia de la clase que forme una matriz de números aleatorios.
{
  filas = f;              // Redefinimos el nombre de las filas.
  columnas = c;           // Redefinimos el nombre de las columnas.
  matriz.resize(filas);   // Al vector que habia creado anteriormente le doy la longitud de las filas de la matriz por lo que ahora tengo
                          // un vector matriz = [x1,x2,...,xn].
  for (int i=0; i<matriz.size(); i++)  // Hacemos un for para agregar las columnas a la matriz.
    {
      matriz[i].resize(columnas);      // Aquí es donde juntamos las columnas con las filas para obtener la matriz nxn
    }

  for (int f=0; f<filas; f++)          // Hacemos un for sobre las filas para variar los posibles valores de las posiciones.
    {
      for (int c=0; c<columnas; c++)   // Hacemos un for sobre las columnas para variar los posibles valores de las posiciones.
	{
	  matriz[f][c] = rand()%3;      //Agrego un valor aleatorio a cada elemento de la matriz, números aleatorios entre 0 y 2.
	}
    }
}

void Matriz::Mostrar()                 // Creamos una instancia de la clase que muestra en pantalla la forma de la matriz
{
  for (int f=0; f<filas; f++)          // Ciclo que recorre las filas.
    {
      for (int c; c<columnas; c++)     // Ciclo que recorre las columnas.
	{
	  if (matriz[f][c] == 1)       // Si esta viva una célula de la especie 1
	    {
	      cout << "*";            // Muestre en pantalla "*"
	    }
	  else if (matriz[f][c] == 2)       // Si esta viva una célula de la especie 2
	    {
	      cout << "# ";            // Muestre en pantalla "#"
	    }
	  else                         // Si la célula esta muerta
	    {
	      cout << ". ";             // Muestre en pantalla "."
	    }
	}
      cout << "\n";                    // Deje un espacio a la hora de mostrar en pantalla.
    }
}

// Hasta aquí hemos definido la clase que contiene la matriz nxn. En lo que sigue definiremos los métodos que la hacen evolucionar
// de acuerdo a las reglas estipuladas.

int Matriz::analizarvecinos0(int posf,int posc)         // Aquí definimos los posibles valores de los vecinos.                                 
{
  vecinos0 = 0;               // Para inicializar los vecinos que tengan valor 0.                                                              
  if(posf-1 >=0 and posc-1 >= 0) //Se mira si el vecino que esta en la posicion (posf-1,posc-1) esta dentro de la matriz (existe)
    {
      if(matriz[posf-1][posc-1] == 0) //Se ve si el vecino en esa pocision tiene valor 0
        {
          vecinos0++; //Si tiene valor de 0 se añade uno al contador
        }
    }
  if(posf-1 >= 0) //Se mira si el vecino que esta en la posicion (posf-1,posc) esta dentro de la matriz (existe)
    {
      if(matriz[posf-1][posc] == 0)
        {
          vecinos0++; //Si tiene valor de 0 se añade uno al contador
        }
    }
  if(posf-1 >= 0 and posc+1 <= columnas-1)//Se mira si el vecino que esta en la posicion (posf-1,posc+1) esta dentro de la matriz (existe)
    {
      if(matriz[posf-1][posc+1] == 0)
        {
          vecinos0++; //Si tiene valor de 0 se añade uno al contador
        }
    }
  if(posc-1 >= 0)//Se mira si el vecino que esta en la posicion (posf,posc-1) esta dentro de la matriz (existe)
    {
      if(matriz[posf][posc-1] == 0)
        {
          vecinos0++; //Si tiene valor de 0 se añade uno al contador
        }
    }
  if(posc+1 <= columnas -1)//Se mira si el vecino que esta en la posicion (posf,posc+1) esta dentro de la matriz (existe)
    {
      if(matriz[posf][posc+1] == 0)
        {
          vecinos0++; //Si tiene valor de 0 se añade uno al contador
        }
    }
   if(posf+1 <= filas-1 and posc-1 >= 0)//Se mira si el vecino que esta en la posicion (posf+1,posc-1) esta dentro de la matriz (existe)
    {
      if(matriz[posf+1][posc-1] == 0)
        {
          vecinos0++; //Si tiene valor de 0 se añade uno al contador
        }
    }
  if(posf+1 <= filas-1)//Se mira si el vecino que esta en la posicion (posf+1,posc) esta dentro de la matriz (existe)
    {
      if(matriz[posf+1][posc] == 0)
        {
          vecinos0++; //Si tiene valor de 0 se añade uno al contador
        }
    }
  if(posf+1 <= filas-1 and posc+1 <= columnas-1)//Se mira si el vecino que esta en la posicion (posf+1,pos+1) esta dentro de la matriz (existe)
    {
      if(matriz[posf+1][posc+1] == 0)
        {
          vecinos0++; //Si tiene valor de 0 se añade uno al contador
        }
    }
  return vecinos0;
}


int Matriz::analizarvecinos1(int posf,int posc)         // Aquí definimos los posibles valores de los vecinos.
{
  vecinos1 = 0;               // Para inicializar los vecinos que tengan valor 1.
  if(posf-1 >=0 and posc-1 >= 0)
    {
      if(matriz[posf-1][posc-1] == 1)
	{
	  vecinos1++;
	}
    }
  if(posf-1 >= 0)
    {
      if(matriz[posf-1][posc] == 1)
	{
	  vecinos1++;
	}
    }
  if(posf-1 >= 0 and posc+1 <= columnas-1)
    {
      if(matriz[posf-1][posc+1] == 1)
	{
	  vecinos1++;
	}
    }
  if(posc-1 >= 0)
    {
      if(matriz[posf][posc-1] == 1)
	{
	  vecinos1++;
	}
    }
  if(posc+1 <= columnas -1)
    {
      if(matriz[posf][posc+1] == 1)
	{
	  vecinos1++;
	}
    }
  if(posf+1 <= filas-1 and posc-1 >= 0)
    {
      if(matriz[posf+1][posc-1] == 1)
	{
	  vecinos1++;
	}
    }
  if(posf+1 <= filas-1)
    {
      if(matriz[posf+1][posc] == 1)
	{
	  vecinos1++;
	}
    }
  if(posf+1 <= filas-1 and posc+1 <= columnas-1)
    {
      if(matriz[posf+1][posc+1] == 1)
	{
	  vecinos1++;
	}
    }
  return vecinos1;
}

int Matriz::analizarvecinos2(int posf, int posc)
{
  vecinos2 = 0;               // Para inicializar los vecinos que tengan valor 2.                                                              
  if(posf-1 >=0  and posc-1 >= 0)
    {
      if(matriz[posf-1][posc-1] == 2)
        {
          vecinos2++;
        }
    }
  if(posf-1 >= 0)
    {
      if(matriz[posf-1][posc] == 2)
        {
          vecinos2++;
        }
    }
  if(posf-1 >= 0 and posc+1 <= columnas-1)
    {
      if(matriz[posf-1][posc+1] == 2)
        {
          vecinos2++;
	}
    }
  if(posc-1 >= 0)
    {
      if(matriz[posf][posc-1] == 2)
        {
          vecinos2++;
        }
    }
  if(posc+1 <= columnas -1)
    {
      if(matriz[posf][posc+1] == 2)
        {
          vecinos2++;
        }
    }
  if(posf+1 <= filas-1 and posc-1 >= 0)
    {
      if(matriz[posf+1][posc-1] == 2)
        {
          vecinos2++;
        }
    }
  if(posf+1 <= filas-1)
    {
      if(matriz[posf+1][posc] == 2)
        {
          vecinos2++;
        }
    }
  if(posf+1 <= filas-1 and posc+1 <= columnas-1)
    {
      if(matriz[posf+1][posc+1] == 2)
        {
          vecinos2++;
        }
    }
  return vecinos2;

}

void Matriz::ciclo()       // Aquí definimos las reglas estipuladas.
{
  vector <vector<int> > nuevo = matriz;    // Definimos una nueva matriz despues de evolucionar.
    for (int f=0; f<filas; f++)           // Ciclo que recorre todas las filas.
      {
	for (int c=0; c<columnas; c++)    // Ciclo que recorre todas las columnas.
	  {
	    int n_vecinos0 = analizarvecinos0(f,c);  // Defino los nuevos vecinos llamando la función anterior.
	    int n_vecinos1 = analizarvecinos1(f,c);
	    int n_vecinos2 = analizarvecinos2(f,c);
	    if(matriz[f][c] == 0)               // Elemento con valor 0
	      {
		if(vecinos1 == 3 and vecinos0 >= 2)  // Condición de que si hay 3 vecinos con valor 1 y 2 o más con valor 0
		  {
		    nuevo[f][c] = 1;                // Su valor cambia a 1.
		  }
		else if(vecinos2 == 4 and vecinos0 >= 1)  // Condición de que si hay 4 vecinos con valor 2 y 1 o más vecinos con valor 0
		  {
		    nuevo[f][c] = 2;                // Su valor cambia a 1.
		  }
	      }
	    if (matriz[f][c] == 1)                 // Elemento con valor 1.
	      {
		if(vecinos1 == 2 || vecinos1 == 3) // Condición de que si tiene 2 o 3 vecinos con valor 1
		  {
		    nuevo[f][c] = 1;               // conserve su valor de 1.
		  }
		else
		  {
		    if(vecinos2 <=4 and vecinos1 == 1)  // Condición de que si tiene al menos 4 vecinos con valor dos y 1 vecino con valor 1
		      {
			nuevo[f][c] = 2;               // Su valor cambia a 2.
		      }
		    else if(vecinos1 <=5)                   // Condición de que si tiene al menos 5 vecinos con valor 1
		      {
			nuevo[f][c] = 0;               // Su valor cambia a 0.
		      }
		  }
	      }
	    if (matriz[f][c] == 2)                 // Elemento con valor 2.
	      {
		if(vecinos2 == 2 || vecinos2 == 3) // Condición de que si tiene 2 o 3 vecinos con valor 2
		  {
		    nuevo[f][c] = 2;               // Conserve su valor 2.
		  }
		else
		  {
		    if(vecinos1 == 4 || vecinos1 == 5 and vecinos2==1) // Condición de tener 4 o 5 vecinos con valor 1 y uno con valor 2.
		      {
			nuevo[f][c] = 1;               // Su valor cambia a 1.
		      }
		    else if(vecinos2 == 5)                  // COndición de tener 5 vecinos con valor de 2
		      {
			nuevo[f][c] = 0;               // Su valor cambia a 0
		      }
		  }
	      }
	  }
      }
  matriz = nuevo;
}


int main()        // Comienza la función principal
{
  srand(time(NULL));  // Hace uso del reloj interno del computador para cambiar el valor inicial para generar una secuancia de números
                      // enteros semi-aleatorios.
  int N;
  cout << "Ingrese el tamaño de la matriz : " << endl;
  cin >> N;
  
  Matriz matriz(N,N); // Le da el tamaño a la matriz con el valor que ingresemos.

  while(true)  //Siempre que dibuje la matriz, espera un tiempo, borra y dibuja una nueva configuración.
    {
      matriz.Mostrar();
      usleep(100);
      system("cls");
      matriz.ciclo();
    }

}
