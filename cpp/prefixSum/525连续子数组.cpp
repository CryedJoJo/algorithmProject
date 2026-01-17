#include <bits/stdc++.h>

using namespace std;

//unordered_map<int, vector<int>> posMap;
unordered_map<int, int> posMap;

void calcuLen(vector<int>& nums){
    int maxLen = 0;
    int preSum = 0;
    int n = nums.size();
    for(int i = 0; i < n; ++i){
        if(nums[i] == 1){
            preSum++;
        } else {
            preSum--;
        }
        cout << " num:" << nums[i] << " preSum:" << preSum << "\n";

        if(posMap.count(preSum)){
//            for(auto pos:posMap[preSum]){
//                cout << "i:" << i << "  pos:" << pos << "  i-pos:" << i-pos<< "\n";
//                maxLen = max(maxLen, i-pos);
//            }
            maxLen = max(maxLen, i - posMap[preSum]);
        }
        //posMap[preSum].push_back(i);
        else {
            posMap[preSum] = i;
        }
    }
    cout << "maxLen:" << maxLen << '\n';
    cout << "\n";
}


int main()
{
    vector<int> nums = {1, 0, 1, 1, 1, 1, 1, 0, 0, 0};
    calcuLen(nums);
    nums.clear(); nums = {0, 1, 1};
    calcuLen(nums);
    nums.clear(); nums = {1, 0, 0};
    calcuLen(nums);
    nums.clear(); nums = {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1};
    calcuLen(nums);
    return 0;
}

