#include <bits/stdc++.h>
using namespace std;


void fun(string& s){
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    int maxLen = 0;
    int start = 0;
    for(int i = n-1; i >= 0; --i){
        for(int j = i+1; j < n; ++j){
            if(s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1])){
                dp[i][j] = true;
                if(maxLen < j-i+1){
                    maxLen = j - i + 1;
                    start = i;
                }
            }
        }
    }
    cout << s.substr(start, maxLen);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    fun(s);
    return 0;
}
