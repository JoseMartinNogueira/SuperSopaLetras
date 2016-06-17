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
#include <ctime>

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
        double tTotal;
        double tBusqueda;
        time_t start;
        double tOut;

	public:
        Tools() {
             I = new int[8] {-1, -1, -1,  0, 0,  1, 1, 1};
             J = new int[8] {-1,  0,  1, -1, 1, -1, 0, 1};
             tTotal = 0;
             tBusqueda = 0;
        }

        double getTBusqueda() const {
            return tBusqueda;
        }

        double getTTotal() const {
            return tTotal;
        }

        void BFS(input &IN, word &w, hashTable &HT, const int &hf) {
            clock_t startBFS = clock();
            int  N = IN.T.size();
            queue<word> Q;
            Q.push(w);
            double timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            //cout << " min: " << IN.min << ", max: " << IN.max << endl;
            while (not Q.empty() && tOut > timeO ) {
                word act = Q.front();
                Q.pop();
                ////////////////////////////
                //cout << "(" << act.x << "," << act.y << ") " << act.value;

                if((act.depth >= IN.min) and (HT.contains(act.value, hf))) {
                    ++IN.contador;
                    cout << act.value << endl;
                    HT.deleteH(act.value, hf);
                }

                ////////////////////////////
                for (int i = 0; i < 8; ++i) {
                    int x = act.x + I[i];
                    int y = act.y + J[i];
                    if(x >= 0 and x < N and y >= 0 and y < N and act.depth +1 <= IN.max ) {
                        word nw = {x, y, act.depth + 1, act.value*10 + IN.T[x][y]};
                        Q.push(nw);
                    }
                }
                timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            }
            clock_t endBFS = clock();
            tBusqueda = (endBFS - startBFS)/double(CLOCKS_PER_SEC)*1000;
        }

        void BFSTablero(input &IN, word &w, hashTable &HT, const int &hf) {
            clock_t startBFS = clock();
            hashFunctions HF;
            int  N = IN.T.size();
            queue<word> Q;
            Q.push(w);
            double timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            //cout << " min: " << IN.min << ", max: " << IN.max << endl;
            while (not Q.empty() && tOut > timeO ) {
                word act = Q.front();
                Q.pop();

                if(act.depth >= IN.min) {
                    cout << act.value << endl;
                    HT.insert(HF.hashFunction( act.value, hf, HT.getSize()), act.value);
                }

                ////////////////////////////
                for (int i = 0; i < 8; ++i) {
                    int x = act.x + I[i];
                    int y = act.y + J[i];
                    if(x >= 0 and x < N and y >= 0 and y < N and act.depth +1 <= IN.max ) {
                        word nw = {x, y, act.depth + 1, act.value*10 + IN.T[x][y]};
                        Q.push(nw);
                    }
                }
                timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            }
            clock_t endBFS = clock();
            tBusqueda = (endBFS - startBFS)/double(CLOCKS_PER_SEC)*1000;
        }

        void BFS2(input &IN, word &w, rollingHash &RH, hashTable &HT, const int &hf) {
            clock_t startBFS = clock();
            int  N = IN.T.size();
            bool aux;
            queue<word> Q;
            Q.push(w);

            double timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;

            while (not Q.empty() && tOut > timeO ) {
                word act = Q.front();
                Q.pop();
                ////////////////////////////
                aux = HT.contains( act.value, hf );
                if((act.depth >= IN.min) and aux ) {
                    cout << "BORRO"<< endl;
                    RH.deletePrefix( act.value, hf );
                    HT.deleteH( act.value, hf );
                    ++IN.contador;
                    cout << act.value << endl;
                }
                if( RH.containsRH( act.value, hf, 1 ) ) {
                    for (int i = 0; i < 8; ++i) {
                        int x = act.x + I[i];
                        int y = act.y + J[i];
                        if(x >= 0 and x < N and y >= 0 and y < N and act.depth +1 <= IN.max ) {
                            word nw = {x, y, act.depth + 1, act.value*10 + IN.T[x][y]};
                            Q.push(nw);
                        }
                    }
                }
            }

            clock_t endBFS = clock();
            tBusqueda = (endBFS - startBFS)/double(CLOCKS_PER_SEC)*1000;
        }

        void DFS(input &IN, word &w, hashTable &HT, const int &hf) {
            clock_t startBFS = clock();
            int  N = IN.T.size();
            stack<word> Q;
            Q.push(w);
            double timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            //cout << " min: " << IN.min << ", max: " << IN.max << endl;
            while (not Q.empty() && tOut > timeO ) {
                word act = Q.top();
                Q.pop();
                ////////////////////////////
                //cout << "(" << act.x << "," << act.y << ") " << act.value;

                if((act.depth >= IN.min) and (HT.contains(act.value, hf))) {
                    ++IN.contador;
                    cout << act.value << endl;
                    HT.deleteH(act.value, hf);
                }

                ////////////////////////////
                for (int i = 0; i < 8; ++i) {
                    int x = act.x + I[i];
                    int y = act.y + J[i];
                    if(x >= 0 and x < N and y >= 0 and y < N and act.depth +1 <= IN.max ) {
                        word nw = {x, y, act.depth + 1, act.value*10 + IN.T[x][y]};
                        Q.push(nw);
                    }
                }
                timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            }
            clock_t endBFS = clock();
            tBusqueda = (endBFS - startBFS)/double(CLOCKS_PER_SEC)*1000;
        }

        void DFSTablero(input &IN, word &w, hashTable &HT, const int &hf) {
            clock_t startBFS = clock();
            hashFunctions HF;
            int  N = IN.T.size();
            stack<word> Q;
            Q.push(w);
            double timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            //cout << " min: " << IN.min << ", max: " << IN.max << endl;
            while (not Q.empty() && tOut > timeO ) {
                word act = Q.top();
                Q.pop();
                ////////////////////////////
                //cout << "(" << act.x << "," << act.y << ") " << act.value;

                if(act.depth >= IN.min) {
                    HT.insert(HF.hashFunction( act.value, hf, HT.getSize()), act.value);
                }

                ////////////////////////////
                for (int i = 0; i < 8; ++i) {
                    int x = act.x + I[i];
                    int y = act.y + J[i];
                    if(x >= 0 and x < N and y >= 0 and y < N and act.depth +1 <= IN.max ) {
                        word nw = {x, y, act.depth + 1, act.value*10 + IN.T[x][y]};
                        Q.push(nw);
                    }
                }
                timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            }
            clock_t endBFS = clock();
            tBusqueda = (endBFS - startBFS)/double(CLOCKS_PER_SEC)*1000;
        }

        void DFS2(input &IN, word &w, rollingHash &RH, hashTable &HT, const int &hf) {
            clock_t startBFS = clock();
            int  N = IN.T.size();
            bool aux;
            stack<word> Q;
            Q.push(w);

            double timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;

            while (not Q.empty() && tOut > timeO ) {
                word act = Q.top();
                Q.pop();
                ////////////////////////////
                aux = HT.contains( act.value, hf );
                if((act.depth >= IN.min) and aux ) {
                    cout << "BORRO"<< endl;
                    RH.deletePrefix( act.value, hf );
                    HT.deleteH( act.value, hf );
                    ++IN.contador;
                    cout << act.value << endl;
                }
                if( RH.containsRH( act.value, hf, 1 ) ) {
                    for (int i = 0; i < 8; ++i) {
                        int x = act.x + I[i];
                        int y = act.y + J[i];
                        if(x >= 0 and x < N and y >= 0 and y < N and act.depth +1 <= IN.max ) {
                            word nw = {x, y, act.depth + 1, act.value*10 + IN.T[x][y]};
                            Q.push(nw);
                        }
                    }
                }
            }

            clock_t endBFS = clock();
            tBusqueda = (endBFS - startBFS)/double(CLOCKS_PER_SEC)*1000;
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
            for (int i=0; i < n; ++i) {
                vSt[i] = min2 + rand()%(max2 - min2 + 1);
                for (int j = 0; j < i; ++j) if(vSt[i] == vSt[j]) {--i; break;}
            }
            jp.write(reinterpret_cast<const char *>(&vSt), sizeof(vSt));
            jp.close();
        }

        void generarDT(string name, int n, int min, int max, int porcentaje, matrix &T){
            srand(time(NULL));
            ofstream jp(name, ios::binary);
            int min2 = pow(10,min - 1);
            int max2 = pow(10,max) - 1;
            int vals[4] = {n, min2, max2, porcentaje};
            jp.write(reinterpret_cast<const char *>(&vals), sizeof(vals));
            int vSt[n];
            int it = (n*porcentaje)/100;
            for (int i = 0; i < it; ++i) {
                int r = min + rand()%(max - min + 1);
                int x = rand()%T.size();
                int y = rand()%T.size();
                /*
                cout << min << " " << max << " " << r << " " << T.size() << " (";
                cout << x << "," << y << ")" << " e: " << T[x][y];
                */
                vSt[i] = T[x][y];
                for (int j = 1; j < r; ++j)  {
                    int k = rand()%8;
                    int xx = x + I[k];
                    int yy = y + J[k];
                    while (not (xx >= 0 and xx < T.size() and yy >= 0 and yy < T.size())) {
                        k = rand()%8;
                        xx = x + I[k];
                        yy = y + J[k];
                    }
                    x = xx; y = yy;
                    vSt[i] = vSt[i]*10 + T[xx][yy];
                }
                //cout << " ee: " << vSt[i] << endl;
                //vSt[i] = min2 + rand()%(max2 - min2 + 1);
                for (int j = 0; j < i; ++j) if(vSt[i] == vSt[j]) {--i; break;}
            }
            for (int i = it ; i < n; ++i) {
                vSt[i] = min2 + rand()%(max2 - min2 + 1);
                for (int j = 0; j < i; ++j) if(vSt[i] == vSt[j]) {--i; break;}
            }
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
                //cout << n << endl;
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

        void partidaPrimerCriterioBFS1(input &IN, hashTable &HT, const int &hf) {
            clock_t startPartida = clock();
            start = clock();
            cout << "BORRARDOS:" << endl;
            int N = IN.T.size();
            IN.min = numDigits(IN.min);
            IN.max = numDigits(IN.max);
            double timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if( timeO >= tOut ) {
                        return;
                    }
                    word w = {i, j, 1, IN.T[i][j]};
                    BFS(IN, w, HT, hf);
                }
                timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            }
            clock_t endPartida = clock();
            tTotal = (endPartida - startPartida)/double(CLOCKS_PER_SEC)*1000;
        }

        void partidaSegundoCriterioBFS1(input &IN, hashTable &HT, const int &hf) {
            clock_t startPartida = clock();
            start = clock();
            int N = IN.T.size();
            IN.min = numDigits(IN.min);
            IN.max = numDigits(IN.max);
            double timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if( timeO >= tOut ) {
                        cout << "TIME LIMIT "<<endl;
                        return;
                    }
                    word w = {i, j, 1, IN.T[i][j]};
                    BFSTablero(IN, w, HT, hf);
                }
                timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            }
            clock_t endPartida = clock();
            tTotal = (endPartida - startPartida)/double(CLOCKS_PER_SEC)*1000;
        }

        void partidaPrimerCriterioBFS2(input &IN, rollingHash &RH, hashTable& HT, const int &hf) {
            cout << "nononoo" << endl;
            start = clock();
            clock_t startPartida = clock();
            int N = IN.T.size();
            IN.min = numDigits(IN.min);
            IN.max = numDigits(IN.max);
            double timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N ; ++j) {
                     if( timeO >= tOut ) {
                        cout << "TIME LIMIT "<<endl;
                        return;
                    }
                    word w = {i, j, 1, IN.T[i][j]};
                    BFS2(IN, w, RH, HT, hf);
                }
            }
            clock_t endPartida = clock();
            tTotal = (endPartida - startPartida)/double(CLOCKS_PER_SEC)*1000;
        }

        void partidaPrimerCriterioDFS1(input &IN, hashTable &HT, const int &hf) {
            clock_t startPartida = clock();
            start = clock();
            cout << "BORRARDOS:" << endl;
            int N = IN.T.size();
            IN.min = numDigits(IN.min);
            IN.max = numDigits(IN.max);
            double timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if( timeO >= tOut ) {
                        cout << "TIME LIMIT "<<endl;
                        return;
                    }
                    word w = {i, j, 1, IN.T[i][j]};
                    DFS(IN, w, HT, hf);
                }
                timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            }
            clock_t endPartida = clock();
            tTotal = (endPartida - startPartida)/double(CLOCKS_PER_SEC)*1000;
        }

        void partidaSegundoCriterioDFS1(input &IN, hashTable &HT, const int &hf) {
            clock_t startPartida = clock();
            start = clock();
            int N = IN.T.size();
            IN.min = numDigits(IN.min);
            IN.max = numDigits(IN.max);
            double timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if( timeO >= tOut ) {
                        cout << "TIME LIMIT "<<endl;
                        return;
                    }
                    word w = {i, j, 1, IN.T[i][j]};
                    DFSTablero(IN, w, HT, hf);
                }
                timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            }
            clock_t endPartida = clock();
            tTotal = (endPartida - startPartida)/double(CLOCKS_PER_SEC)*1000;
        }

        void partidaPrimerCriterioDFS2(input &IN, rollingHash &RH, hashTable& HT, const int &hf) {
            cout << "nononoo" << endl;
            start = clock();
            clock_t startPartida = clock();
            int N = IN.T.size();
            IN.min = numDigits(IN.min);
            IN.max = numDigits(IN.max);
            double timeO = (clock()-start)/(double)(CLOCKS_PER_SEC)*1000;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N ; ++j) {
                    
                    if( timeO >= tOut ) {
                        cout << "TIME LIMIT "<<endl;
                        return;
                    }
                    word w = {i, j, 1, IN.T[i][j]};
                    DFS2(IN, w, RH, HT, hf);
                }
            }
            clock_t endPartida = clock();
            tTotal = (endPartida - startPartida)/double(CLOCKS_PER_SEC)*1000;
        }

        void setTime(double d) {
            tOut = d;
        }

        bool timeOut() {
            //while (1) cout << "timepo: " << !(difftime(time(0), start) < tOut) << endl;
            return difftime(time(0), start) > tOut;

        }

};
