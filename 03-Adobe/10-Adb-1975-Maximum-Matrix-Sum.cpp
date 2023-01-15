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




// Link:- https ://leetcode.com/problems/maximum-matrix-sum/description/


class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        int n = mat.size(), minusCnt = 0, mini = INT_MAX;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mini = min(mini, abs(mat[i][j]));
                if (mat[i][j] < 0) minusCnt++;
                sum += abs(mat[i][j]);
            }
        }
        sum -= (minusCnt % 2 != 0 ? 2 * mini : 0);
        return sum;
    }
};





int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



