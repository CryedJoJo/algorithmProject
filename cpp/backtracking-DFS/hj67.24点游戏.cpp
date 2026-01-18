#include <bits/stdc++.h>
using namespace std;

vector<int> used(4, 0);
bool fin = false;
vector<int> nums;
void backTracking(int result, int level){
    if(level == 4){
        return;
    }
    if(result == 24){
        fin = true;
        return;
    }

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(used[i] == 0){
                used[i] = 1;
                level++;
                switch(j){
                case 0: 
                    result += nums[i];
                    backTracking(result,level);
                    result -= nums[i];
                    used[i] = 0; break;
                case 1:
                    result -= nums[i];
                    backTracking(result,level);
                    result += nums[i];
                    used[i] = 0;break;
                case 2:
                    result *= nums[i];
                    backTracking(result,level);
                    result /= nums[i];
                    used[i] = 0;break;
                case 3:
                    result /= nums[i];
                    backTracking(result,level);
                    result *= nums[i];
                    used[i] = 0;break;
                }
                level--;
            }
        }
    }

}

void fun(){
    
}

int main() {
    int n = 4;
    while(n--){
        int num; cin >> num;
        nums.push_back(num);
    }
    for(auto n:nums){
        cout << n << " ";
    }
    cout << '\n';
    for(int i = 0; i < 4; ++i){
        used[i] = 1;
        backTracking(nums[i], 1);
        used[i] = 0;
    }
    if(fin){
        cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}
// 64 位输出请用 printf("%lld")
