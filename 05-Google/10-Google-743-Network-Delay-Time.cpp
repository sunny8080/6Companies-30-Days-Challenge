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



// Link :- https://leetcode.com/problems/network-delay-time/description/


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int> >> adj(n);
        for (auto& e : times) adj[e[0] - 1].push_back({ e[1] - 1, e[2] });

        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>> pq;
        pq.push({ 0, k - 1 });
        dist[k - 1] = 0;

        while (pq.size()) {
            auto wt = pq.top().first, node = pq.top().second; pq.pop();
            for (auto nbrIt : adj[node]) {
                auto nbr = nbrIt.first, nbrWt = nbrIt.second;
                if (nbrWt + wt < dist[nbr]) {
                    dist[nbr] = nbrWt + wt;
                    pq.push({ dist[nbr],nbr });
                }
            }
        }
        int maxi = *max_element(dist.begin(), dist.end());
        return maxi == 1e9 ? -1 : maxi;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



