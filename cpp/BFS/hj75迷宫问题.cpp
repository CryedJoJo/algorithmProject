#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<vector<int>> mat;
int xs, ys, xt, yt;
vector<vector<int>> pos = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void dfs(int i, int j, vector<pair<int,int>>& rot){
    if(i < 0 || j < 0 || i >= h || j >= w) return;
    if(mat[i][j] != 0) return;
    mat[i][j] = 1;
    pair<int, int> p = {i, j};
    rot.push_back(p);
    if(i == xt && j == yt){
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
    cin >> xs >> ys >> xt >> yt;
    xs--;ys--;xt--;yt--;
    mat.resize(h, vector<int>(w));
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j)
            cin >> mat[i][j];
    vector<pair<int, int>> rot;
    dfs(xs, ys, rot);
    return 0;
}

