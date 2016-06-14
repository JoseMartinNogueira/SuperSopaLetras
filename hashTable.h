#include <iostream>
#include <list>
#include <vector>

using namespace std;

typedef vector< list<int> > hashTable;
typedef vector< vector<int> > matrix;		

class hashTable {

	public:
		
		void createHashTable( const vector<int>& diccionario );
		void createHashTable( const  matrix& sopaLetras );

		bool insert( const int x );
		bool contains( const int x );
		hashTable getHashTable() const;

	private:
		hashTable hashT;
		
};	
