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

void Tools::construirHash(const vector< vector<int> > &T, const int &maxDepth) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            word w = {i, j, 0, T[i][j]};
            BFS(T, w, 1, maxDepth);
        }
    }
}

//Repasar que no haya repetidos en el diccionario.
void Tools::generar(string name, int n, int min, int max, int porcentaje){
    srand(time(NULL));
    ofstream jp(name, ios::binary);
    int vals[4] = {n, min, max, porcentaje};
    jp.write(reinterpret_cast<const char *>(&vals), sizeof(vals));
    int vSt[n];
    for (int i=0; i < n; ++i) {
        int aux = rand()%max;
        while (aux < min) aux = rand()%max;
        vSt[i] = aux;
    }
    jp.write(reinterpret_cast<const char *>(&vSt), sizeof(vSt));
    jp.close();
}

void Tools::lectura(input& atributos) {
    cout << "Introducir nombre del juego de pruebas con el diccionario ";
    string fileName;
    cin >> fileName;
    cout << endl;
    ifstream dicc( fileName, ios::in | ios::binary);
    //cout << "Introducir juego de pruebas con la sopa de letras(con extension .txt): ";
    //cin >> fileName;
   // cout << endl;
   // ifstream sl( fileName.c_str() ios::in | ios::binary);


    if(dicc) {
        //{n, min, max, porcentaje};
        int vals[4];
        dicc.read(reinterpret_cast<char *>(&vals), sizeof(vals));

        int D[vals[0]];
        cout << "My value is " << vals[0] << endl;
        atributos.D = vector<int>(vals[0]);

        atributos.min = vals[1];
        atributos.max = vals[2];

        dicc.read(reinterpret_cast<char *>(&D), sizeof(D));
         
        for (int i = 0; i < vals[0]; ++i) atributos.D[i] = D[i];
    }
    dicc.close();
    /*if (sl){

    }*/
    
    //sl.close();
}



