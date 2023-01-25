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




// Link :- https://leetcode.com/problems/swim-in-rising-water/description/



class Solution {

    // check by bfs
    bool isReachable1(int upperLimit, vector<vector<int>>& grid) {
        int n = grid.size();
        vector< vector<int>> vis(n, vector<int>(n, 0));
        vector< vector<int>> ways = { {0,1},{0,-1}, {1,0}, {-1,0} };
        queue<pair<int, int>> q;

        q.push({ 0, 0 });
        vis[0][0] = 1;

        auto isValid = [&vis, &grid, &upperLimit, &n](int i, int j) {
            return (i >= 0 && j >= 0 && i < n && j < n && !vis[i][j] && grid[i][j] <= upperLimit);
        };

        while (q.size()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if (i == n - 1 && j == n - 1) return 1;
            for (auto& w : ways) {
                int x = i + w[0], y = j + w[1];
                if (isValid(x, y)) q.push({ x,y }), vis[x][y] = 1;
            }
        }
        return 0;
    }




    bool dfsCheck(int i, int j, int upperLimit, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        if (i == grid.size() - 1 && j == grid.size() - 1 && grid[i][j] <= upperLimit) return 1;
        if (i < 0 || j < 0 || i >= grid.size() || j == grid.size() || vis[i][j] || grid[i][j]>upperLimit) return 0;
        vis[i][j] = 1;
        vector< vector<int>> ways = { {0,1},{0,-1}, {1,0}, {-1,0} };
        for (auto& w : ways) {
            int x = i + w[0], y = j + w[1];
            if (dfsCheck(x, y, upperLimit, vis, grid)) return 1;
        }
        return 0;
    }


    // check by dfs
    bool isReachable2(int upperLimit, vector<vector<int>>& grid) {
        int n = grid.size();
        vector< vector<int>> vis(n, vector<int>(n, 0));
        return dfsCheck(0, 0, upperLimit, vis, grid);
    }



public:
    // binary search // O(N^2*LogN)
    int swimInWater1(vector<vector<int>>& grid) {
        int n = grid.size(), l = grid[0][0], r = n * n - 1, ans;
        while (l <= r) {
            int mid = (l + r) >> 1;
            // if (isReachable1(mid, grid)) ans = mid, r = mid - 1; // bfs
            if (isReachable2(mid, grid)) ans = mid, r = mid - 1; // dfs
            else l = mid + 1;
        }
        cout << l << " " << r << " ";
        return ans;
    }






    // by priority queue, Dijkstras Algo // O(N^2 logN)
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), maxi = max(grid[0][0], grid[n - 1][n - 1]);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector< vector<int>> vis(n, vector<int>(n, 0));
        vector< vector<int>> ways = { {0,1},{0,-1}, {1,0}, {-1,0} };

        pq.push({ maxi, 0, 0 });
        vis[0][0] = 1;

        // using priority queue, move where no of grid cell value is minimum
        while (pq.size()) {
            int cur = pq.top()[0], i = pq.top()[1], j = pq.top()[2];
            pq.pop();
            maxi = max(maxi, cur);
            if (i == n - 1 && j == n - 1) return maxi;

            for (auto& w : ways) {
                int x = i + w[0], y = j + w[1];
                if (x >= 0 && y >= 0 && x < n && y < n && !vis[x][y]) {
                    pq.push({ grid[x][y], x,y });
                    vis[x][y] = 1;
                }
            }
        }
        return -1;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



