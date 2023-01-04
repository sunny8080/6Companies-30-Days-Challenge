#include<bits/stdc++.h>
using namespace std;

// #define int                long long
#define ll                 long long
#define mod                1000000007
#define inf                1e18
const ll N = 1e5 + 5;
void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}




// Link : https://leetcode.com/problems/most-profitable-path-in-a-tree/description/


class Solution {
    vector<vector<int>> buildTree(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }


    void getParent(int cur, int curPar, int curDist, vector<vector<int>>& adj, vector<int>& par, vector<int>& dist) {
        dist[cur] = curDist;
        par[cur] = curPar;

        for (auto nbr : adj[cur]) {
            if (nbr != curPar) getParent(nbr, cur, curDist + 1, adj, par, dist);
        }
    }


    void findMaxSum(int node, vector<int>& vis, int sum, int& maxSum, vector<int>& amt, vector<vector<int>>& adj) {
        vis[node] = 1;
        sum += amt[node];
        int trav = 0;
        for (auto nbr : adj[node]) {
            if (!vis[nbr]) findMaxSum(nbr, vis, sum, maxSum, amt, adj), trav = 1;
        }
        if (!trav) maxSum = max(sum, maxSum);
        sum -= amt[node];
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amt) {
        int n = edges.size() + 1;
        auto adj = buildTree(edges);
        vector<int> par(n, 0), dist(n, 0);
        getParent(0, -1, 0, adj, par, dist);

        // as graph is tree, so there is unique path for bob ro reach root node
        int cur = bob, curDist = 0;
        while (cur != 0) {
            if (dist[cur] > curDist) amt[cur] = 0; // bob will reach firsr
            else if (dist[cur] == curDist) amt[cur] /= 2; // node where bob and meet
            cur = par[cur];
            curDist++;
        }

        // now find the maximum sum that can be obtained by a path from root to leaf node
        vector<int> vis(n, 0);
        int maxSum = INT_MIN;
        findMaxSum(0, vis, 0, maxSum, amt, adj);
        return maxSum;
    }
};








int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




