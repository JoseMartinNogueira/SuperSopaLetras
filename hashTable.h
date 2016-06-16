#include <iostream>
#include <list>
#include <vector>
#include "hashFunctions.cpp"
using namespace std;

typedef vector< list<int> > Table;
typedef vector< vector<int> > matrix;

class hashTable {

	public:
		hashTable();

		void createHashTable(vector<int>& diccionario,int i );
		void createHashTable(matrix& sopaLetras,int i );
		void insert( const int i, const int value );

		bool contains( const int x );
		bool empty( const int i );
		Table getHashTable() const;

	private:
		Table hashT;

};
