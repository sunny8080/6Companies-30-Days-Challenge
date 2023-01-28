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


// Link :- https://leetcode.com/problems/cheapest-flights-within-k-stops/description/




typedef tuple<int, int, int> tii;

class Solution {
public:
    // Dijkstras's Algo
    int findCheapestPrice1(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector< vector<pair<int, int> >>  adj(n);
        for (auto& e : flights) adj[e[0]].push_back({ e[1], e[2] });

        priority_queue<tii, vector<tii>, greater<tii>> pq; // {wt, node, level }
        vector<int> stops(n, 1e9); // minimum no of nodes needed to reach ith node from src

        pq.push({ 0, src, 0 });
        stops[src] = 0;

        while (pq.size()) {
            auto [nodeWt, node, level] = pq.top();
            pq.pop();
            if (level > stops[node] || level > k + 1) continue;
            if (node == dst) return nodeWt;
            stops[node] = level;

            for (auto nbrIt : adj[node]) {
                auto [nbr, nbrWt] = nbrIt;
                pq.push({ nodeWt + nbrWt, nbr, level + 1 });
            }
        }
        return -1;
    }



    // BFS
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector< vector<pair<int, int> >>  adj(n);
        for (auto& e : flights) adj[e[0]].push_back({ e[1], e[2] });
        queue<vector<int>> q; // {stops, node, wt}
        vector<int> dist(n, 1e9);

        q.push({ 0, src, 0 });
        dist[src] = 0;

        while (q.size()) {
            auto it = q.front();
            q.pop();
            int stops = it[0], node = it[1], nodeWt = it[2];
            if (stops > k) continue;

            for (auto nbrIt : adj[node]) {
                int nbr = nbrIt.first, nbrWt = nbrIt.second;
                if (nodeWt + nbrWt < dist[nbr] && stops <= k) {
                    dist[nbr] = nodeWt + nbrWt;
                    q.push({ stops + 1, nbr, dist[nbr] });
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }

};

int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




