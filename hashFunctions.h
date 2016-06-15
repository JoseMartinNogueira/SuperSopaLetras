#include <iostream>

using namespace std;

class hashFunctions {
	public:
		//i es la funcion de hash que utilizaremos ya que podemos tener varias
		int hashFunction( const int i, const int numHashFunction, const int hashSize ) const;

	private:
<<<<<<< HEAD
		
=======
>>>>>>> b8a568b73e2c81dc0741c06dfca919ed36c4a884
		int djb2( const int i ) const;
		int modulHF( const int i, const int hashSize ) const;
		int sdbm( const int i ) const;
		int Jenkins ( const int i ) const;
		int linearProbing ( const int posicion, const int i ) const;
		int knuth ( const int ) const;
		void cuckooHashing ( const int i ) const;

<<<<<<< HEAD
};
=======
};
>>>>>>> b8a568b73e2c81dc0741c06dfca919ed36c4a884
