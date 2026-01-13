#include <bits/stdc++.h>
using namespace std;

vector<int> children;

void fun(){
    // 1 0 2 9 2
    // 2 1 2 3 1
    //children.emplace_back(0);
    vector<int> dp(children.size(), 1);
    for(int i = 0; i < children.size(); ++i){
        if(i == 0 && children[i] >= children[i+1]){
            dp[i]++; continue;
        }
        if(children[i-1] < children[i] || (i+1 < children.size() && children[i] >= children[i+1])){
            dp[i] = max(dp[i-1], dp[i+1])+1; continue;
        }
    }
    int count = 0;
    for(auto num:dp){
        count += num;
    }
    cout << count;
}

int main(){
    
    int n;
    cin >> n;
    while(n--){
        int score; cin >> score;
        children.emplace_back(score);
    }
    fun();
    return 0;
}
