#include <bits/stdc++.h> //solo
#include <unordered_map>
#include <vector>
using namespace std;

void fun(string& a, string& b){
    int aLen = a.size(); 
    int bLen = b.size();
    string sortStr, longStr;
    int more, less;
    
    //①找出短字符串
    if(aLen < bLen){ 
        less = aLen; more = bLen;
        sortStr = a; longStr = b;
    } else {
        less = bLen; more = aLen;
        sortStr = b; longStr = a;
    }

    //②dp数组构建，生成有效数据
    vector<vector<int>> dp(less+1, vector<int>(more+1, 0));
    map<int, int> posLen; //记录子串 起始位置 和 切割长度
    int maxLen = 0;
    
    for(int i = 0; i < less; ++i){
        for(int j = 0; j < more; ++j){
            if(sortStr[i] == longStr[j]){
                dp[i+1][j+1] = dp[i][j]+1;
                if(maxLen <= dp[i+1][j+1]){
                    maxLen = dp[i+1][j+1];
                    //i 是 当前最长子串的最后一个字母的下标
                    int start = i - maxLen + 1;
                    //子串开始位置i - maxLen + 1;
                    posLen[start] = maxLen; 
                    //maxLen 表示最长字串长度
                    
                }
            }
        }
    }

    //③查找最终结果
    int start = less-1;
    for(auto e:posLen){
        if(e.second == maxLen){
            if(e.first < start){
                start = e.first;
            }
        }
    }
    if(maxLen == 0){
        cout << "";
        return;
    }
    cout << sortStr.substr(start, maxLen);
}

int main() {
    string a, b;
    while (cin >> a >> b) {
        fun(a, b);
    }
    return 0;
}
