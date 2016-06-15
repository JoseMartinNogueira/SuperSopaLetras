#include <iostream>

using namespace std;

class hashFunctions {
	public:
		//i es la funcion de hash que utilizaremos ya que podemos tener varias
		int hashFunction( const int i, const int numHashFunction, const int hashSize ) const;
		int getNumHashFunctions() const;

	private:
		int numHashFunctions = 1;
		int djb2( const int i ) const;
		int modulHF( const int i, const int hashSize ) const;
		int sdbm( const int i ) const;
		int Jenkins ( const int i ) const;
		int linearProbing ( const int posicion, const int i ) const;
		int hashFunctions::knuth ( const int ) const;
		int hashFunctions::cuckooHashing ( const int i ) const

}