#include <bits/stdc++.h>
using namespace std;

static const int H = 1000;
static const int W = 1000;

int xs, ys, xt, yt;
vector<vector<int>> mat(H, vector<int>(W));
vector<vector<pair<int,int>>> pre(H, vector<pair<int,int>>(W, {-1,-1}));

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    /* 1. 读 maze.txt */
    ifstream fin("maze.txt");
    if (!fin) {
        cerr << "Failed to open maze.txt\n";
        return 1;
    }

    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            fin >> mat[i][j];

    fin.close();

    /* 2. 起点终点 */
    cin >> xs >> ys >> xt >> yt;
    xs--; ys--; xt--; yt--;

    queue<pair<int,int>> q;
    q.push({xs, ys});
    mat[xs][ys] = 1;  // 标记访问

    bool found = false;

    /* 3. BFS */
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == xt && y == yt) {
            found = true;
            break;
        }
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if (mat[nx][ny] != 0) continue;
            mat[nx][ny] = 1;
            pre[nx][ny] = {x, y};
            q.push({nx, ny});
        }
    }

    if (!found) {
        cout << "No path\n";
        return 0;
    }

    /* 4. 回溯路径 */
    vector<pair<int,int>> path;
    for (int x = xt, y = yt; x != -1; ) {
        path.push_back({x, y});
        auto p = pre[x][y];
        x = p.first;
        y = p.second;
    }

    reverse(path.begin(), path.end());

    for (auto &p : path) {
        cout << "(" << p.first << "," << p.second << ")\n";
    }

    return 0;
}

