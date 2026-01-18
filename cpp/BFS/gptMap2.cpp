#include <bits/stdc++.h>
using namespace std;

static const int N = 1000;

char maze[N][N];
bool vis[N][N];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

inline bool inside(int x, int y) {
    return x > 0 && x < N - 1 && y > 0 && y < N - 1;
}

// 非递归 DFS 生成完美迷宫
void generateMaze(int sx, int sy) {
    stack<pair<int,int>> st;
    st.push({sx, sy});
    vis[sx][sy] = true;
    maze[sx][sy] = '.';

    while (!st.empty()) {
        auto [x, y] = st.top();

        vector<int> dir = {0, 1, 2, 3};
        random_shuffle(dir.begin(), dir.end());

        bool expanded = false;

        for (int d : dir) {
            int nx = x + dx[d] * 2;
            int ny = y + dy[d] * 2;

            if (inside(nx, ny) && !vis[nx][ny]) {
                // 打通中间墙
                maze[x + dx[d]][y + dy[d]] = '.';
                maze[nx][ny] = '.';
                vis[nx][ny] = true;

                st.push({nx, ny});
                expanded = true;
                break;
            }
        }

        // 四个方向都走不了，回溯
        if (!expanded) {
            st.pop();
        }
    }
}

int main() {
    srand(time(nullptr));

    // 1️⃣ 初始化全是墙
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            maze[i][j] = '*';
            vis[i][j] = false;
        }
    }

    // 2️⃣ 生成迷宫（从 (1,1) 开始）
    generateMaze(1, 1);

    // 3️⃣ 选择唯一入口 & 出口（边界）
    vector<pair<int,int>> border;

    for (int i = 1; i < N - 1; ++i) {
        if (maze[i][1] == '.')     border.push_back({i, 0});
        if (maze[i][N-2] == '.')   border.push_back({i, N-1});
        if (maze[1][i] == '.')     border.push_back({0, i});
        if (maze[N-2][i] == '.')   border.push_back({N-1, i});
    }

    // 至少保证两个
    random_shuffle(border.begin(), border.end());
    auto entrance = border[0];
    auto exitp    = border[1];

    maze[entrance.first][entrance.second] = '.';
    maze[exitp.first][exitp.second] = '.';

    // 4️⃣ 随机出生点（任意一个 '.'）
    int bx, by;
    do {
        bx = rand() % N;
        by = rand() % N;
    } while (maze[bx][by] != '.');

    // 输出坐标（1-based）
    cout << "Entrance: (" << entrance.first + 1 << ", " << entrance.second + 1 << ")\n";
    cout << "Exit: (" << exitp.first + 1 << ", " << exitp.second + 1 << ")\n";
    cout << "Birth: (" << bx + 1 << ", " << by + 1 << ")\n";

    // 5️⃣ 输出迷宫到文件
    ofstream fout("maze.txt");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            fout << maze[i][j];
        }
        fout << '\n';
    }
    fout.close();

    return 0;
}

