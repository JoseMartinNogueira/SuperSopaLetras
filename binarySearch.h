#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class binarySearch {

private:
	vector<int> bSVector;
public:
	binarySearch();
	void setSBVector( const vector<int>& diccionario );
	vector<int> getBSVector() const;
	bool search(int x) const;

};