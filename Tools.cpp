#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <utility>

#include "rollingHash.cpp"

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
    int min, max, porcentaje, contador;
};

class Tools {

    private:
        int *I;
        int *J;

	public:
        Tools() {
             I = new int[8] {-1, -1, -1,  0, 0,  1, 1, 1};
             J = new int[8] {-1,  0,  1, -1, 1, -1, 0, 1};
        }

        void BFS(input &IN, word &w, const hashTable &HT, const int &hf) {
            int  N = IN.T.size();
            queue<word> Q;
            Q.push(w);
            cout << "min: " << IN.min << ", max: " << IN.max << endl;
            while (not Q.empty()) {
                word act = Q.front();
                Q.pop();
                ////////////////////////////
                cout << "(" << act.x << "," << act.y << ") " << act.value;

                if((act.depth >= IN.min) and (HT.contains(act.value, hf))) {
                    ++IN.contador;
                    cout << act.value << endl;
                }

                ////////////////////////////
                for (int i = 0; i < 8; ++i) {
                    int x = act.x + I[i];
                    int y = act.y + J[i];
                    if(x >= 0 and x < N and y >= 0 and y < N and act.depth +1 < IN.max ) {
                        word nw = {x, y, act.depth + 1, act.value*10 + IN.T[x][y]};
                        Q.push(nw);
                    }
                }
            }
        }

        void BFS2(input &IN, word &w,const rollingHash &HT, const int &hf) {
            int  N = IN.T.size();
            int aux;
            queue<word> Q;
            Q.push(w);
            cout << "min: " << IN.min << ", max: " << IN.max << endl;
            while (not Q.empty()) {
                word act = Q.front();
                Q.pop();
                ////////////////////////////
                cout << "(" << act.x << "," << act.y << ") " << act.value;
                aux = HT.containsRH(act.value, hf);
                if((act.depth >= IN.min) and aux != 3) {
                    if( aux == 1 ) ++IN.contador;
                    cout << act.value << endl;
                }
                if( aux != 3 ) {
                    for (int i = 0; i < 8; ++i) {
                        int x = act.x + I[i];
                        int y = act.y + J[i];
                        if(x >= 0 and x < N and y >= 0 and y < N and act.depth +1 < IN.max ) {
                            word nw = {x, y, act.depth + 1, act.value*10 + IN.T[x][y]};
                            Q.push(nw);
                        }
                    }
                }
            }
        }

        void DFS(const vector< vector<int> > &T, word &w, const int &minDepth, const int &maxDepth) {
            int  N = T.size();
            stack<word> Q;
            Q.push(w);

            while (not Q.empty()) {
                word act = Q.top();
                Q.pop();
                ////////////////////////////
                if(act.depth >= minDepth) cout << act.value << endl;
                ////////////////////////////
                for (int i = 0; i < 8; ++i) {
                    int x = act.x + I[i];
                    int y = act.y + J[i];
                    if(x >= 0 and x < N and y >= 0 and y < N and act.depth < maxDepth) {
                        word nw = {x, y, act.depth + 1, act.value*10 + T[x][y]};
                        Q.push(nw);
                    }
                }
            }
        }
/*
        void construirHash(const vector< vector<int> > &T, const int &minDepth, const int &maxDepth) {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    word w = {i, j, 0, T[i][j]};
                    BFS(T, w, 1, maxDepth);
                }
            }
        }
*/
        int numDigits(int x) {
            int l = 1;
            while (x /= 10) ++l;
            return l;
        }
        //Repasar que no haya repetidos en el diccionario.
        void generarD(string name, int n, int min, int max, int porcentaje){
            srand(time(NULL));
            int min2 = pow(10,min - 1);
            int max2 = pow(10,max) - 1;
            ofstream jp(name, ios::binary);
            int vals[4] = {n, min2, max2, porcentaje};
            jp.write(reinterpret_cast<const char *>(&vals), sizeof(vals));
            int vSt[n];
            for (int i=0; i < n; ++i) vSt[i] = min2 + rand()%(max2 - min2 + 1);
            jp.write(reinterpret_cast<const char *>(&vSt), sizeof(vSt));
            jp.close();
        }

