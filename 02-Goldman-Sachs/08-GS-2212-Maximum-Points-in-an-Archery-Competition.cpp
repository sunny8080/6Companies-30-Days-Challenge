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



// Link :- https://leetcode.com/problems/maximum-points-in-an-archery-competition/description/


class Solution {
    int maxi = INT_MIN;
    vector<int> ans;
    void solve(int ind, int k, int score, vector<int>& alice, vector<int>& bob) {
        if (ind < 0 || k == 0) {
            if (maxi < score) {
                maxi = score;
                bob[0] += k;
                ans = bob;
            }
            return;
        }

        // score in this section
        if (alice[ind] < k) {
            bob[ind] = alice[ind] + 1;
            solve(ind - 1, k - alice[ind] - 1, score + ind, alice, bob);
            bob[ind] = 0;
        }
        solve(ind - 1, k, score, alice, bob);
    }


    int solve2(int mask, int k, vector<int>& alice, vector<int>& bob) {
        int n = alice.size(), score = 0;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) && alice[i] < k) {
                bob[i] = alice[i] + 1;
                k -= alice[i] + 1;
                score += i;
            }
        }
        bob[0] += k;
        return score;
    }

public:
    // backtracking - (n * 2^n) // (12 * 2^12)
    vector<int> maximumBobPoints1(int k, vector<int>& alice) {
        int n = alice.size();
        vector<int> bob(n, 0);
        solve(n - 1, k, 0, alice, bob);
        return ans;
    }


    // bit masking - (n * 2^n)
    vector<int> maximumBobPoints(int k, vector<int>& alice) {
        int maxi = INT_MIN, n = alice.size();
        vector<int> ans;
        for (int mask = 0; mask < (1 << 12); mask++) {
            vector<int> bob(n, 0);
            int t = solve2(mask, k, alice, bob);
            if (t > maxi) {
                maxi = t;
                ans = bob;
            }
        }
        return ans;
    }


};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



