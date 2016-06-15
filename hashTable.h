#include <iostream>
#include <list>
#include <vector>
#include "hashFunctions.h"
#include "Tools.h"

using namespace std;

typedef vector< list<int> > hashTable;
typedef vector< vector<int> > matrix;		

class hashTable {

	public:
		
		void createHashTable( const vector<int>& diccionario, const int i );
		void createHashTable( const  matrix& sopaLetras, const int i, const int  );

		bool contains( const int x );
		hashTable getHashTable() const;

	private:
		hashTable hashT;
		
};	
