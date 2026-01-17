#include <bits/stdc++.h>

using namespace std;

int calcuLine(vector<int>& nums){
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
    return maxArea;
}

void fun(vector<vector<int>>& matrix){
    int maxArea = calcuLine(matrix[0]);
    for(int i = 1; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[i].size(); ++j){
            if(matrix[i-1][j] != 0){
                matrix[i][j] += matrix[i-1][j];
            }
        }
        maxArea = max(maxArea, calcuLine(matrix[i]));
    }
    cout << maxArea;
}

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    fun(matrix);
    return 0;
}

