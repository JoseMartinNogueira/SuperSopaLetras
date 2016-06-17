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
	Tools H;
	input P;
	P.contador = 0;
	H.leerDiccionario("d", P);
	rollingHash RH;
	hashTable HT;

	coutHashes();
	int numFHash;

	cin >> numFHash;

	HT.createHashTable( P.D, numFHash );

	for( auto a : HT.getHashTable() ) {
		for ( auto b : a) {
			cout << "  " << b << endl;
		}
		cout << endl;
	}
	cout << "--------- " << HT.contains(438, numFHash)<<" ---------"<< endl;

	RH.createRollingHash(P.D, P.max, numFHash);
	for( auto a : RH.getRollingHash() ) {
		for( auto b : a ) {
			cout << "    " << b.first << "::" << b.second;
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

	H.partidaPrimerCriterio2(P, RH, HT, numFHash);

	cout << endl << "---------------:  "<< P.contador << endl;

	cout << "comp: " << RH.getComparacionesRH() << endl;

	cout << "tiempo Construccion: " << RH.getTConstruccionRH() << endl;

	cout << "tiempo BFS: " << H.getTBusqueda() << endl;

	cout << "tiempo total: " << H.getTTotal() << endl;
	for( auto a : RH.getRollingHash() ) {
		for( auto b : a ) {
			cout << "    " << b.first << "::" << b.second;
		}
		cout << endl;
	}
}