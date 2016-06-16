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
#include "hashTable.cpp"
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
void coutHashes() {
	cout << "Selecciona una de los siguientes funciones de hash(indicando el numero):" << endl;
	cout << "(1)" << endl;
	cout << "(2)" << endl;
	cout << "(3)" << endl;
	cout << "(4)" << endl;
	cout << "(5)" << endl;
	cout << "(6)" << endl;
	cout << "(7)" << endl;
}


int main(int argc, char *argv[]) {


	/*__________________INFORMACION PROBLEMA_____________________*/
/*
	string nombreDiccionario;
	string nombreTablero;

	if (argc == 1) {
		cout << "Nombre del fichero que contiene el diccionario:" << endl;
		cin >> nombreDiccionario;
		cout << "Nombre del fichero que contiene el tablero:" << endl;
		cin >> nombreTablero;
	}
	else if(argc == 3) {
		nombreDiccionario = argv[1];
		nombreDiccionario = argv[2];
	}
	else {
		cout << endl << endl;
		cout << "Uso: nombreDiccionario nombreTablero" << endl;
		cout << "\t - nombreDiccionario 'nombre del fichero que contiene el diccionario'" << endl;
		cout << "\t - nombreTablero 'nombre del fichero que contiene el tablero'" << endl;
		cout << endl;
		return 0;
	}

	cout << "Seleciona criterio de busqueda(indica el numero):" << endl;
	cout << "\t(1) Explorando las posibilidad de que un patron de posiciones contiguas en el tablero contenga una palabra del diccionario." << endl;
	cout << "\t(2) Examinando la posibilidad de que una palabra del diccionario este o no en el tablero." << endl;
	int criterio;
	cin >> criterio;

	cout << "Seleciona criterio de obtención de palabras de la supa(indica el numero):" << endl;
	cout << "\t(1) BFS." << endl;
	cout << "\t(2) DFS." << endl;
	int bfsdfs;
	cin >> bfsdfs;

	cout << "Seleciona el metoro de busqueda(indica el numero):" << endl;
	cout << "\t(1) linearProbing." << endl;
	cout << "\t(2) cuckooHashing" << endl;
	cout << "\t(3) doubleHashing" << endl;
	cout << "\t(4) BloomHashing" << endl;
	cout << "\t(5) Busqueda Binaria" << endl;
	int metodo;
	cin >> metodo;

	int hash1 = -1;
	int hash2 = -1;
	switch (metodo) {
		case 1:
			coutHashes();;
			cin >> hash1;
			break;
		case 2:
			cout << "HASH 1 -->";
			coutHashes();
			cin >> hash1;
			cout << "HASH 2 -->";
			coutHashes();
			cin >> hash2;
			break;
		case 3:
			cout << "HASH 1 -->";
			coutHashes();
			cin >> hash1;
			cout << "HASH 2 -->";
			coutHashes();
			cin >> hash1;
			break;
	}
*/
	/*__________________CONSTRUCCION PROBLEMA_____________________*/
	//lectura de Diccionario y tablero
	Tools H;
	input P;
	//H.leerDiccionario(nombreDiccionario, P);
	//H.leerTablero(nombreTablero,P);
	//Construccion de la estructura de hash
	H.leerDiccionario("d", P);
	hashTable HT;

	HT.createHashTable(P.D, 1);
	for (auto a : HT.getHashTable()) {
		for(auto b : a) cout << " " << b;
		cout << endl;
	}
	cout<< endl;
	

}
