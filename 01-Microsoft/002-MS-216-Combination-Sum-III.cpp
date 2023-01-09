#include<bits/stdc++.h>
using namespace std;

#define ll                 long long
// #define int                long long
#define mod                1000000007
#define inf                1e18
const ll N = 1e5 + 5;
void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}



// QUE :- https://leetcode.com/problems/combination-sum-iii/


class Solution {
    void combinationSum3Help(int k, int sum, int start, vector<int>& nums, vector<vector<int>>& ans) {
        if (k == 0 && sum == 0) {
            ans.push_back(nums);
            return;
        } else if (k == 0) return;
        else if (sum < 0) return;

        for (int i = start; i <= 9; i++) {
            if (sum - i >= 0) {
                nums.push_back(i);
                combinationSum3Help(k - 1, sum - i, i + 1, nums, ans);
                nums.pop_back();
            }
        }
    }


public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> nums;
        combinationSum3Help(k, n, 1, nums, ans);
        return ans;
    }
};




int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



