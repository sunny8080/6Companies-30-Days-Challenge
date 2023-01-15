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



// Link :- https://leetcode.com/problems/minimum-genetic-mutation/description/


class Solution {
    vector<char> chars = { 'A', 'C', 'G', 'T' };

    void insert(string& root, string& par, unordered_map<string, int>& mpp, unordered_map<string, vector<string>>& adj) {
        for (int i = 0; i < 8; i++) {
            for (auto w : chars) {
                if (root[i] != w) {
                    string tmp = root;
                    tmp[i] = w;
                    if (tmp != par && mpp[tmp]) {
                        adj[root].push_back(tmp);
                        insert(tmp, root, mpp, adj);
                    }
                }
            }
        }
    }


    int findShortestPath(string& src, string& node, unordered_map<string, vector<string>>& adj) {
        queue<string> q;
        unordered_map<string, int> vis;
        q.push(src);
        vis[src] = 1;

        int len = 0;
        while (q.size()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto cur = q.front(); q.pop();
                if (cur == node) return len;
                for (auto nbr : adj[cur]) {
                    if (!vis[nbr])q.push(nbr), vis[nbr] = 1;
                }
            }
            len++;
        }
        return -1;
    }

public:
    int minMutation1(string a, string b, vector<string>& bank) {
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> mpp;
        for (auto& s : bank) {
            mpp[s] = 1;
        }
        mpp[a] = 1;
        if (mpp[b] == 0) return -1;

        string par = "12345678";
        insert(b, par, mpp, adj);

        // for (auto x : adj) {
        //     cout << x.first << " -> ";
        //     for (auto y : x.second) cout << y << " ";
        //     cout << "\n";
        // }

        return findShortestPath(b, a, adj);;
    }



    int minMutation(string start, string end, vector<string>& bank) {
        map<string, int> cnt;
        queue<string> q;

        for (auto& x : bank) cnt[x]++;
        cnt[start]++;

        q.push(start);
        cnt[start]--;

        int len = 0;
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                auto cur = q.front(); q.pop();
                if (cur == end) return len;

                for (int i = 0; i < cur.size(); i++) {
                    for (auto c : "ACGT") {
                        string tmp = cur;
                        tmp[i] = c;
                        if (cnt[tmp]) {
                            q.push(tmp);
                            cnt[tmp] --;
                        }
                    }
                }
            }
            len++;
        }
        return -1;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



