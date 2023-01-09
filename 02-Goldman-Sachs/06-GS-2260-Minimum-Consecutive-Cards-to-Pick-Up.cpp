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


// Link : https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/


class Solution {
public:
    int minimumCardPickup(vector<int>& nums) {
        int mini = INT_MAX;
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            if (mpp[nums[i]] != 0) mini = min(mini, i - mpp[nums[i]] + 2);
            mpp[nums[i]] = i + 1;
        }
        return mini == INT_MAX ? -1 : mini;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




