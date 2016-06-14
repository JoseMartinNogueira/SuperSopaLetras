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