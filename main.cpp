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

using namespace std;

#define numAlg 2;
typedef vecotr< vector<int> > matrix;

vector< List<int> > hashTable;


void readFile( const int i ) const
{
	//i ==> algoritmo
	//aqui llamaremos a las funciones que leen los ficheros de cada algoritmo
	switch( i ) {
		case 1:
			break;
		default:
			break;
	}	
}

void executeAlgorithm( const int i ) const
{
	switch( i ) {
		case 1:
			break;
		default:
			break;
	}
}


int main() {
	
	cout << "Introducir juego de pruebas con el diccionario(con extension .txt): ";
	string fileName;
	cin >> fileName;
	cout << endl;
	ifstream dicc( fileName.c_str() );
	cout << "Introducir juego de pruebas con la sopa de letras(con extension .txt): ";
	cin >> fileName;
	cout << endl;
	ifstream sl( fileName.c_str() );

	vector<int> diccionario;
	matrix sopaLetras;

	if( dicc and sl ) {
		string lineD, lineSL;
		while ( getline( dicc, lineD ) and getline( sl, lineSL ) ) {
			//rellenar diccionario y sopaLetras.
		}
	}
	dicc.close();
	sl.close();

	cout << "¿Algoritmo individual? (Si/No)";
	string aux;
	cin >> aux;
	if( aux == "Si" ) {
		cout << "Escoje uno de los siguientes (solo hace falta el número):";
		/* Todos los algorimtos numerados*/
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
	cout << endl;

}