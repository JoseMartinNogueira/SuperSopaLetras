#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

struct word {
    int x;
    int y;
    int depth;
    int value;
};

int I[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
int J[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

void BFS(const vector< vector<int> > &T, word &w, const int &maxDepth) {
    int  N = T.size();
    queue<word> Q;
    Q.push(w);

    while (not Q.empty()) {
        word act = Q.front();
        Q.pop();
        ////////////////////////////
        cout << act.value << endl;
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
/////////////////////////////////////////
//tiene que haber dos BFS uno que meta indiscriminadamente en el hash, y otro que compruebe apalabras en el
//hash, solo cambiaría el codigo entre la sección marcada



////////////////////////////////////////////
// Funfción para construir el hash a partir de Tablero

void insertHash(const vector< vector<int> > &T, const int &maxDepth) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            word w = {i, j, 0, T[i][j]};
            BFS(T, w, maxDepth);
        }
    }
}


/////////////////////////////////////////////////
int main() {
    vector< vector<int> > T(10, vector<int> (10));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            T[i][j] = j;
        }
    }

    cout << endl << "Tablero" << endl << endl;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) cout << T[i][j] << "\t";
        cout << endl;
    }
    cout << endl << "-------------------------------------------------" << endl;
    word p = {3,3,0,T[3][3]};
    BFS(T, p, 1);
}
