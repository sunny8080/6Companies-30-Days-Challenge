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


// Link :- https://leetcode.com/problems/knight-probability-in-chessboard/description/



class Solution {
    bool isValid(int i, int j, int n) {
        return (i >= 0 && j >= 0 && i < n&& j < n);
    }

public:
    double knightProbability(int n, int k, int row, int col) {
        vector< vector<double>> prev(n, vector<double>(n, 0.0));
        vector<vector<int>> ways = { {-1, -2}, { 1, -2}, { -1, 2},{ 1, 2},{ -2, -1},{ -2, 1},{2 ,-1 },{2 , 1} };
        prev[row][col] = 1.0;

        for (int moves = 1; moves <= k; moves++) {
            vector< vector<double>> cur(n, vector<double>(n, 0.0));

            // traverse prev chess grid
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (prev[i][j] != 0) {
                        for (auto w : ways) {
                            int x = i + w[0], y = j + w[1];
                            if (isValid(x, y, n)) cur[x][y] += prev[i][j] / 8.0;
                        }
                    }
                }
            }
            prev = cur;
        }

        double prob = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                prob += prev[i][j];
            }
        }
        return prob;
    }
};




int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



