#include <bits/stdc++.h>

using namespace std;

void fun(vector<int>& nums){
    vector<int> next(nums.size(), -1);
    int n = nums.size();
    stack<int> st; 
    for(int right = 0; right < 2*n; ++right){
        int pos = right%n;
        while(!st.empty() && nums[pos] > nums[st.top()]){
            int left = st.top();
            st.pop();
            next[left] = nums[pos];
        }
        if(right < n){
            st.push(right);
        }
    }
    for(auto n:next){
        cout << n << " ";
    }
}

int main()
{
    int n; cin >> n;
    vector<int> nums;
    while(n--){
        int num; cin >> num;
        nums.push_back(num);
    }
    fun(nums);
    return 0;
}

