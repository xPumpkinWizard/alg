#include "solve.h"
#include "vertex.h"
#include <vector>
#include <unordered_set>
#include <queue>
#include <iostream>

using namespace std;

unordered_map<string, Vertex*> vSet;
unordered_map<Vertex*, Vertex*> bCrumbs;
int rC[2];

bool onB(string maze, int r, int c) {
    return (r == 0 || c == 0 || r == rC[0] || c == rC[1]);
}

bool chkTop(int r, int c) {
    string key = to_string(r - 1) + "," + to_string(c);
    return (vSet.find(key) != vSet.end());
}

bool chkLeft(int r, int c) {
    string key = to_string(r) + "," + to_string(c - 1);
    return (vSet.find(key) != vSet.end());
}

int findIdx(string maze, int r, int c) {
    return (r * (rC[1] + 2)) + c;
}

void addE(string a, string b) {
    Vertex* aV = vSet[a];
    Vertex* bV = vSet[b];
    aV->neighs.push_back(bV);
    bV->neighs.push_back(aV);
}

void bfs(string src) {
    queue<Vertex*> Q;
    unordered_set<Vertex*> marked;

    Vertex* s = vSet[src];
    marked.insert(s);
    Q.push(s);

    while (!Q.empty()) {
        Vertex* x = Q.front();
        Q.pop();

        for (int i = 0; i < x->neighs.size(); i++) {
            Vertex* y = x->neighs[i];
            if (marked.find(y) == marked.end()) {
                marked.insert(y);
                Q.push(y);
                bCrumbs[y] = x;
            }
        }
    }
}

string shortPth(string* startEnd, string maze) {
    Vertex* s = vSet[startEnd[0]];
    Vertex* t = vSet[startEnd[1]];

    bfs(startEnd[0]);

    Vertex* cur = t;
    while (cur != s) {
        maze[findIdx(maze, cur->row, cur->col)] = 'o';
        cur = bCrumbs[cur];
    }

    maze[findIdx(maze, s->row, s->col)] = 'o';
    cout << maze;

    return maze;
}

void findRC(string maze) {
    rC[0] = 0; rC[1] = 0;
    for (int i = 0; i < maze.size() - 1; i++) {
        if (maze[i] == '\n') {
            rC[1] = i + 1;
            break;
        }
    }
    rC[0] = (maze.size() / rC[1]) - 1;
    rC[1] = rC[1] - 2;
}

string* createG(string maze) {
    static string startEnd[2]; startEnd[0] = ""; startEnd[1] = "";
    int borderCount = 0;
    int r = 0; int c = 0;
    for (int i = 0; i < maze.size() - 1; i++) {
        if (maze[i] == ' ') {
            if (onB(maze, r, c) && borderCount == 0) {
                Vertex* v = new Vertex(r, c);
                string coor = to_string(r) + "," + to_string(c);
                vSet[coor] = v;
                startEnd[0] = coor;
                if (chkTop(r, c)) {
                    string coorTop = to_string(r - 1) + "," + to_string(c);
                    addE(coor, coorTop);
                }
                if (chkLeft(r, c)) {
                    string coorLeft = to_string(r) + "," + to_string(c - 1);
                    addE(coor, coorLeft);
                }
                borderCount++;
            }
            else if (onB(maze, r, c) && borderCount == 1) {
                Vertex* v = new Vertex(r, c);
                string coor = to_string(r) + "," + to_string(c);
                vSet[coor] = v;
                startEnd[1] = coor;
                if (chkTop(r, c)) {
                    string coorTop = to_string(r - 1) + "," + to_string(c);
                    addE(coor, coorTop);
                }
                if (chkLeft(r, c)) {
                    string coorLeft = to_string(r) + "," + to_string(c - 1);
                    addE(coor, coorLeft);
                }
            }
            else {
                Vertex* v = new Vertex(r, c);
                string coor = to_string(r) + "," + to_string(c);
                vSet[coor] = v;
                if (chkTop(r, c)) {
                    string coorTop = to_string(r - 1) + "," + to_string(c);
                    addE(coor, coorTop);
                }
                if (chkLeft(r, c)) {
                    string coorLeft = to_string(r) + "," + to_string(c - 1);
                    addE(coor, coorLeft);
                }
            }
        }
        if (maze[i] == '\n') { r++; c = 0; }
        else { c++; }
    }
    return startEnd;
}

string solve(string maze) {
    vSet.clear();
    bCrumbs.clear();
    findRC(maze);
    return shortPth(createG(maze), maze);
}
