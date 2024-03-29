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
		int comparacionesH;
		double tConstruccionH;
	public:

		int getComparacionesH() const
		{
			return comparacionesH;
		}

		int getTConstruccionH() const
		{
			return tConstruccionH;
		}

		int getSize() const
		{
			return hashT.size();
		}

		void createHashTable(const vector<int>& diccionario, int numHashFunction )
		{
			clock_t startC = clock();
			int size = diccionario.size();
			hashT = Table(size);
			hashFunctions HF;
			for( auto a : diccionario ) {
				hashT[HF.hashFunction( a, numHashFunction, size )].push_back(a);
			}
			clock_t endC = clock();
			tConstruccionH = (endC - startC)/double(CLOCKS_PER_SEC)*1000;	
		}

		void createHashTable( matrix& sopaLetras )
		{
			hashT = Table(sopaLetras.size()*sopaLetras.size());
		}

		void deleteH( const int i, const int numHashFunction ) 
		{
			hashFunctions HF;
			int index = HF.hashFunction( i, numHashFunction, hashT.size() );
			list<int> auxList = hashT[index];
			list<int>::iterator it;
			for( it = auxList.begin(); it != auxList.end(); ++it ) {
				++comparacionesH;
				if( *it == i ) {
					it = auxList.erase(it);
					hashT[index] = auxList;
					break;
				}
			}
		}

		void insert( const int i, const int value )
		{
			hashT[i].push_back(value);
		}

		bool contains( const int x, const int hf )
		{
			hashFunctions HF;
			for( auto a : hashT[HF.hashFunction( x, hf, hashT.size() )] ) {
				++comparacionesH;
				if ( a == x ) return true;
			}
			return false;
		}

		bool empty(int i )
		{
			return ( hashT[i].size() == 0 );
		}


		Table getHashTable() const
		{
			return hashT;
		}

		hashTable() {
			comparacionesH = 0;
			tConstruccionH = 0;
		}

		bool pertany( int i, int posicion){
			for (auto a : hashT[posicion]){
				++comparacionesH;
				if (i == a ) return true;

			}
			return false;
		}

		int linearProbing (int posicion, const int i)
        {
            //mientras no esté vacio y el elemento donde estamos sea distinto al que tenemos,
            // seguiremos recorriendo. 
            while (empty(posicion) && not pertany(i, posicion)) {
            	++posicion;
            	if (posicion ==  hashT.size()) hashT[posicion].push_back(i); //Añadimos al final de todo.
            }
            return posicion;
        }
};
