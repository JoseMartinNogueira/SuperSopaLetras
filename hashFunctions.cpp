#include "hashFunction"


using namespace std;

int hashFunctions::hashFunction( const int i, const int numHashFunction, const int sizeHash ) const
{
	switch( numHashFunction ) {
		case 1:
			//mod
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
	//revisar si --c o c = c >> 3
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
		hash = c + (hash << 6) + (hash << 16) - hash;
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