#include "hashTable.h"

void hashTable::createHashTable(vector<int>& diccionario, int numHashFunction )
{

	int size = diccionario.size();
	hashT = Table(size);
	hashFunctions HF;
	for( auto a : diccionario ) {
		hashT[HF.hashFunction( a, numHashFunction, size )].push_back(a);
	}

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
	for ( int i = 0; i < hashT.size(); ++i ) {
		for( auto& a : hashT[i] ) {
			if ( a == x ) return true;
		}
	}
	return false;
}

bool hashTable::empty( const int i )
{
	return ( hashT[i].size() == 0 );
}


Table hashTable::getHashTable() const
{
	return hashT;
}

hashTable::hashTable() {}
