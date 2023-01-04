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



// Link :- https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/description/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = numsDivide[0];
        for (auto x : numsDivide) g = __gcd(g, x);
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (g % nums[i] == 0) return i;
        }
        return -1;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



