/*Constantes del sistema
width = ancho del mapa.
height = alto del mapa.
numIterations = número máximo de iteraciones para la simulación.
millisecondsToWait = tiempo de espera en milisegundos entre generación y generación.
*/
const int width = 25, height = 25;
const int numIterations = 50;
const int millisecondsToWait = 1000;
#include <thread>
#include <iostream>

/*
						////////A ESCRIBIR////////
Función que sirve para buscar cuántos vecinos vivos tiene una célula concreta.

Recordad, vecinos son:

[NW][N][NE]
[ W][O][ E]
[SW][S][SE]

Recordad revisar los limites del mapa, no existe vecino en posiciones menores que 0 o 
mayores que witdh o height.

Tu posición no cuenta como vecino, no puedes utilizarte a ti mismo.

Parámetros:
x = posición x de la célula
y = posición y de la célula
map = mapa del juego.
Return:
Retorna la suma de celulas vivas que tiene de vecino esta célula. Si no tiene vecinos vivos retorna 0.
						////////A ESCRIBIR////////
*/
int checkNeightbours(int x, int y, const bool(&map)[width][height])
{
	return 0;
}

/*
Función para pintar el mapa.
O = célula viva.
# = célula muerta.
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
Función que inicializa el mapa para que todos los valores sean false(Muerto).
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
Función encargada de inicializar el mapa,
Se encarga de dibujar un patrón inicial concreto para que podáis ver 
la simulación que ha de hacer vuestro programa. 
Intentará colocar el patrón en el centro del mapa, si no hay espacio nos lanzará un mensaje por consola.
Sentiros libres de colocar el patrón que queráis y hacer las pruebas que queráis,
en internet podéis encontrar patrones muy interesantes. 
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
Función basada en el initShape original pero con la diferencia de que puede
spawnear ese patrón en un lugar específico del mapa. 
Si no hay espacio saltará un mensaje por pantalla y ejecutará el initShape original.
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

Función para copiar los datos de un mapa a otro.
Lo tenemos que utilizar para pasar los datos de la copia al mapa original
para la siguiente generación.

Parámetros:
source: mapa desde el que extraeremos los datos.
destinación: Mapa desde el que sobreescribiremos esos datos.
		////////A ESCRIBIR////////
*/
void copyMap(const bool(&source)[width][height], bool(&destination)[width][height])
{
	
}
int main()
{
	//Mapa actual (El que pintamos en cada iteración)
	bool map[width][height];
	//Copia de mapa, el que manipulamos cuando calculamos lo que ocurrirá con cada célula.
	bool mapCopy[width][height];

	initMap(map);
	/*initShape(map, 3, 2);*/
	initShape(map);
	copyMap(map, mapCopy);

	//Variable para guardar la información de la generación actual.
	int generation = 0;

	while (generation < numIterations)
	{
		paintMap(map);
		std::cout << "Generation number: " << generation << std::endl;

		////////A ESCRIBIR////////

		/*Tenéis que colocar todas las condiciones del juego de Conway aquí
		Recordad utilizar la función checkNeightbours para buscar los vecinos de cada célula.
		Recordad sobreescribir el mapCopy, pero realizar las condiciones sobre el map, el mapCopy
		es una copia del mapa para poder alterar el estado del mapa sin pervertir la información del mapa original
		Recordad que  debemos de iterar sobre cada célula en cada generación.
		*/
		////////A ESCRIBIR////////
		
		//sobreescribimos el mapa original, con el mapa alterado.
		copyMap(mapCopy, map);


		generation++;
		std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsToWait));

	}

}