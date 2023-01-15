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

// Link :- https://leetcode.com/problems/dungeon-game/description/



class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dun) {
        int r = dun.size(), c = dun[0].size();
        int dp[r][c]; // dp[i][j] = minimum health req to reach (r-1, c-1) from (i, j) 

        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                if (i == r - 1 && j == c - 1) dp[i][j] = min(0, dun[i][j]);
                else if (i == r - 1) dp[i][j] = min(0, dun[i][j] + dp[i][j + 1]);
                else if (j == c - 1) dp[i][j] = min(0, dun[i][j] + dp[i + 1][j]);
                else dp[i][j] = min(0, dun[i][j] + max(dp[i][j + 1], dp[i + 1][j]));
            }
        }
        return abs(dp[0][0]) + 1;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




