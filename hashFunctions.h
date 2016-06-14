#include <iostream>

using namespace std;

class hashFunction {
	public:
		//i es la funcion de hash que utilizaremos ya que podemos tener varias
		int hashFunction( const int i );
		int getNumHashFunctions() const;

	private:
		int numHashFunctions = 1;
}