        void generarDT(string name, int n, int min, int max, int porcentaje, matrix &T){
            ofstream jp(name, ios::binary);
            int vals[4] = {n, min, max, porcentaje};
            jp.write(reinterpret_cast<const char *>(&vals), sizeof(vals));
            int vSt[n];
            int lmin = numDigits(min);
            int lmax = numDigits(max);
            int it = (n*porcentaje)/100;
            for (int i = 0; i < it; ++i) {
                int r = lmin + rand()%(lmax - lmin + 1);
                int x = rand()%T.size() - 1;
                int y = rand()%T.size() - 1;
                vSt[i] = T[x][y];
                for (int j = 0; j < r; ++j) {
                    int pos = rand()%8;
                    int ii = x + I[pos];
                    int jj = y + J[pos];
                    while (ii < 0 or ii >= n or jj < 0 or jj >= n) {
                        ii = x + I[pos];
                        jj = y + J[pos];
                        pos = rand()%8;
                    }
                    vSt[i] = vSt[i]*10 + T[ii][jj];

                }

            }

            for (int i = it ; i < n; ++i) vSt[i] = min + rand()%(max - min + 1);
            jp.write(reinterpret_cast<const char *>(&vSt), sizeof(vSt));
            jp.close();
        }



        void generarT(string name, int n){
            ofstream jp(name, ios::binary);
            jp.write(reinterpret_cast<const char *>(&n), sizeof(int));
            int vSt[n*n];
            for (int i = 0; i < n*n; ++i) {
                vSt[i] = rand()%10;
            }
            jp.write(reinterpret_cast<const char *>(&vSt), sizeof(vSt));
            jp.close();
        }

        void leerDiccionario(const string &name, input& atributos) {
            ifstream dicc( name, ios::in | ios::binary);
            if(dicc) {
                //{n, min, max, porcentaje};
                int vals[4];
                dicc.read(reinterpret_cast<char *>(&vals), sizeof(vals));

                int D[vals[0]];
                atributos.D = vector<int>(vals[0]);

                atributos.min = vals[1];
                atributos.max = vals[2];
                atributos.porcentaje = vals[3];

                dicc.read(reinterpret_cast<char *>(&D), sizeof(D));

                for (int i = 0; i < vals[0]; ++i) atributos.D[i] = D[i];
            }
            dicc.close();
        }

        void leerTablero(const string &name, input& atributos) {
            ifstream sl(name, ios::in | ios::binary);
            if (sl){
                int n;
                sl.read(reinterpret_cast<char *>(&n), sizeof(int));
                atributos.T = vector< vector<int> >(n);
                cout << n << endl;
                for (int i = 0; i < n; ++i){
                    int fila[n];
                    sl.read(reinterpret_cast<char *>(&fila), sizeof(fila));
                    atributos.T[i] = vector<int>(n);
                    for (int j = 0; j < n; ++j) {
                        atributos.T[i][j] = fila[j];
                    }
                }
            }
            sl.close();
        }

        void partidaPrimerCriterio(input &IN, const hashTable &HT, const int &hf) {
            cout << "nononoo" << endl;
            int N = IN.T.size();
            IN.min = numDigits(IN.min);
            IN.max = numDigits(IN.max);
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    word w = {i, j, 0, IN.T[i][j]};
                    BFS(IN, w, HT, hf);
                }
            }
        }

        void partidaPrimerCriterio2(input &IN, const rollingHash &HT, const int &hf) {
            cout << "nononoo" << endl;
            int N = IN.T.size();
            IN.min = numDigits(IN.min);
            IN.max = numDigits(IN.max);
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    word w = {i, j, 0, IN.T[i][j]};
                    BFS2(IN, w, HT, hf);
                }
            }
        }

};
