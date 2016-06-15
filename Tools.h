#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

typedef vector< vector<int> > matrix;

struct word {
    int x;
    int y;
    int depth;
    int value;
};

struct input {
    matrix T;
    vector<int> D;
    int min, max, porcentaje;
};

class Tools {

    private:
        int *I;
        int *J;

	public:
        Tools();

        int numDigits(int x);
        /* params: Tablero, posicionPartida, tamanoMinimo, tamanoMaximo, hashFuncion */
        void BFS(const vector< vector<int> > &T, word &w, const int &minDepth, const int &maxDepth);
        /* params: Tablero, posicionPartida, tamanoMinimo tamanoMaximo */
        void DFS(const vector< vector<int> > &T, word &w, const int &minDepth, const int &maxDepth);

        void construirHash(const vector< vector<int> > &T, const int &maxDepth);

        void lectura(input& x);

        void leerDiccionario(const string &name, input &x);

        void leerTablero(const string &name, input &x);

        void generarD(string name, int n, int min, int max, int porcentaje);

        void generarDT(string name, int n, int min, int max, int porcentaje, matrix &T);

        void generarT(string name, int n);




};
