#include <iostream>
#include <list>
#include <vector>
#include <math.h>       /* pow */
#include "hashFunctions.cpp"
#include "hashTable.cpp"
using namespace std;

class Cuckoo {

    private: 
        hashTable ht1, ht2;
        list<int> A1, A2;
        int f1,f2;
        hashFunctions hf;

    public:
        Cuckoo() {}
        
        bool checkIfCycle( list<int>&A )
        {
            list<int>::iterator it;
            list<int>::iterator it2;
            it = A.begin();
            it2 = A.begin(); ++it2;
            while ( it2 != A.end() ) {
                ++it2;
                if ( (*it) == (*it2) ) return true;
                ++it;
            }
            return false;
        }

        //insertamos los elementos ordenadamente.
        void insertInOrder( list<int>& A, int elemento )
        {
            list<int>::iterator it;
            it = A.begin();
            while ( elemento < (*it) && it != A.end()) ++it;
            A.insert( it, elemento );
        }

        bool cuckooHashing( int i, int sizeHash, int tabla ) 
        {
            if ( tabla == 1 ) 
            {
                //calculem la posicio
                int posH1 = hf.hashFunction( i , f1, sizeHash);
                //Si está vacío, perfecto. Insertamos y ya está
                if ( ht1.empty(posH1) ) {
                    ht1.insert(posH1, i);
                    //cout << "Posicio  ht1 " << posH1 << " trobada" << endl;
                    return false;
                }
                else {
                    //Si no pues enviamos el otro valor a H2
                    int posH2 = hf.hashFunction( i , f2, sizeHash);
                    insertInOrder( A2, posH2 ); //marcamos 
                    if ( checkIfCycle( A2 ) ) {
                        //cout << "CICLO" << endl;
                        return true;
                    }
                    else    cuckooHashing( posH2 , sizeHash, 2);
                }
            }
            else if ( tabla == 2 ) 
            {
                int posH2 = hf.hashFunction( i , f2, sizeHash);
                //Si está vacío, perfecto. Insertamos y ya está
                if ( ht2.empty(posH2) ) {
                    ht2.insert(posH2, i);
                    //cout << "Posicio  ht2 " << i << " trobada" << endl;
                    return false;
                }
                else {
                    int posH1 = hf.hashFunction( i , f1, sizeHash);
                    insertInOrder( A1, posH1 );
                    if (checkIfCycle( A1 )) {
                        //cout << "CICLO" << endl;
                        return true;
                    }
                    else    cuckooHashing ( posH1 , sizeHash, 1);
                }

            }
            //otherwise finish tabla == 0

        }

        void cuckoo ( int funcion1, int funcion2, const int i, int hashSize )
        {
            f1 = 1; f2 = 1;
            while (cuckooHashing( i, hashSize, 1)) ++hashSize;
        }
};