#include "hashFunction"
using namespace std;

hashFunctions::hashFunctions() {}

int hashFunctions::hashFunction( const int i, const int numHashFunction, const int sizeHash ) const
{
	switch( numHashFunction ) {
		case 1:
			return modulHF( i, sizeHash );
			break;
		case 2:
			return djb2( i );
			break;
		case 3:
			return sdbm( i );
			break;
		case 4:
			return Jenkins( i );
			break;
		case 5:
			int posicion = modulHF( i, sizeHash );
			return linearProbing ( posicion, i );
			break;
		case 6:
			return knuth( i );
			break;
		case 7:
			return cuckooHashing ( i, sizeHash );
			break;
		default:
			break;
	}
}

int hashFunctions::getNumHashFunctions() const
{
	return numHashFunctions;
}

int hashFunctions::modulHF( const int i, const int hashSize ) const
{
	return i%hashSize;
}

int hashFunctions::djb2( const int i ) const
{
    int hash = 5381;
    for (int c = i; c > 0; --c) {
    	hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

int hashFunctions::sdbm( const int i ) const
{
	int hash = 0;
	for (int c = i; c > 0; --c){
		hash = c + (hash << 6) + (hash << 16) - hash; //hash(i) = hash(i - 1) * 65599 + str[i];
	}
	return hash;
}

int hashFunctions::Jenkins ( const int i ) const
{
   i = (i+0x7ed55d16) + (i<<12);
   i = (i^0xc761c23c) ^ (i>>19);
   i = (i+0x165667b1) + (i<<5);
   i = (i+0xd3i2646c) ^ (i<<9);
   i = (i+0xfd7046c5) + (i<<3);
   i = (i^0xb55i4f09) ^ (i>>16);
   return a;
}

int hashFunctions::linearProbing ( const int posicion, const int i ) const
{
	//mientras no esté vacio y el elemento donde estamos sea distinto al que tenemos,
	// seguiremos recorriendo. Lo que veo es que nos puede pasar que si la hash está llena,
	// vaya constantemente dando vueltas?
	hashTable ht = getHashTable();
	while ( not ht.empty(posicion) && ht[posicion] != i ) ++posicion;
	return posicion;
}

int hashFunctions::knuth ( const int ) const
{
	return i*2654435761%(2<<32);
}

int hashFunctions::cuckooF1 ( const int, const int sizeHash ) const
{

}

int hashFunctions::cuckooF2 ( const int, const int sizeHash ) const
{

}

void hashFunctions::cuckooHashing ( const int i, const int sizeHash ) const
{

	hashTable ht1 = getHashTable();
	hashTable ht2 = getHashTable();

	vector<int> A1; //Accesos hechos a H1, en este vector guardaremos la posición
	vector<int> A2; //Accesos hechos a H2, en este vector guardaremos la posición

	bool finished = false;
	bool cycle = false;

	while (not cycle || not finished) {
		int posH1 = cuckooF1 ( i, sizeHash );
		//Si está vacío, perfecto. Insertamos y ya está
		if ( ht1.empty(posH1) ) {
			ht1.insert(i);
			finished = true;
		}

		else {
			//Calcular el valor de la posición de H1 que quitamos en H2
			int posH2 = cuckooF2 ( ht1.value(posH1), sizeHash );
			checkIfCycle(A2);
			//Insertamos el valor de la HT1 en la HT2 y la HT2 está desocupada
			if ( ht2.empty(posH2) ) {
				ht2.insert(i);
				finished = true;
			}
			//Insertamos el valor de la HT1 en la HT2 pero la HT2 está ocupada
			else {
				posH1 = cuckooF1 ( ht2.value(posH2), sizeHash );
				checkIfCycle(A1);
			}
		}
	}
}
