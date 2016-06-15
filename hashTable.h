#include <iostream>
#include <list>
#include <vector>

using namespace std;

typedef vector< list<int> > hashTable;
typedef vector< vector<int> > matrix;		

class hashTable {

	public:
		
		void createHashTable( const vector<int>& diccionario, const int i );
		void createHashTable( const  matrix& sopaLetras, const int i );
		void insert( const int i, const int value );
		
		bool contains( const int x );
		bool empty( const int i ) 
		hashTable getHashTable() const;

	private:
		hashTable hashT;
		
};	
