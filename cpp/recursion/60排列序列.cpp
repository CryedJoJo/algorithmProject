#include <bits/stdc++.h>

using namespace std;
vector<int> used;
int sum;
void dfs(int n, int k, string& str);
void findRank(int n, int k){
    used.resize(n+1, 0);
    string str = "";
    dfs(n, k, str);
} 

void dfs(int n, int k, string& str){
    if(str.size() == n){
        sum++;
        if(sum == k)
            cout << str;
        return;
    }

    for(int i = 1; i <= n; ++i){
        if(used[i] != 1){
            str += i + '0';
            used[i] = 1;
            dfs(n, k, str);
            str.pop_back();
            used[i] = 0;
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    findRank(n, k);
    return 0;
}

