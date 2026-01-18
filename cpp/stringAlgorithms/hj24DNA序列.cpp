#include <bits/stdc++.h>
using namespace std;

int len;
void fun(string& s){ //独立
    
    int start = 0; //Ratio 最高的子串的起始位置
    int maxCount = 0; //子串 最多能包含的C、G个数
    bool hasC = false, hasG = false; //子串是否包含C和G 
    for(int left = 0; left + len <= s.size(); ++left){
        int curCount = 0; //当前子串中C 和 G的数量
        for(int i = left, j = 0; i < s.size()&&j < len; ++i, ++j){
            if(s[i] == 'C'){
                curCount++; hasC = true;
            }
            if(s[i] == 'G'){
                curCount++; hasG = true;
            }
        }
        if(hasC && hasG){ //子串需要都包含C G才能入选
            if(curCount > maxCount){
                maxCount = curCount;
                start = left;
            }
        }
    }
    string sub = s.substr(start, len);
    cout << sub;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    getline(cin, line);
    cin >> len;
    fun(line);
    return 0;
}
