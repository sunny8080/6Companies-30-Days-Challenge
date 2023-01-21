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


// Link :- https://leetcode.com/problems/max-area-of-island/


class Solution {
    vector< vector<int>> ways = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };

    void dfs(int i, int j, vector<vector<int>>& g, vector< vector<int>>& vis, int& cnt) {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || vis[i][j] || !g[i][j]) return;
        vis[i][j] = 1;
        cnt++;
        for (auto w : ways) dfs(i + w[0], j + w[1], g, vis, cnt);
    }


    int dfs2(int i, int j, vector<vector<int>>& g, vector< vector<int>>& vis) {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || vis[i][j] || !g[i][j]) return 0;
        vis[i][j] = 1;
        int cnt = 1;
        for (auto w : ways) cnt += dfs2(i + w[0], j + w[1], g, vis);
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& g) {
        vector< vector<int>> vis(g.size(), vector<int>(g[0].size()));
        int maxi = 0;
        for (int i = 0; i < g.size(); i++)
            for (int j = 0, cnt = 0; j < g[0].size(); j++, cnt = 0)
                // if (!vis[i][j] && g[i][j]) dfs(i, j, g, vis, cnt), maxi = max(maxi, cnt);
                if (!vis[i][j] && g[i][j] && maxi < (cnt = dfs2(i, j, g, vis))) maxi = cnt;
        return maxi;
    }
};

int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



