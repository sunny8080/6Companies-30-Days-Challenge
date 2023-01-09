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


// Link :  https://leetcode.com/problems/max-points-on-a-line/description/


class Solution {
    double findSlope(vector<int>& a, vector<int >& b) {
        if (a[0] == b[0]) return INT_MAX;
        return (b[1] - a[1]) / ((b[0] - a[0]) * 1.0);
    }
public:
    int maxPoints(vector<vector<int>>& pts) {
        int n = pts.size(), maxi = 0;
        if (n == 1) return 1;
        for (int i = 0; i < n; i++) {
            map<double, int> mpp;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                // mpp[findSlope(pts[i], pts[j])]++;
                mpp[atan2(pts[j][1] - pts[i][1], pts[j][0] - pts[i][0])]++;
            }
            for (auto x : mpp) maxi = max(maxi, x.second + 1);
        }
        return maxi;
    }
};




int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




