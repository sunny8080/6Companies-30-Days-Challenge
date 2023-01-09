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



// Link :- https://leetcode.com/problems/ipo/description/


class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& pro, vector<int>& cap) {
        int n = pro.size();
        vector<pair<int, int>> nums(n); // {cap, pro}
        for (int i = 0; i < n; i++) nums[i] = { cap[i], pro[i] };

        // sort according to increasing capital
        sort(nums.begin(), nums.end());

        priority_queue<int> pq; // {pro}
        int ind = 0;

        while (k--) {
            while (ind < n && nums[ind].first <= w) pq.push(nums[ind++].second);
            if (pq.size() == 0) break;
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



