/*
 输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
输出：5
0201
0101
0202
1212
2002
0202
6
 */

#include <bits/stdc++.h>
using namespace std;

unordered_set<string> deadwd;
unordered_set<string> visited;
int steps = 0;

void findPW(vector<string>& deadends, string target){
    unordered_set<string> deadSet(deadends.begin(), deadends.end());
    if(deadSet.count("0000")){
        cout << -1; return;
    }
    visited.insert("0000");
    int step = 0;
    queue<string> q;
    q.push("0000");
    while(!q.empty()){
        int size = q.size();
        while(size--){
            string pw = q.front();q.pop();

            if(pw == target){
                cout << step;
                return;
            }
            for(int i = 0; i < pw.size(); ++i){
                char old = pw[i];

                pw[i] = (old == '9') ? '0': old + 1;
                if(!deadSet.count(pw) && !visited.count(pw)){
                    visited.insert(pw);
                    q.push(pw);
                }

                pw[i] = (old == '0') ? '9': old-1;
                if(!deadSet.count(pw) && !visited.count(pw)){
                    visited.insert(pw);
                    q.push(pw);
                }

                pw[i] = old;
            }

        }
        step++;
    }
    cout << -1;
    return;
}


int main()
{
    vector<string> dead;
    int n;
    cin >> n;
    string target;
    string cur;
    while(n){
        n--;
        cin >> cur;
        dead.push_back(cur);
    }
    cin >> target;
    findPW(dead, target);

    return 0;
}

//不给n 怎么输入 
//int main(){
//    vector<string> deadends;
//    string line;
//    getline(cin, line);          // 第一行
//    stringstream ss(line);
//
//    string s;
//    while (ss >> s) {
//        deadends.push_back(s);
//    }
//
//    string target;
//    cin >> target;
//    
//}

