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


// Link :- https://leetcode.com/problems/random-pick-with-weight/description/


class Solution {
    vector<int> preSum;
public:
    Solution(vector<int>& w) {
        preSum.resize(w.size());
        preSum[0] = w[0];
        for (int i = 1; i < w.size(); i++) preSum[i] = preSum[i - 1] + w[i];
    }

    int pickIndex() {
        int randWt = rand() % preSum.back();
        return upper_bound(preSum.begin(), preSum.end(), randWt) - preSum.begin();
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



