#include "Tools.h"

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
