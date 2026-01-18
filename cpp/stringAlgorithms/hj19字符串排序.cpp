#include <bits/stdc++.h>
#include <cctype>
#include <unordered_map>
using namespace std;

template<class T>
void pf(T t){
    for(auto e:t){
        cout << e;
    }
    cout << '\n';
}

// vector<pair<char, int>> vc;
vector<char> vc;
unordered_map<int, char> um;
void fun(string& s){
    int gap = 'a'-'A';
    for(int i = 0; i < s.size(); ++i){
        char c = s[i];
        if(isalpha(c)){
            vc.push_back(c);
            // if(isupper(c)){
            //     pair<char, char> p = {c+gap, c};
            //     vc.push_back(p);
            // }else{
            //     pair<char, char> p = {c, c};
            //     vc.push_back(p);
            // }
        }else{
            um[i] = c;
        }
    }
    pf(vc);
        // 关键：稳定排序 + 忽略大小写
    stable_sort(vc.begin(), vc.end(),
        [](char a, char b) {
            return tolower(a) < tolower(b);
        });
    pf(vc);
    vector<char> str(s.size());
    int j = 0;
    for(int i = 0; i < s.size(); ++i){
        if(um.count(i)){
            str[i] = um[i];
            // continue;
        }else{
            if(j < vc.size()){
                str[i] = vc[j++];
            }
        }
    }
    pf(str);
    string cur = "";
    for(auto c:str){
        cur += c;
    }
    pf(cur);
    cout << cur;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    string line;
    getline(cin, line);
    stringstream ss(line);
    fun(line);

    return 0;
}
