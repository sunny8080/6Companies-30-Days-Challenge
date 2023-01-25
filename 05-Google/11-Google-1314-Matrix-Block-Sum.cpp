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



// Link :- https://leetcode.com/problems/matrix-block-sum/description/


class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> tmp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tmp[i][j] = mat[i][j] + (j >= 1 ? tmp[i][j - 1] : 0);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int x = j - k - 1 >= 0 ? tmp[i][j - k - 1] : 0;
                int y = j + k < m ? tmp[i][j + k] : tmp[i][m - 1];
                mat[i][j] = y - x;
            }

        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i++)
                tmp[i][j] = mat[i][j] + (i >= 1 ? tmp[i - 1][j] : 0);

        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i++) {
                int x = i - k - 1 >= 0 ? tmp[i - k - 1][j] : 0;
                int y = i + k < n ? tmp[i + k][j] : tmp[n - 1][j];
                mat[i][j] = y - x;
            }

        return mat;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



