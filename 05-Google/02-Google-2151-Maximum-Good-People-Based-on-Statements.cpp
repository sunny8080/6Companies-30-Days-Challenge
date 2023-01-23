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


// Link :- https://leetcode.com/problems/maximum-good-people-based-on-statements/description/


class Solution {
    bool valid(vector<vector<int>>& stm, vector<int>& assume) {
        int n = stm.size();
        for (int i = 0; i < n; i++) {
            // ith person is bad person, so ignore it
            if (assume[i] == 0) continue;

            // if ith person is good => it's all stmt will be true
            for (int j = 0; j < n; j++) {
                if (stm[i][j] != 2 && stm[i][j] != assume[j]) return 0;
            }
        }
        return 1;
    }


public:
    // O(2^n * n^2)
    int maximumGood1(vector<vector<int>>& stm) {
        int n = stm.size(), maxi = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            // assume all 1 in mask [1...0.0.11] are good person
            // if ith digit in binary of mask is 1 => assume ith person is good
            vector<int> assume(n, 0);
            int currentGoodPerson = 0; // total no of 1 in mask

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) assume[i] = 1;
                currentGoodPerson += assume[i];
            }

            if (valid(stm, assume)) maxi = max(maxi, currentGoodPerson);
        }
        return maxi;
    }



    // same as previous // TC - O(2^N * n^2) // SC - O(1)
    int maximumGood(vector<vector<int>>& stm) {
        int n = stm.size(), maxi = 0, total = (1 << n) - 1;

        auto isValid = [&](int good) {
            for (int i = 0; i < n; i++) {
                if (good & (1 << i))
                    for (int j = 0; j < n; j++)
                        if (stm[i][j] != 2 && stm[i][j] != (good & (1 << j) ? 1 : 0))
                            return 0;
            }
            return 1;
        };

        for (int mask = 1; mask <= total; mask++) {
            int curGoodCnt = __builtin_popcount(mask);// __builtin_popcountll()
            if (curGoodCnt > maxi && isValid(mask)) maxi = curGoodCnt;
        }
        return maxi;
    }
};

int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




