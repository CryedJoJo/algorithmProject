#include <bits/stdc++.h>
using namespace std;

string ip;
bool isValid(string cur){
    if(cur == "") return false;
    if(cur.size() >= 2 && cur[0] == '0') return false;
    int num = stoi(cur);
    if(num > 255) return false;
    return true;
}
void fun(){
    int len = ip.size();
    if (len < 7 || len > 15) {
        cout << "NO";
        return;
    }
    string cur;
    int pointCount = 0;
    for(int i = 0; i < len;){
        if(ip[i] >= '0' && ip[i] <= '9'){
            cur += ip[i];
        } else if (ip[i] == '.'){
            if(isValid(cur)){
                cur = "";
                pointCount++;
                if(pointCount > 3) {
                    cout << "NO";return;
                }
            }else{
                cout << "NO";
                return;
            }
        } else {
            cout << "NO";
            return;
        }
        ++i;
        if(i == len){
            if(isValid(cur)){
                cout << "YES";
            }else{
                cout <<"NO";
            }
        }
    }
}

int main(){
    cin >> ip;
    fun();
    return 0;
}
