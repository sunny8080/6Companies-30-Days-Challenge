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




// Link :- https://leetcode.com/problems/count-nice-pairs-in-an-array/description/


class Solution {
    int rev(int n) {
        int sum = 0;
        while (n) {
            sum = sum * 10 + n % 10;
            n /= 10;
        }
        return sum;
    }
public:
    int countNicePairs(vector<int>& nums) {
        // nums[i] = nums[i] - rev(nums[i])
        for (auto& x : nums) x -= rev(x);

        // count (i, j) such that, nums[i] == nums[j]
        int n = nums.size(), mod = 1e9 + 7, cnt = 0;
        map<int, int> mpp;

        for (auto x : nums) {
            cnt = (cnt + mpp[x]++) % mod;
        }
        return cnt;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



