#include <bits/stdc++.h>
#include <vector>
using namespace std;

int n, m;
int xs, ys, xt, yt;
vector<vector<int>> pos = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<char>> g;
void bfs(){
    queue<tuple<int, int, int>> q;
    q.push({xs, ys, 0});

    while(!q.empty()){
        int size = q.size();
        while(size--){
            auto [x, y, d] = q.front(); q.pop();
            if(x == xt && y == yt){
                cout << d;
                return;
            }
            for(auto p: pos){
                int xx = x+p[0];
                int yy = y+p[1];
                if(xx < 0 || yy < 0 || xx >= n || yy >= m)
                    continue;
                if(g[xx][yy] == '*') continue;
                if(g[xx][yy] == '.'){
                    g[xx][yy] = '*';
                    q.push({xx, yy, d+1});
                }
            }
        }
        
    }
    cout << -1;
}

int main() {
    cin >> n >> m;
    cin >> xs >> ys >> xt >> yt;
    xs--;ys--;xt--;yt--;
    ifstream fin("maze.txt");
    if (!fin.is_open()) {
        cerr << "Failed to open maze.txt\n";
        return 1;
    }

    g.resize(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            fin >> g[i][j];
        }
    }
    fin.close();
    bfs();
    return 0;
}
// 64 位输出请用 printf("%lld")
