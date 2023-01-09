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


// Link: https://leetcode.com/problems/largest-divisible-subset/description/


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int maxi = 1, lastInd = 0;

        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && dp[i] < dp[prev] + 1) {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastInd = i;
            }
        }

        // track back
        vector<int> ans;
        ans.push_back(nums[lastInd]);
        while (hash[lastInd] != lastInd) {
            lastInd = hash[lastInd];
            ans.push_back(nums[lastInd]);
        }
        // reverse(ans.begin(), ans.end()); // no need in this case
        return ans;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




