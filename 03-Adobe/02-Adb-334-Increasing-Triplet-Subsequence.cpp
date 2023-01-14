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


// Link :- https://leetcode.com/problems/increasing-triplet-subsequence/



class Solution {
public:
    bool increasingTriplet1(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp;
        tmp.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (nums[i] > tmp.back()) tmp.push_back(nums[i]);
            else {
                int ind = lower_bound(tmp.begin(), tmp.end(), nums[i]) - tmp.begin();
                tmp[ind] = nums[i];
            }
            if (tmp.size() >= 3) return 1;
        }
        return 0;
    }


    bool increasingTriplet(vector<int>& nums) {
        int n1 = INT_MAX, n2 = INT_MAX;
        for (auto x : nums) {
            if (x <= n1) n1 = x;
            else if (x <= n2) n2 = x;
            else return 1; // triplet found {n1<n2<x} // n1<n2 && n2<x
        }
        return 0;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



