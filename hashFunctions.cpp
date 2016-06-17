#include <iostream>
#include <list>
#include <vector>
#include <math.h>       /* pow */
using namespace std;


class hashFunctions {

	public:
		hashFunctions() {
			
		}

		int hashFunction( int i, const int numHashFunction, const int sizeHash ) 
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
				case 6:
					return knuth( i );
					break;
				default:
					break;
			}
		}

		int modulHF( const int i, const int hashSize ) const
		{
			return i%hashSize;
		}

		unsigned int djb2( const int i )
		{
		    int hash = 5381;
		    for (int c = i; c > 0; --c) {
		    	hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
		    }
		    return hash;
		}

		unsigned int sdbm( const int i )
		{
			int hash = 0;
			for (int c = i; c > 0; --c){
				hash = c + (hash << 6) + (hash << 16) - hash; //hash(i) = hash(i - 1) * 65599 + str[i];
			}
			return hash;
		}

		unsigned int Jenkins( unsigned int i) {
		    i = (i+0x7ed55d16) + (i<<12);
		    i = (i^0xc761c23c) ^ (i>>19);
		    i = (i+0x165667b1) + (i<<5);
		    i = (i+0xd3a2646c) ^ (i<<9);
		    i = (i+0xfd7046c5) + (i<<3);
		    i = (i^0xb55a4f09) ^ (i>>16);
		    return i;
		}

		unsigned long long knuth( int i  )
		{
		return fmod(i*2654435761,(pow(2,32)));
		}


};
