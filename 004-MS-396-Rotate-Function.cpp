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



// Link : https://leetcode.com/problems/rotate-function/description/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int sum = 0, prd = 0;
        for (int i = 0; i < n; i++) sum += nums[i], prd += i * nums[i];

        dp[0] = prd;
        int maxi = dp[0];
        for (int i = 1; i < n; i++) dp[i] = dp[i - 1] + sum - n * nums[n - i], maxi = max(dp[i], maxi);
        return maxi;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



