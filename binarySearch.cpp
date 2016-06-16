#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class binarySearch {

private:
	vector<int> bSVector;
public:
	binarySearch()
	{
		bSVector = NULL;
	}

	void setBSVector( const vector<int>& diccionario )
	{
		bSVector = diccionario;
		sort( bSVector.begin(), bSVector.end() );
	}

	vector<int> getBSVector() const
	{
		return bSVector;
	}

	bool search(int x) const
	{
		return binarySearchAlgorithm( bSVector, 0, bSVector.size()-1, x );
	}

	bool binarySearchAlgorithm(const vector<int>& diccionario, int e, int d, int x ){
		if(e > d){
	    	return false;
	  	}
		int mid = (e+d)/2;
		if (diccionario[mid] == x){
	    	return true;
	  	}
		else if (x < diccionario[mid]) return cerca_dicotomica(diccionario, e, mid-1, x);
		else if (x > diccionario[mid]) return cerca_dicotomica(diccionario,mid+1, d, x);
	}

};
