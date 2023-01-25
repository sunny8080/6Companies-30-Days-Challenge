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


// Link :- https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/

class Solution {
    int solve(int l, int r, vector<int>& piles) {
        if (l >= r) return 0;
        return piles[l + 1] + solve(l + 2, r - 1, piles);
    }
public:
    int maxCoins(vector<int>& piles, int ans = 0) {

        // sort(piles.rbegin(), piles.rend());
        // // return solve(0, piles.size(), piles);
        // int r = piles.size() - 1;
        // for (int i = 1; i < r; i += 2, r--) ans += piles[i];

        sort(piles.begin(), piles.end());
        for (int i = piles.size() / 3; i < piles.size(); i += 2) ans += piles[i];
        return ans;
    }
};




int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



