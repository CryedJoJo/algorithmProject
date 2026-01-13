#include <bits/stdc++.h>

using namespace std;
unordered_set<string> strSet;
unordered_map<string, int> strLenMap;

void find(string start, string end){
    queue<string> q;
    q.push(start);
    strLenMap[start]++;

    while(!q.empty()){
        string cur = q.front(); q.pop();
        for(int pos = 0; pos < cur.size(); ++pos){
            string newStr = cur;
            for(int i = 1; i <= 26; ++i){
                newStr[pos] = i + 'a';
        
                if(newStr == end){
                    cout << strLenMap[cur] + 1; return;
                }

                if(strSet.count(newStr) && !strLenMap.count(newStr)){
                    strLenMap[newStr] = strLenMap[cur]+1;
                    q.push(newStr);
                }

            }

        }
    }
    cout << -1;
}

int main()
{
    string start, end;
    int n; cin >> n;
    cin >> start >> end;
    while(n){
        string cur; cin >> cur;
        strSet.insert(cur); n--;
    }
    find(start, end);
    return 0;
}

