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


// Link :- https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/


class Solution {
    bool dfs(int curSum, int st, vector<int>& vis, vector<int>& nums, int target, int round) {
        if (round == 1) return 1;
        if (curSum == target && dfs(0, nums.size() - 1, vis, nums, target, round - 1)) return 1;

        for (int i = st; i >= 0; i--) {
            if (!vis[i] && curSum + nums[i] <= target) {
                vis[i] = 1;
                if (dfs(curSum + nums[i], i - 1, vis, nums, target, round)) return 1;
                vis[i] = 0;
            }
        }
        return 0;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n || k == 1) return k == 1;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return 0;

        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) vis[i] = 0;
        sort(nums.begin(), nums.end()); // helps to minimize the time 

        vis[n - 1] = 1; // necessary to avoid TLE
        int curSum = nums[n - 1];
        return dfs(curSum, n - 2, vis, nums, sum / k, k);
    }
};


int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




