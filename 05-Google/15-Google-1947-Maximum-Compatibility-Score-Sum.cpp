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



// Link :- https://leetcode.com/problems/maximum-compatibility-score-sum/description/


class Solution {
    int n, m, maxi = 0;
    int revXor(vector<int>& a, vector<int>& b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) cnt += a[i] == b[i];
        return cnt;
    }

    void solve(int ind, int pos, int sum, vector<vector<int>>& stud, vector<vector<int>>& ment) {
        if (ind == m) { maxi = max(maxi, sum); return; }

        for (int i = 0; i < m; i++) {
            if ((pos & (1 << i)) == 0) {
                solve(ind + 1, pos | (1 << i), sum + revXor(stud[ind], ment[i]), stud, ment);
            }
        }
    }
public:
    int maxCompatibilitySum1(vector<vector<int>>& stud, vector<vector<int>>& ment) {
        m = stud.size(), n = stud[0].size();
        solve(0, 0, 0, stud, ment);
        return maxi;
    }


    int maxCompatibilitySum(vector<vector<int>>& stud, vector<vector<int>>& ment) {
        int m = stud.size(), res = 0;
        vector<int> inds;
        for (int i = 0; i < m; i++) inds.push_back(i);

        do {
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                cnt += revXor(stud[inds[i]], ment[i]);
            }
            res = max(cnt, res);
        } while (next_permutation(begin(inds), end(inds)));
        return res;
    }
};

int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



