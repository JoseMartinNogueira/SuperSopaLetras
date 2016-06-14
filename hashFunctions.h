#include <iostream>

using namespace std;

class hashFunctions {
	public:
		//i es la funcion de hash que utilizaremos ya que podemos tener varias
		int hashFunction( const int i, const int numHashFunction, const int hashSize ) const;
		int getNumHashFunctions() const;

	private:
		int numHashFunctions = 1;
		int modulHF( const int i, const int hashSize ) const;
}