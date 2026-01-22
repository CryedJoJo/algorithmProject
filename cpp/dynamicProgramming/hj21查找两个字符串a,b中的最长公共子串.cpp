#include <bits/stdc++.h> //solo
#include <unordered_map>
#include <vector>
using namespace std;

void fun(string& a, string& b){
    int na = a.size(); 
    int nb = b.size();
    string ls, mr;
    int more, less;
    if(na < nb){ //比较长度，记录大小
        less = na;
        more = nb;
        ls = a;
        mr = b;
    } else {
        less = nb;
        more = na;
        ls = b;
        mr = a;
    }
    vector<vector<int>> dp(less+1, vector<int>(more+1, 0));
    int maxLen = 0;
    map<int, int> posLen;
    
    // 先遍历短字符串
    for(int i = 0; i < less; ++i){
        for(int j = 0; j < more; ++j){
            if(ls[i] == mr[j]){
                dp[i+1][j+1] = dp[i][j]+1;
                if(maxLen <= dp[i+1][j+1]){
                    maxLen = dp[i+1][j+1];
                    int start = i - maxLen + 1;
                    //开始位置就是 i - maxLen + 1
                    posLen[start] = maxLen; 
                    //maxLen 表示最长字串长度
                    //i 表示 最长字串的最后一个字母的位置
                }
            }
        }
    }
    int start = less-1;
    for(auto e:posLen){
        if(e.second == maxLen){
            if(e.first < start){
                start = e.first;
            }
        }
    }
    cout << ls.substr(start, maxLen);
}

int main() {
    string a, b;
    while (cin >> a >> b) {
        fun(a, b);
    }
    return 0;
}
