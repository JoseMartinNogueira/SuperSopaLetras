#include "Tools.h"

typedef vector< vector<int> > matrix;

Tools::Tools() {
     I = new int[8] {-1, -1, -1,  0, 0,  1, 1, 1};
     J = new int[8] {-1,  0,  1, -1, 1, -1, 0, 1};
}

void Tools::BFS(const vector< vector<int> > &T, word &w, const int &minDepth, const int &maxDepth) {
    int  N = T.size();
    queue<word> Q;
    Q.push(w);

    while (not Q.empty()) {
        word act = Q.front();
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

void Tools::DFS(const vector< vector<int> > &T, word &w, const int &minDepth, const int &maxDepth) {
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

void Tools::construirHash(const vector< vector<int> > &T, const int &minDepth, const int &maxDepth) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            word w = {i, j, 0, T[i][j]};
            BFS(T, w, 1, maxDepth);
        }
    }
}

int Tools::numDigits(int x) {
    int l = 1;
    while (x /= 10) ++l;
    return l;
}
//Repasar que no haya repetidos en el diccionario.
void Tools::generarD(string name, int n, int min, int max, int porcentaje){
    srand(time(NULL));
    ofstream jp(name, ios::binary);
    int vals[4] = {n, min, max, porcentaje};
    jp.write(reinterpret_cast<const char *>(&vals), sizeof(vals));
    int vSt[n];
    for (int i=0; i < n; ++i) vSt[i] = min + rand()%(max - min + 1);
    jp.write(reinterpret_cast<const char *>(&vSt), sizeof(vSt));
    jp.close();
}

void Tools::generarDT(string name, int n, int min, int max, int porcentaje, matrix &T){
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



void Tools::generarT(string name, int n){
    ofstream jp(name, ios::binary);
    jp.write(reinterpret_cast<const char *>(&n), sizeof(int));
    int vSt[n*n];
    for (int i = 0; i < n*n; ++i) {
        vSt[i] = rand()%10;
    }
    jp.write(reinterpret_cast<const char *>(&vSt), sizeof(vSt));
    jp.close();
}

void Tools::leerDiccionario(const string &name, input& atributos) {
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

void Tools::leerTablero(const string &name, input& atributos) {
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
