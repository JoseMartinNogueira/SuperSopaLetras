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
	cout << "(1) Modulo" << endl;
	cout << "(2) DJB2" << endl;
	cout << "(3) SDBM" << endl;
	cout << "(4) JENKINS" << endl;
	cout << "(5) KNUTH" << endl;
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

	HT.createHashTable( P.D, numFHash);

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

	H.setTime(10.0);
	H.partidaPrimerCriterioDFS2(P, RH, HT, numFHash);

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
