#include <bits/stdc++.h>

using namespace std;

void fun(vector<int>& nums){
    stack<int> st;
    int maxArea = 0;
    int n = nums.size();
    nums.push_back(0);
    for(int right = 0; right < n; ++right){

        //while(!st.empty() && nums[right] < nums[st.top()]){
        //    int left = st.top();
        //    st.pop();
        //    int high = nums[left];
        //    int width = right - left;
        //    maxArea = max(maxArea, width * high);
        //}
        while(!st.empty() && nums[right] < nums[st.top()]){
            int high = nums[st.top()];
            st.pop();
            int left = (st.empty()) ? -1 : st.top();
            int width = right - left - 1; //这儿要怎么想得到
            maxArea = max(maxArea, width * high);                                          
        }    
    
        st.push(right);
    }
    cout << maxArea;
}

int main()
{
    vector<int> nums;
    int n; cin >> n;
    while(n--){
        int num; cin >> num;
        nums.push_back(num);
    }
    fun(nums);
    return 0;
}

