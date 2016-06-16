#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include "hashFunctions.cpp"
using namespace std;

typedef vector< list<int> > Table;
typedef vector< vector<int> > matrix;

class hashTable {
	private:
		Table hashT;

	public:
		void createHashTable(vector<int>& diccionario, int numHashFunction )
		{

			int size = diccionario.size();
			hashT = Table(size);
			hashFunctions HF;
			for( auto a : diccionario ) {
				hashT[HF.hashFunction( a, numHashFunction, size )].push_back(a);
			}

		}

		void createHashTable( matrix& sopaLetras,int numHashFunction )
		{
			int n = sopaLetras.size();
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++i) {

				}
			}

		}

		void insert( const int i, const int value )
		{
			hashT[i].push_back(value);
		}

		bool contains( const int x, const int hf ) const
		{
			hashFunctions HF;
			for( auto& a : hashT[HF.hashFunction( x, hf, hashT.size() )] ) {
				if ( a == x ) return true;
			}
			return false;
		}

		bool empty( const int i )
		{
			return ( hashT[i].size() == 0 );
		}


		Table getHashTable() const
		{
			return hashT;
		}

		hashTable() {}
};
