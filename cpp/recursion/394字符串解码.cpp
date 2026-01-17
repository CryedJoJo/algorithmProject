#include <bits/stdc++.h>

using namespace std;

void decode(string& str){
    stack<int> numSt;
    stack<string> strSt;
    string cur = "";
    int num = 0;
    for(auto c:str){
        if(isdigit(c)){
            num = num * 10 + c - '0';
        } else if (c == '['){
            numSt.push(num);
            strSt.push(cur);
            num = 0;
            cur = "";
        } else if (c == ']'){
            int times = numSt.top();
            numSt.pop();
            string prev = strSt.top(); strSt.pop();
            string calcu;
            while(times--) calcu += cur;
            cur = prev + calcu;
        } else {
            cur += c;
        }
    }
    cout << cur;
    
}

int main()
{
    string str;
    cin >> str;
    decode(str);
    return 0;
}

