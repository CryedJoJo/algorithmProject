#include <bits/stdc++.h>

using namespace std;

vector<int> nextHigh;

void fun(vector<int>& tmp){
    stack<int> st;
    nextHigh.resize(tmp.size(), 0);
    
    for(int right = 0; right < tmp.size(); ++right){
        while(!st.empty() && tmp[right] > tmp[st.top()]){
            int left = st.top();
            st.pop();
            int gap = right - left;
            nextHigh[left] = gap;
        }
        st.push(right);
    }
    for(auto next:nextHigh){
        cout << next << " ";
    }
}

int main()
{
    int n;
    vector<int> tmp;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        tmp.push_back(num);
    }
    fun(tmp);

    return 0;
}

