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


// Link :- https://leetcode.com/problems/course-schedule/



class Solution {
    bool cycleFound(int node, vector<int>& vis, vector<int>& stk, vector<vector<int>>& adj) {
        vis[node] = 1;
        stk[node] = 1;

        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {
                if (cycleFound(nbr, vis, stk, adj)) return true;
            } else if (stk[nbr]) {
                return true;
            }
        }
        stk[node] = 0;
        return false;
    }

public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < pre.size(); i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        vector<int> vis(n, 0);
        vector<int> stk(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (cycleFound(i, vis, stk, adj)) return false;
            }
        }

        return true;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




