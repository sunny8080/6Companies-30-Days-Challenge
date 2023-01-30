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



// Link :- https://leetcode.com/problems/destroying-asteroids/description/

class Solution {
public:
    bool asteroidsDestroyed1(int m, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = m;
        for (auto x : nums) {
            if (x > sum) return 0;
            sum += x;
        }
        return 1;
    }


    bool asteroidsDestroyed(int m, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return accumulate(nums.begin(), nums.end(), m, [](int sum, int x) {
            return sum < x ? 0 : min(100000, sum + x);
            });
    }
};


int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




