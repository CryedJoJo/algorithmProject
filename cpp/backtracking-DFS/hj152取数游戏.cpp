#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> a;
vector<vector<int>> ban;
int ans = 0;

// 8 个方向
vector<vector<int>> pos = {{1, 0}, {0, 1}, {-1, 0}, {0, -1},
                        {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

void dfs(int idx, int curSum) {
    if (idx == N * M) {
        ans = max(ans, curSum);
        return;
    }

    int x = idx / M;
    int y = idx % M;

    // 选择 1：不选当前格子
    dfs(idx + 1, curSum);

    // 选择 2：选当前格子（必须未被禁）
    if (ban[x][y] == 0) {
        // 标记当前格子及 8 邻域
        ban[x][y]++;
        for (auto p:pos) {
            int nx = x + p[0];
            int ny = y + p[1];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                ban[nx][ny]++;
            }
        }

        dfs(idx + 1, curSum + a[x][y]);

        // 回溯
        ban[x][y]--;
        for (auto p:pos) {
            int nx = x + p[0];
            int ny = y + p[1];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                ban[nx][ny]--;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        ans = 0;
        cin >> N >> M;
        a.resize(N, vector<int>(M));
        ban.assign(N, vector<int>(M, 0));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> a[i][j];

        dfs(0, 0);
        cout << ans << "\n";
    }
   
    return 0;
}

