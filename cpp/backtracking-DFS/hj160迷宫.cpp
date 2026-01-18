#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<char>> mp;
bool can = false;
vector<vector<int>> dict = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};


void dfs1(int i, int j){ 
    if(i < 0 || j < 0 || i >= N || j >= M) return;
    if(mp[i][j] == 'E'){
        can = true; //如果洪泛就能到达，直接返回
        return;
    }
    cout << __LINE__ << "\n";
    if(mp[i][j] != '.') return;
    mp[i][j] = 'S';
    for(auto p:dict) dfs1(i+p[0], j+p[1]);//将S或E能触及到的地方洪泛
}
void dfs2(int i, int j){ 
    if(i < 0 || j < 0 || i >= N || j >= M) return;
    if(mp[i][j] == 'S'){
        can = true; //如果洪泛就能到达，直接返回
        return;
    }
    cout << __LINE__ << "\n";
    if(mp[i][j] != '.') return;
    //cout << "i:" << i << " j:" << j<< " line:" << __LINE__ << "\n";
    mp[i][j] = 'E';
    for(auto p:dict) dfs2(i+p[0], j+p[1]);//将S或E能触及到的地方洪泛
}
void dfs3(int i, int j, int p1, int p2){
    if(i < 0 || j < 0 || i >= N || j >= M) return;
    for(auto p:dict) { //如果上下左右能接触到E，说明能到
        int ni = i+p[0];
        int nj = j+p[1];
        if(ni < 0 || nj < 0 || ni >= N || nj >= M) 
            continue;
        if(mp[ni][nj] == 'E'){
            can = true;
            return;
         }
    }
    dfs3(i+p1, j+p2, p1, p2);
}
void pf(){
    for(auto line: mp){
        for(auto e:line)
            cout << e << " ";
        cout << '\n';    
    }
    cout << "\n";
}

void fun(){
    bool fe = true, fs = true;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(mp[i][j] == 'S' && fs){
                fs = false;
                for(auto p:dict) dfs1(i+p[0], j+p[1]); //一直向同一个方向延伸，看能否到E
                cout << "-----------------------"<<"\n";
            }
            if(mp[i][j] == 'E' && fe){
                fe = false;
                cout << "i:" << i << " j:" << j<< " line:" << __LINE__ << "\n";
                for(auto p:dict) dfs2(i+p[0], j+p[1]); //一直向同一个方向延伸，看能否到E
            }
        }
    }
    cout << "after reflection" << "\n";
    pf();
    if(can){
        return;
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(mp[i][j] == 'S'){
                for(auto p:dict){
                    dfs3(i, j, p[0], p[1]);
                }
            }
        }
    }
    pf();
}

int main(){

    cin >> N >> M;
    mp.resize(N, vector<char>(M));
    for(int i=0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> mp[i][j];
        }
    }
    pf();
    fun();
    if(can){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}
