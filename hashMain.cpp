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
	int alg;
	cout << "ELige un algoritmo:" <<endl;
	cout << "1) Hash diccionario + BFS" << endl;
	cout << "2) Hash diccionario + DFS" << endl;
	cout << "3) Hash tablero 	 + BFS" << endl;
	cout << "4) Hash tablero     + DFS" <<endl;
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
		H.setTime(50);
		H.partidaPrimerCriterioBFS1(P, HT, numFHash);

		cout << endl << "---------encontradas:  "<< P.contador << endl;

		cout << "comp: " << HT.getComparacionesH() << endl;

		cout << "tiempo Construccion: " << HT.getTConstruccionH() << endl;

		cout << "tiempo BFS: " << H.getTBusqueda() << endl;

		cout << "tiempo total: " << H.getTTotal() << endl;
	}
	else if( alg == 2 ) {	
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
		H.setTime(50);
		H.partidaPrimerCriterioDFS1(P, HT, numFHash);

		cout << endl << "---------encontradas:  "<< P.contador << endl;

		cout << "comp: " << HT.getComparacionesH() << endl;

		cout << "tiempo Construccion: " << HT.getTConstruccionH() << endl;

		cout << "tiempo BFS: " << H.getTBusqueda() << endl;

		cout << "tiempo total: " << H.getTTotal() << endl;
	}
	else if( alg == 3 ) {
		Tools H;
		input P;
		P.contador = 0;
		H.leerDiccionario("d", P);
		hashTable HT;

		coutHashes();
		int numFHash;

		cin >> numFHash;

		

		H.leerTablero("t", P);

		HT.createHashTable(P.T);
		
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
		H.setTime(999999999999999999);
		H.partidaSegundoCriterioBFS1(P, HT, numFHash);

		int encontradas = 0;
		for(auto a : P.D) {
			if( HT.contains(a, numFHash) ) ++encontradas;
		}

		cout << endl << "---------encontradas:  "<< encontradas << endl;

		cout << "comp: " << HT.getComparacionesH() << endl;

		cout << "tiempo Construccion: " << HT.getTConstruccionH() << endl;

		cout << "tiempo BFS: " << H.getTBusqueda() << endl;

		cout << "tiempo total: " << H.getTTotal() << endl;
	}		
	else if( alg == 4 ) {
		Tools H;
		input P;
		P.contador = 0;
		H.leerDiccionario("d", P);
		hashTable HT;

		coutHashes();
		int numFHash;

		cin >> numFHash;

		

		H.leerTablero("t", P);

		HT.createHashTable(P.T);
		
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
		H.setTime(999999999999999999);
		H.partidaSegundoCriterioDFS1(P, HT, numFHash);

		int encontradas = 0;
		for(auto a : P.D) {
			if( HT.contains(a, numFHash) ) ++encontradas;
		}

		cout << endl << "---------encontradas:  "<< encontradas << endl;

		cout << "comp: " << HT.getComparacionesH() << endl;

		cout << "tiempo Construccion: " << HT.getTConstruccionH() << endl;

		cout << "tiempo BFS: " << H.getTBusqueda() << endl;

		cout << "tiempo total: " << H.getTTotal() << endl;
	}
}
