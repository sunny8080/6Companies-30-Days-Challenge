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



// Link :- https://leetcode.com/problems/number-of-boomerangs/description/


class Solution {
    int dist(vector<int>& a, vector<int>& b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& pt) {
        int cnt = 0;
        for (auto& p1 : pt) {
            unordered_map<int, int> mpp; // assume p as center point i, so dist(j, i) == dist(i, k)
            for (auto& p2 : pt) cnt += mpp[dist(p1, p2)]++;
        }
        // order of tuple matters // if i is center =>  (i, j, k) and (i, k, j)
        return 2 * cnt;
    }
};




int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



