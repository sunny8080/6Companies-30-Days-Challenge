#include<bits/stdc++.h>
using namespace std;

#define ll                 long long
// #define int                long long
// #define mod                1000000007
#define inf                1e18
const ll N = 1e5 + 5;
void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}



// Link :- https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/



class Solution {
public:
    int peopleAwareOfSecret1(int n, int delay, int forget) {
        vector<long> dp(n + 1, 0); // dp[i] = no of people who found the secret on the ith day
        dp[1] = 1;
        long share = 0, cnt = 0, mod = 1e9 + 7;
        for (int i = 2; i <= n; i++) {
            // share is no of people who will share the secret => dp[i] = share
            // share = share + (no of people who's delay time ended so they start sharing) - (no of people who forget the secret, they can't share )
            share = (share + dp[max(0, i - delay)] - dp[max(0, i - forget)] + mod) % mod;
            dp[i] = share;
        }

        for (int i = n - forget + 1; i <= n; i++) cnt = (cnt + dp[i]) % mod;
        return cnt;
    }


    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> dp(forget, 0);
        dp[0] = 1;
        int share = 0, mod = 1e9 + 7;
        for (int i = 1; i < n; i++) {
            share = (share + dp[(i - delay + forget) % forget] - dp[i % forget] + mod) % mod;
            dp[i % forget] = share;
        }
        return accumulate(dp.begin(), dp.end(), 0L) % mod;
    }


    int peopleAwareOfSecret3(int n, int delay, int forget) {
        long share = 0, mod = 1e9 + 7;
        deque<int> d{ 1 }, f{ 1 }; // d=> no of people who are ready to share // f=> no of people who are going to forget secret
        // share is no of people who will share the secret => dp[i] = share
        // share = share + (no of people who's delay time ended so they start sharing) - (no of people who forget the secret, they can't share )

        while (--n > 0) {
            if (d.size() >= delay) share = (share + d.front()) % mod, d.pop_front();
            if (f.size() >= forget) share = (share - f.front() + mod) % mod, f.pop_front();
            d.push_back(share);
            f.push_back(share);
        }
        return accumulate(f.begin(), f.end(), 0L) % mod;
    }

};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



