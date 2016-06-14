#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

struct word {
    int x;
    int y;
    int depth;
    int value;
};

class Tools {

    private:
        int *I;
        int *J;

	public:
        Tools();
        /* params: Tablero, posicionPartida, tamanoMinimo, tamanoMaximo, hashFuncion */
        void BFS(const vector< vector<int> > &T, word &w, const int &minDepth, const int &maxDepth);
        /* params: Tablero, posicionPartida, tamanoMinimo tamanoMaximo */
        void DFS(const vector< vector<int> > &T, word &w, const int &minDepth, const int &maxDepth);

        void construirHash(const vector< vector<int> > &T, const int &maxDepth);




};
