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


// Link :- https://leetcode.com/problems/split-array-into-consecutive-subsequences/


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, needed;
        for (auto x : nums) freq[x]++;

        for (auto x : nums) {
            // Every no has 2 choices :
            // 1. append this no as end of some needed subsequence
            // 2. create a new subsequence started with this no
            // Conclusion => appending to end should be higher priority than creating a new subsequence 
            if (!freq[x]) continue;
            if (needed[x]) {
                freq[x]--;
                needed[x]--;
                needed[x + 1]++;
            } else if (freq[x + 1] && freq[x + 2]) {
                freq[x]--;
                freq[x + 1]--;
                freq[x + 2]--;
                needed[x + 3]++;
            } else return 0;
        }
        return 1;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




