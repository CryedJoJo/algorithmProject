#include <bits/stdc++.h>
using namespace std;

static const int N = 1000;
char maze[N][N];
bool vis[N][N];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool inside(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// DFS 生成完美迷宫
void dfs(int x, int y) {
    vis[x][y] = true;
    maze[x][y] = '.';

    vector<int> dir = {0, 1, 2, 3};
    random_shuffle(dir.begin(), dir.end());

    for (int d : dir) {
        int nx = x + dx[d] * 2;
        int ny = y + dy[d] * 2;
        if (inside(nx, ny) && !vis[nx][ny]) {
            maze[x + dx[d]][y + dy[d]] = '.';
            dfs(nx, ny);
        }
    }
}

int main() {
    srand(time(nullptr));

    // 1️⃣ 初始化为墙
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            maze[i][j] = '*';

    // 2️⃣ 从 (1,1) 开始挖迷宫
    dfs(1, 1);

    // 3️⃣ 随机入口 & 出口（边界）
    vector<pair<int,int>> border;

    for (int i = 1; i < N - 1; ++i) {
        if (maze[i][1] == '.') border.push_back({i, 0});
        if (maze[i][N-2] == '.') border.push_back({i, N-1});
        if (maze[1][i] == '.') border.push_back({0, i});
        if (maze[N-2][i] == '.') border.push_back({N-1, i});
    }

    random_shuffle(border.begin(), border.end());

    auto entrance = border[0];
    auto exitp = border[1];

    maze[entrance.first][entrance.second] = '.';
    maze[exitp.first][exitp.second] = '.';

    // 4️⃣ 随机出生点（任意 '.'）
    int sx, sy;
    while (true) {
        sx = rand() % N;
        sy = rand() % N;
        if (maze[sx][sy] == '.') break;
    }

    // 输出关键信息
    cout << "Entrance: (" << entrance.first+1 << ", " << entrance.second+1 << ")\n";
    cout << "Exit: (" << exitp.first+1 << ", " << exitp.second+1 << ")\n";
    cout << "Birth: (" << sx+1 << ", " << sy+1 << ")\n";

    // ⚠️ 如需输出迷宫到文件：
    ofstream fout("maze.txt");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            fout << maze[i][j];
        fout << '\n';
    }
}

