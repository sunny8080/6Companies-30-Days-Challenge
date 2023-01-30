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



// Link :- https://leetcode.com/problems/maximum-sum-of-an-hourglass/description/


class Solution {
public:
    int maxSum(vector<vector<int>>& g) {
        vector<vector<int>> cell = { {0,0}, {0,1 }, {0,2 }, {1,1 }, { 2,0}, {2,1 }, {2,2 } };
        int maxi = INT_MIN;

        for (int i = 0; i <= g.size() - 3; i++) {
            for (int j = 0, sum = 0; j <= g[0].size() - 3; j++, sum = 0) {
                for (auto w : cell) sum += g[i + w[0]][j + w[1]];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};




int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



