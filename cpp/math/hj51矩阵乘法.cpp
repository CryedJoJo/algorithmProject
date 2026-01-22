#include <bits/stdc++.h>
using namespace std;

void fun() {
    int a, b, c;
    vector<vector<int>> v1;
    vector<vector<int>> v2;
    while (cin >> a >> b >> c) { // 注意 while 处理多个 case
        v1.resize(a, vector<int>(b));
        v2.resize(b, vector<int>(c));
        for(int i = 0; i < a; ++i){
            for(int j = 0; j < b; ++j){
                int cur; cin >> cur;
                v1[i][j] = cur;
            }
        }
        for(int i = 0; i < b; ++i){
            for(int j = 0; j < c; ++j){
                int cur; cin >> cur;
                v2[i][j] = cur;
            }
        }

        vector<vector<int>> result;
        for(int i = 0; i < a; ++i){
            vector<int> cur;
            int k = 0;
            while(k < c){
                int num = 0;
                int j = 0;
                while(j < b){
                    num += v1[i][j] * v2[j][k];
                    ++j;
                }
                ++k;
                cur.push_back(num);
            }
            result.push_back(cur);
        }
        for(auto& line: result){
            for(auto& e:line){
                cout << e << " ";
            }
            cout << '\n';
        }
    }
}

int main(){
    fun();
    return 0;
}
