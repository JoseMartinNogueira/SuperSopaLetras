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
	int alg;
	cout << "1) Hash de diccionario" <<endl;
	cout << "2) Hash de la tabla" <<endl;
	cin >> alg;
	if( alg == 1 ) {
		Tools H;
		input P;
		P.contador = 0;
		H.leerDiccionario("d", P);
		hashTable HT;

		coutHashes();
		int numFHash;

		cin >> numFHash;

		HT.createHashTable(P.D, numFHash);
		for( auto a : HT.getHashTable() ) {
			for( auto b : a ) {
				cout << "    " << b;
			}
			cout << endl;
		}

		H.leerTablero("t", P);

		cout << P.min << " " << P.max << " " << P.porcentaje << endl;
		cout << "---------------------------" << endl;
		for (auto i : P.D) cout << " " << i;
		cout << endl;
		cout << "---------------------------" << endl;
		for (auto i : P.T) {
			for(auto j : i) cout << " " << j;
			cout << endl;
		}
		cout << "---------------------------" << endl;
		H.setTime(0.1);
		H.partidaPrimerCriterio(P, HT, numFHash);

		cout << endl << "---------------:  "<< P.contador << endl;

		cout << "comp: " << HT.getComparacionesH() << endl;

		cout << "tiempo Construccion: " << HT.getTConstruccionH() << endl;

		cout << "tiempo BFS: " << H.getTBusqueda() << endl;

		cout << "tiempo total: " << H.getTTotal() << endl;


		cout << "------------RESTANTES---------------" << endl;
		for( auto a : HT.getHashTable() ) {
			for( auto b : a ) {
				cout << "    " << b ;
			}
			cout << endl;
		}
	}
	else if( alg == 2) {
		Tools H;
		input P;
		P.contador = 0;
		H.leerDiccionario("d", P);
		hashTable HT;

		coutHashes();
		int numFHash;

		cin >> numFHash;

		H.leerTablero("t", P);
		HT.createHashTable( P.T );
		for( auto a : HT.getHashTable() ) {
			for( auto b : a ) {
				cout << "    " << b;
			}
			cout << endl;
		}

		cout << P.min << " " << P.max << " " << P.porcentaje << endl;
		cout << "---------------------------" << endl;
		for (auto i : P.D) cout << " " << i;
		cout << endl;
<<<<<<< HEAD
		cout << "---------------------------" << endl;
		for (auto i : P.T) {
			for(auto j : i) cout << " " << j;
			cout << endl;
		}
		cout << "---------------------------" << endl;
		H.setTime(0.1);
		H.partidaSegundoCriterio(P, HT, numFHash);
=======
	}
	cout << "---------------------------" << endl;
	H.setTime(0.1);
	H.partidaPrimerCriterioDFS1(P, HT, numFHash);
>>>>>>> d2cb01d61e159a7fcb10067e9f67ca016529a16e

		int contadorpal = 0;

		for( auto a : P.D ) {
			if( HT.contains( a, numFHash ) ) ++contadorpal; 
		}

		cout << endl << "---------------:  "<< contadorpal << endl;

		cout << "comp: " << HT.getComparacionesH() << endl;

		cout << "tiempo Construccion: " << HT.getTConstruccionH() << endl;

		cout << "tiempo BFS: " << H.getTBusqueda() << endl;

		cout << "tiempo total: " << H.getTTotal() << endl;


		cout << "------------RESTANTES---------------" << endl;
		for( auto a : HT.getHashTable() ) {
			for( auto b : a ) {
				cout << "    " << b ;
			}
			cout << endl;
		}
	}
}
