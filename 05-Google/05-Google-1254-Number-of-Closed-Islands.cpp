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


// Link :-https ://leetcode.com/problems/number-of-closed-islands/description/


class Solution {
    void dfs(int i, int j, vector< vector<int>>& g) {
        if (i < 0 || i >= g.size() || j < 0 || j >= g[0].size() || g[i][j] != 0) return;
        g[i][j] = 1;
        dfs(i, j + 1, g), dfs(i, j - 1, g), dfs(i + 1, j, g), dfs(i - 1, j, g);
    }


public:
    int closedIsland(vector<vector<int>>& g, int cnt = 0) {
        for (int i = 0; i < g.size(); i++)
            for (int j = 0; j < g[0].size(); j++)
                if ((i * j == 0 || i == g.size() - 1 || j == g[0].size() - 1) && (!g[i][j]))
                    dfs(i, j, g);

        for (int i = 0; i < g.size(); i++)
            for (int j = 0; j < g[0].size(); j++)
                if (g[i][j] == 0) dfs(i, j, g), cnt++;
        return cnt;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




