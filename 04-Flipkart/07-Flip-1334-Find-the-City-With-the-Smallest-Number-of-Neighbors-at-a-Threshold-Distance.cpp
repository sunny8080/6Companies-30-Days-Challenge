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



// Link :- https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/


class Solution {
    int findNoOfNodesReachable(int src, int n, vector< vector<pair<int, int>>>& adj, int thres) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, 1e9);

        pq.push({ 0, src });
        dist[src] = 0;

        while (pq.size()) {
            int nodeWt = pq.top().first, node = pq.top().second;
            pq.pop();

            for (auto nbrIt : adj[node]) {
                int wt = nodeWt + nbrIt.second, nbr = nbrIt.first;
                if (dist[nbr] > wt) {
                    dist[nbr] = wt;
                    pq.push({ wt, nbr });
                }
            }
        }

        return accumulate(dist.begin(), dist.end(), 0, [&](int s, int t) {
            return s + (t <= thres);
            });
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thres) {
        vector< vector<pair<int, int>>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back({ e[1], e[2] }), adj[e[1]].push_back({ e[0], e[2] });

        int mini = INT_MAX, ans = 0;
        for (int i = 0; i < n; i++) {
            int t = findNoOfNodesReachable(i, n, adj, thres);
            if (t <= mini) mini = t, ans = i;
        }
        return ans;
    }
};

int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



