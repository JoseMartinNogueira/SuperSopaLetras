#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <time.h>
#include <ctime>

#include "hashTable.cpp"

typedef vector< list< pair<int,int> > > rollHash;

class rollingHash {

private:
    rollHash rollH;
    int comparacionesRH;
    double tConstruccionRH;
public:

    rollingHash(){
        comparacionesRH = 0;
        tConstruccionRH = 0;
    }

	int numDigits2(int x) {
		int l = 1;
		while (x /= 10) ++l;
		return l;
	}

    int getComparacionesRH() const
    {
        return comparacionesRH;
    }

    double getTConstruccionRH() const
    {
        return tConstruccionRH;
    }

    void createRollingHash( const vector<int>& diccionario, const int maxSize, const int numHashFunction )
    {
        clock_t startC = clock();
        rollH = rollHash( diccionario.size() * numDigits2(maxSize));
        hashFunctions HF;
        for( auto a : diccionario ) {
            int sizeAux = numDigits2( a );
            int aux = pow(10, sizeAux-1);
            int prefijo = a;
            int index = HF.hashFunction( prefijo, numHashFunction, rollH.size() );
            bool auxb = containsRH( prefijo, numHashFunction, 2 );
            if( !auxb ) {
                pair<int,int> p (prefijo, 1);
                rollH[index].push_back( p );
            } 
            for( int i = 0; i < sizeAux-1; ++i ) {
                prefijo = a / aux;
                aux = aux/10;
                auxb = containsRH( prefijo, numHashFunction, 2);
                if( !auxb ) {
                    pair<int,int> p (prefijo, 1);
                    rollH[ HF.hashFunction( prefijo, numHashFunction, rollH.size() )].push_back(p);
                }
            }
        }
        clock_t endC = clock();
        tConstruccionRH = (endC - startC)/double(CLOCKS_PER_SEC)*1000;
    }

    void deletePrefix( const int a, const int numHashFunction ) {
            hashFunctions HF;
            int sizeAux = numDigits2( a );
            int aux = pow(10, sizeAux-1);
            int prefijo = a;
            int index = HF.hashFunction( prefijo, numHashFunction, rollH.size() );
            containsRH( prefijo, numHashFunction, 3 );
             
            for( int i = 0; i < sizeAux-1; ++i ) {
                prefijo = a / aux;
                aux = aux/10;
                containsRH( prefijo, numHashFunction, 3);
            }
    }
    /// retorna la pos en al hash si es = 0 es que no esta
    // modo == 1 consulta, modo == 2 inc, modo == 3 dec
    bool containsRH( const int i, const int numHashFunction, int modo )
    {
        hashFunctions HF;
        int index = HF.hashFunction( i, numHashFunction, rollH.size() );
        list<pair<int,int> > auxList = rollH[index];
        list<pair<int,int> >::iterator it;
        for( it = auxList.begin(); it != auxList.end(); ++it ) {
            comparacionesRH++;
            if( (*it).first == i ) {
                if( modo == 2 ) {
                    (*it).second++;
                    rollH[index] = auxList;
                }
                else if( modo == 3) {
                    if ((*it).second > 1) (*it).second--;
                    else {
                        it = auxList.erase(it);
                    }
                    rollH[index] = auxList;
                }
                return true;
            }
        }
        return false;
    }

    rollHash getRollingHash()
    {
        return rollH;
    }



};
