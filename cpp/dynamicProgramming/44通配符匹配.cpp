#include <bits/stdc++.h>

using namespace std;

void pf(vector<vector<bool>>& v){
    for(const auto& line: v){
        for(const auto& e:line){
            cout << e << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void fun(string& s, string& p){
    int pn = p.size();
    int sn = s.size();
    vector<vector<bool>> dp(pn+1, vector<bool>(sn+1, false));
    dp[0][0] = true;

    for(int i = 0; i < pn; ++i){
        if(p[i] == '*' && dp[i][i]){
            cout << "p[" << i << "]:" << p[i] << "\n";
            int pos = i + 1;
            while(pos <= sn){
                dp[i+1][pos] = true;
                pos++;
                pf(dp);
            }
            continue;
        }
        for(int j = i; j < sn; ++j){
            if(p[i] == s[j] || p[i] == '?'){
                cout << "p[" << i << "]:" << p[i] << "\n";
                cout << "s[" << j << "]:" << s[j] << '\n';
                dp[i+1][j+1] = dp[i][j];
                pf(dp);
            }
        }
    }
    cout << "result:\n";
    pf(dp);
    if(dp[pn][sn]) cout << "true";
    else cout << "false";
}

int main(){
    string s, p;
    cin >> s >> p;
    fun(s, p);
    return 0;
}
