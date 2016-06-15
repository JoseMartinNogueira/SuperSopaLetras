#include "hashTable.h"
#include "hashFunctions.h"

using namespace std;

typedef vector< list<int> > hashTable;
typedef vector< vector<int> > matrix;

void hashTable::createHashTable( const vector<int>& diccionario, const int numHashFunction )
{
	int size = diccionario.size();
	hashTable hash (size);

	for( auto a : diccionario ) {
		hash[hashFunction( a, numHashFunction, size )].append(a);
	}

	hashT = hash;
}

void hashTable::createHashTable( const  matrix& sopaLetras, const int numHashFunction )
{
	/*Pendiente de las funciones de hash*/
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

hashTable hashTable::getHashTable() const
{
	return hashT;
}
