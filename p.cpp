#include "Tools.cpp"

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
    Tools TT;
    word p = {3,3,1,T[3][3]};
    TT.BFS(T, p, 2, 3);
}
