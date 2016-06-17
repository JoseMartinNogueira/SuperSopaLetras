#include <iostream>
#include <cmath>

using namespace std;

class BloomA {
    public:
	int k;
	int mida;
	int numero_colsiones;
	
	BloomA(int size) {
	    mida = int(10*sqrt(size));
	    F = vector<unsigned char> (mida, 0x0000);
	    numero_colsiones = 0;
	}

	void insert(int k, int &nc) {
	    bool collocal = true;

	    if (mida > 100000) {
				int h = h5(k, nc);
				collocal &= (F[h>>3]>>(h%8))&0x0001;
				F[h>>3] |= 0x0001<<(h%8);
				++nc;
	    }
	    if (mida > 10000) {
				int h = h4(k, nc);
				collocal &= (F[h>>3]>>(h%8))&0x0001;
				F[h>>3] |= 0x0001<<(h%8);
				++nc;
	    }
	    if (mida > 5000) {
				int h = h3(k, nc);
				collocal &= (F[h>>3]>>(h%8))&0x0001;
				F[h>>3] |= 0x0001<<(h%8);
				++nc;
	    }
	    if (mida > 100) {
				int h = h2(k, nc);
				collocal &= (F[h>>3]>>(h%8))&0x0001;
				F[h>>3] |= 0x0001<<(h%8);
				++nc;
	    }
	    int h = h1(k, nc);
	    collocal &= (F[h>>3]>>(h%8))&0x0001;
			F[h>>3] |= 0x0001<<(h%8);
	    ++nc;
	    
	    
	    if (collocal) ++numero_colsiones;
	    
	}
	
	bool search(int k, int &nc) {
	    if (mida > 100000) {
	    	++nc;
	    	int h = h5(k, nc);
	    	if (not ((F[h>>3]>>(h%8))&0x0001)) return false;
	    }
	    if (mida > 10000) {
	    	++nc;
	    	int h = h4(k, nc);
	    	if (not ((F[h>>3]>>(h%8))&0x0001)) return false;
	    }
	    if (mida > 5000) {
	    	++nc;
	    	int h = h3(k, nc);
	    	if (not ((F[h>>3]>>(h%8))&0x0001)) return false;
	  	}
	    if (mida > 100) {
	    	++nc;
	    	int h = h2(k, nc);
	    	if (not ((F[h>>3]>>(h%8))&0x0001)) return false;
    	}
	    ++nc;
	    int h = h1(k, nc);
    	if (not ((F[h>>3]>>(h%8))&0x0001)) return false;
	    return true;

	}
	
	int memoria() {
	    return mida;
	}
	
	int colisiones() {
	    return numero_colsiones;
	}
	
    private:
	vector<unsigned char> F;
	
	unsigned int h(int k, int &nc) {
	    unsigned int h = mida<<3;
	    for (int i = k; i  >  0; i = (i >> 3)) {
				h = (h << 5) + h + i; 
	    }
	    return h%(mida<<3);
	}
	
	unsigned int h1(int k, int &nc) {
	    return h(k, nc);
	}
	
	unsigned int h2(int k, int &nc) {
	    unsigned int i = k;
	    i = ((i >> 16) ^ i) * 0x045d9f3b;
	    i = ((i >> 16) ^ i) * 0x045d9f3b;
	    i = ((i >> 16) ^ i);
	    return i%(mida<<3);
	}
	
	unsigned int h3(int k, int &nc) {
	    unsigned int i = k;
	    i = (i+0x7ed55d16) + (i<<12);
	    i = (i^0xc761c23c) ^ (i>>19);
	    i = (i+0x165667b1) + (i<<5);
	    i = (i+0xd3a2646c) ^ (i<<9);
	    i = (i+0xfd7046c5) + (i<<3);
	    i = (i^0xb55a4f09) ^ (i>>16);
	    return i%(mida<<3);
	}
	
	//parells
	unsigned int h4(int k, int &nc) {
	    int p = h(k, nc);
	    p = p%(mida<<2);//mida*8/2=mida*4
	    return (p<<1);//p*2
	}
	
	//imparells
	unsigned int h5(int k, int &nc) {
	    int p = h(k, nc);
	    p = p%(mida<<2);//mida*8/2=mida*4
	    return (p<<1 + 1);//p*2
	}
    
};