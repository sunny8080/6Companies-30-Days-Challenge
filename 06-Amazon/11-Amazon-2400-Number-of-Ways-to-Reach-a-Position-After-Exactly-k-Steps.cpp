#include<bits/stdc++.h>
using namespace std;

// #define ll                 long long
// #define int                long long
// #define mod                1000000007
#define inf                1e18
// const ll N = 1e5 + 5;
void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}



// Link :- https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/


class Solution {
    typedef long long ll;
    int mod = 1e9 + 7;
    ll dp[3005][1005];

    int solve(int cur, int k, int e) {
        if (k == 0) return cur == e;
        if (dp[cur][k] != -1) return dp[cur][k];
        return dp[cur][k] = (solve(cur - 1, k - 1, e) + solve(cur + 1, k - 1, e)) % mod;
    }

public:
    int numberOfWays(int s, int e, int k) {
        memset(dp, -1, sizeof dp);
        return solve(s + k, k, e + k);
    }
};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



