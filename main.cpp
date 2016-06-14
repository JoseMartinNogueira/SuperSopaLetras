#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <time.h>
#include <iomanip>
#include <locale>
#include <sstream>
#include <list> 
#include "Tools.cpp"

using namespace std;
/*
#define numAlg 2;
typedef vecotr< vector<int> > matrix;

vector< List<int> > hashTable;

void executeAlgorithm( const int i ) const
{
	switch( i ) {
		case 1:
			break;
		default:
			break;
	}
}
*/

int main() {
	
	input x;
	Tools tot;
	tot.generar("holis2", 10, 2, 4, 100);


	tot.lectura(x);
	cout << x.min << ' ' << x.max << ' ' << x.porcentaje << endl;
	for (int i = 0; i < x.D.size(); ++i) {
		cout << ' ' << x.D[i];
	}
	cout << endl;

/*
	cout << "¿Algoritmo individual? (Si/No)";
	string aux;
	cin >> aux;
	if( aux == "Si" ) {
		cout << "Escoje uno de los siguientes (solo hace falta el número):";
		//Todos los algoritmos numerados
		cout << endl;
		int i;
		cin >> i;
		executeAlgorithm(i);
	}
	else {
		for( int i = 0; i < numAlg; ++i ) {
			executeAlgorithm(i);
		}
	}
	cout << endl;*/

}