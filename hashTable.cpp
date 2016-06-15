#include "hashTable.h"

void hashTable::createHashTable(vector<int>& diccionario, int numHashFunction )
{
	/*
	int size = diccionario.size();
	hashT = Table(size);

	for( auto a : diccionario ) {
		hashT[hashFunction( a, numHashFunction, size )].append(a);
	}
	*/
}

void hashTable::createHashTable( matrix& sopaLetras,int numHashFunction )
{
	int n = sopaLetras.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++i) {

		}
	}

}

void hashTable::insert( const int i, const int value )
{
	hashT[i].push_back(value);
}

bool hashTable::contains( const int x )
{
	bool found = false;
	for ( int i = 0; !found && i < hashT.size(); ++i ) {
		found = hashT[i].contains( x );
	}
	return found;
}

bool hashTable::empty( const int i )
{
	return ( hashT[i].size() == 0 );
}

Table hashTable::getHashTable() const
{
	return hashT;
}

hashTable::hashTable() {
	hashT = NULL;
}
