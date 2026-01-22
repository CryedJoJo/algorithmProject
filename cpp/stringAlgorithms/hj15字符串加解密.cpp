#include <bits/stdc++.h>
#include <cctype>
#include <cstddef>
using namespace std;

void incode(string& s, string& ns){
    for(int i = 0; i < s.size(); ++i){
        char old = s[i];
        if(isupper(old)){
            if(old != 'Z'){
                ns[i] = tolower(old) + 1;
            } else {
                ns[i] = 'a';
            }
        } else if(islower(old)){
            if(old != 'z'){
                ns[i] = toupper(old) + 1;
            } else {
                ns[i] = 'A';
            }
        } else if ('0' <= old && '9' >= old){
            if(old != '9'){
                ns[i] = old + 1;  
            } else {
                ns[i] = '0';
            }
        }
    }
}

void decode(string& t, string& nt){
    for(int i = 0; i < t.size(); ++i){
        char old = t[i];
        if(isupper(old)){
            if(old != 'A'){
                nt[i] = tolower(old) - 1;
            } else {
                nt[i] = 'z';
            }
        } else if(islower(old)){
            if(old != 'a'){
                nt[i] = toupper(old) - 1;
            } else {
                nt[i] = 'Z';
            }
        } else if ('0' <= old && '9' >= old){
            if(old != '0'){
                nt[i] = old - 1;  
            } else {
                nt[i] = '9';
            }
        }
    }
}

int main(){
    string s, t;
    cin >> s >> t;
    string ns = s;
    string nt = t;
    string fisrts = s;
    string secondt = t;
    while(1){
        //sleep(1);
        incode(s, ns);
        decode(t, nt);
        cout << ns << '\n' << nt << '\n';
        s = ns; t = nt;
        if(ns == fisrts || nt == secondt){
            break;
        }
    }
    cout << ns << endl;
    cout << nt;
    return 0;
}
