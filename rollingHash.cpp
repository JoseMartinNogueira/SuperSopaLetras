#include <iostream>
#include <list>
#include <vector>
#include <utility>

#include "hashTable.cpp"

typedef vector< list< pair<int,bool> > > rollHash;

class rollingHash {

private:
    rollHash rollH;
public:

    rollingHash(){}

	int numDigits2(int x) {
		int l = 1;
		while (x /= 10) ++l;
		return l;
	}

    void createRollingHash( const vector<int>& diccionario, const int maxSize, const int numHashFunction )
    {
        cout << "WTF  ----" << endl;
        rollH = rollHash( diccionario.size() );
        cout << "------------- WTF  ----" << endl;
        hashFunctions HF;
        for( auto a : diccionario ) {
            int aux = 10;
            int prefijo = a;
            pair<int, bool> p (a , true );
            rollH[HF.hashFunction( prefijo, numHashFunction, rollH.size() )].push_back( p );
			int sizeAux = numDigits2( a );
            for( int i = sizeAux; prefijo > 0; --i ) {
                prefijo = prefijo / aux;
                aux = aux*10;
                pair<int, bool> prefP ( prefijo, false );
                rollH[HF.hashFunction( prefijo, numHashFunction, rollH.size() )].push_back( prefP );
            }
        }
    }
    /// si return 1 es palabra si return 2, es prefijo, 3 no esta en la hash
    int containsRH( const int i, const int numHashFunction ) const
    {
        hashFunctions HF;
        for( auto b : rollH[HF.hashFunction( i, numHashFunction, rollH.size() )] ) {
            if( b.second == true && b.first == i ) return 1;
			else if( b.second == false && b.first == i ) return 2;
        }
        return 3;
    }

    rollHash getRollingHash()
    {
        return rollH;
    }



};
