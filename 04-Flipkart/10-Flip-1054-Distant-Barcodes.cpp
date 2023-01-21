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



// Link :- https://leetcode.com/problems/distant-barcodes/description/


class Solution {
public:
    // O(NlogN)
    vector<int> rearrangeBarcodes1(vector<int>& bar) {
        unordered_map<int, int> mpp;
        for (auto x : bar) mpp[x]++;
        priority_queue<pair<int, int>> pq; // {cnt, x}
        for (auto x : mpp) pq.push({ x.second, x.first });
        int pos = 0;

        while (pq.size()) {
            auto top = pq.top(); pq.pop();
            while (top.first) {
                if (pos >= bar.size()) pos = 1;
                bar[pos] = top.second;
                top.first--;
                pos += 2;
            }
        }
        return bar;
    }


    // O(N)
    vector<int> rearrangeBarcodes(vector<int>& bar) {
        unordered_map<int, int> mpp;
        int maxFreq = 0, maxN = 0;
        for (auto x : bar) {
            mpp[x]++;
            if (mpp[x] > maxFreq) maxFreq = mpp[x], maxN = x;
        }

        int pos = 0;
        for (pos = 0; pos < 2 * maxFreq; pos += 2) bar[pos] = maxN;
        mpp.erase(maxN);

        for (auto x : mpp) {
            while (x.second) {
                if (pos >= bar.size()) pos = 1;
                bar[pos] = x.first;
                x.second--;
                pos += 2;
            }
        }
        return bar;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



