/*Constantes del sistema
width = ancho del mapa.
height = alto del mapa.
numIterations = n�mero m�ximo de iteraciones para la simulaci�n.
millisecondsToWait = tiempo de espera en milisegundos entre generaci�n y generaci�n.
*/
const int width = 25, height = 25;
const int numIterations = 50;
const int millisecondsToWait = 1000;
#include <thread>
#include <iostream>

/*
						////////A ESCRIBIR////////
Funci�n que sirve para buscar cu�ntos vecinos vivos tiene una c�lula concreta.

Recordad, vecinos son:

[NW][N][NE]
[ W][O][ E]
[SW][S][SE]

Recordad revisar los limites del mapa, no existe vecino en posiciones menores que 0 o 
mayores que witdh o height.

Tu posici�n no cuenta como vecino, no puedes utilizarte a ti mismo.

Par�metros:
x = posici�n x de la c�lula
y = posici�n y de la c�lula
map = mapa del juego.
Return:
Retorna la suma de celulas vivas que tiene de vecino esta c�lula. Si no tiene vecinos vivos retorna 0.
						////////A ESCRIBIR////////
*/
int checkNeightbours(int x, int y, const bool(&map)[width][height])
{
	return 0;
}

/*
Funci�n para pintar el mapa.
O = c�lula viva.
# = c�lula muerta.
*/
void paintMap(bool(&map)[width][height])
{
	system("cls");
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (map[i][j]) std::cout << "O";
			else std::cout << "#";
		}
		std::cout << std::endl;
	}

}

/*
Funci�n que inicializa el mapa para que todos los valores sean false(Muerto).
*/
void initMap(bool(&map)[width][height])
{
	for (size_t i = 0; i < width; i++)
	{
		for (size_t j = 0; j < height; j++)
		{
			map[i][j] = false;
		}
	}
}
/*
Funci�n encargada de inicializar el mapa,
Se encarga de dibujar un patr�n inicial concreto para que pod�is ver 
la simulaci�n que ha de hacer vuestro programa. 
Intentar� colocar el patr�n en el centro del mapa, si no hay espacio nos lanzar� un mensaje por consola.
Sentiros libres de colocar el patr�n que quer�is y hacer las pruebas que quer�is,
en internet pod�is encontrar patrones muy interesantes. 
https://en.wikipedia.org/wiki/Conways_Game_of_Life
*/
void initShape(bool(&map)[width][height])
{
	
	int halfWidth = width / 2, halfHeight = height / 2;
	if (halfWidth - 2 < 0 || halfHeight - 2 < 0 || halfWidth + 1 >= width || halfHeight + 1 >= height) { std::cout << "Out Of Map, InitShape(default)" << std::endl; std::cin.get(); return; }
	map[halfWidth][halfHeight] = true;
	map[halfWidth + 1][halfHeight] = true;
	map[halfWidth - 1][halfHeight - 1] = true;
	map[halfWidth + 1][halfHeight - 1] = true;
	map[halfWidth + 1][halfHeight - 2] = true;





}

/*
Funci�n basada en el initShape original pero con la diferencia de que puede
spawnear ese patr�n en un lugar espec�fico del mapa. 
Si no hay espacio saltar� un mensaje por pantalla y ejecutar� el initShape original.
*/
void initShape(bool(&map)[width][height], int posX, int posY)
{
	

	if (posX - 2 < 0 || posY - 2 < 0 || posY + 1 >= width || posY + 1 >= height) { std::cout << "Out Of Map, calling Initshape default Instead" << std::endl; std::cin.get(); initShape(map); return; }
	map[posX][posY] = true;
	map[posX + 1][posY] = true;
	map[posX - 1][posY - 1] = true;
	map[posX + 1][posY - 1] = true;
	map[posX + 1][posY - 2] = true;
}

/*
		////////A ESCRIBIR////////

Funci�n para copiar los datos de un mapa a otro.
Lo tenemos que utilizar para pasar los datos de la copia al mapa original
para la siguiente generaci�n.

Par�metros:
source: mapa desde el que extraeremos los datos.
destinaci�n: Mapa desde el que sobreescribiremos esos datos.
		////////A ESCRIBIR////////
*/
void copyMap(const bool(&source)[width][height], bool(&destination)[width][height])
{
	
}
int main()
{
	//Mapa actual (El que pintamos en cada iteraci�n)
	bool map[width][height];
	//Copia de mapa, el que manipulamos cuando calculamos lo que ocurrir� con cada c�lula.
	bool mapCopy[width][height];

	initMap(map);
	/*initShape(map, 3, 2);*/
	initShape(map);
	copyMap(map, mapCopy);

	//Variable para guardar la informaci�n de la generaci�n actual.
	int generation = 0;

	while (generation < numIterations)
	{
		paintMap(map);
		std::cout << "Generation number: " << generation << std::endl;

		////////A ESCRIBIR////////

		/*Ten�is que colocar todas las condiciones del juego de Conway aqu�
		Recordad utilizar la funci�n checkNeightbours para buscar los vecinos de cada c�lula.
		Recordad sobreescribir el mapCopy, pero realizar las condiciones sobre el map, el mapCopy
		es una copia del mapa para poder alterar el estado del mapa sin pervertir la informaci�n del mapa original
		Recordad que  debemos de iterar sobre cada c�lula en cada generaci�n.
		*/
		////////A ESCRIBIR////////
		
		//sobreescribimos el mapa original, con el mapa alterado.
		copyMap(mapCopy, map);


		generation++;
		std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsToWait));

	}

}