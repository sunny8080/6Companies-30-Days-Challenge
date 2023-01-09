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




// Link :- https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/



#define mod 1000000007
#define ll long long
#define inf 1e15

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Apply dijkstras algo
        vector<pair<ll, ll>> adj[n];
        for (auto& e : roads) {
            adj[e[0]].push_back({ e[1], e[2] });
            adj[e[1]].push_back({ e[0], e[2] });
        }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        vector<ll> dist(n, inf), ways(n, 0);

        pq.push({ 0, 0 });
        dist[0] = 0;
        ways[0] = 1ll;

        while (pq.size()) {
            ll dis = pq.top().first;
            auto node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int nbr = it.first;
                ll nbrWt = it.second;

                if (dis + nbrWt < dist[nbr]) {
                    // it came first for such a shortest distance
                    dist[nbr] = dis + nbrWt;
                    ways[nbr] = ways[node];
                    pq.push({ dist[nbr], nbr });
                } else if (dis + nbrWt == dist[nbr]) {
                    // other path found with the same weight
                    ways[nbr] = (ways[nbr] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



