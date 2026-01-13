#include <bits/stdc++.h>

using namespace std;

vector<string> dead;
unordered_set<string> deadSet;
unordered_set<string> used;

void find(string target){
    for(auto pw:dead){
        deadSet.insert(pw);
        if(pw == "0000"){
            cout << -1;return;
        }
    }
    if(target == "0000"){
        cout << 0;
        return;
    }
    queue<string> q;
    q.push("0000");
    used.insert("0000");
    int step = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            string cur = q.front(); q.pop();
            
            if(cur == target){
                cout << step; return;
            }

            for(int i = 0; i < cur.size(); ++i){
                char old = cur[i];
                
                //向上拨
                cur[i] = (old == '9') ? '0':old+1;
                if(!deadSet.count(cur) && !used.count(cur)){
                    used.insert(cur);
                    q.push(cur);
                }

                //向下拨
                cur[i] = (old == '0')? '9':old-1;
                if(!deadSet.count(cur) && !used.count(cur)){
                    used.insert(cur);q.push(cur);
                }
                
                cur[i] = old;
            }
        }
        step++;
 
    }
    cout << -1;
}


int main(){
    int n;
    cin >> n;
    while(n){
        string cur; cin >> cur;
        dead.emplace_back(cur); n--;
    }
    string target; cin >> target;
    find(target);
    return 0;
}
