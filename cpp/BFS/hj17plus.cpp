#include <bits/stdc++.h>
using namespace std;

int h = 1000, w = 1000;
vector<vector<int>> mat;
int xs, ys, xt, yt;

vector<vector<int>> pos = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

bool found = false;

/* DFS */
void dfs(int i, int j, vector<pair<int,int>>& path) {
    if (found) return;
    if (i < 0 || j < 0 || i >= h || j >= w) return;
    if (mat[i][j] != 0) return;

    mat[i][j] = 1;
    path.push_back({i, j});

    if (i == xt && j == yt) {
        for (auto &p : path) {
            cout << "(" << p.first << "," << p.second << ")\n";
        }
        found = true;
        return;
    }

    for (auto &d : pos) {
        dfs(i + d[0], j + d[1], path);
        if (found) return;
    }

    path.pop_back();
    mat[i][j] = 0;
}

int main() {
    /* ===== 1. 读取 maze.txt ===== */
    ifstream fin("./maze.txt");
    if (!fin.is_open()) {
        cerr << "Failed to open maze.txt\n";
        return 1;
    }

    mat.resize(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            fin >> mat[i][j];
        }
    }
    fin.close();

    /* ===== 2. 起点 & 终点（仍从标准输入） ===== */
    cin >> xs >> ys >> xt >> yt;
    xs--; ys--; xt--; yt--;

    vector<pair<int, int>> path;
    dfs(xs, ys, path);

    if (!found) {
        cout << "No path\n";
    }

    return 0;
}

