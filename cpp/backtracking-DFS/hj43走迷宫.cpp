#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<vector<int>> mat;
vector<vector<int>> pos = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void dfs(int i, int j, vector<pair<int,int>>& rot){
    if(i < 0 || j < 0 || i >= h || j >= w) return;
    if(mat[i][j] != 0) return;
    mat[i][j] = 1;
    rot.push_back({i, j});
    if(i == h-1 && j == w-1){
        for(auto r:rot){
            cout<<'('<<r.first<<','<<r.second<<')'<<'\n';
        }
        return;
    }
    for(auto p:pos) dfs(i+p[0], j+p[1], rot);
    rot.pop_back();
    mat[i][j] = 0;
}

int main(){
    cin >> h >> w;
    //mat.resize(h, vector<int>(w));
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j)
            cin >> mat[i][j]; //这儿没有给mat容量，mat[i]是空指针，直接用会段错误
    vector<pair<int, int>> rot;
    dfs(0, 0, rot);
    return 0;
}

