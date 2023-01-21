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


// Link :- https://leetcode.com/problems/new-21-game/description/


class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        // res = ( dp[k] + dp[k+1] + ...  + dp[n-1] + dp[n])
        // dp[i] = (1/maxPts)( dp[i-1] + dp[i-2] + ... + dp[i-maxPts] )
        double sum = dp[0], res = 0.0; // sum is sliding window sum 

        for (int i = 1; i <= n; i++) {
            dp[i] = sum / maxPts;
            if (i < k) sum += dp[i]; // add 
            else res += dp[i];
            if (i - maxPts >= 0)  sum -= dp[i - maxPts]; // remove 1st one
        }
        return res;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



