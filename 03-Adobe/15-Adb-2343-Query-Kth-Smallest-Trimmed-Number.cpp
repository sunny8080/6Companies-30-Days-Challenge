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


// Link :- https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/


class Solution {
public:
    vector<int> smallestTrimmedNumbers1(vector<string>& nums, vector<vector<int>>& qs) {
        int n = nums[0].size();
        vector<int> ans;

        for (auto q : qs) {
            int k = q[0], ind = n - q[1];
            vector<pair<string, int>> tmp;
            for (int i = 0; i < nums.size(); i++) tmp.push_back({ nums[i].substr(ind), i });
            ans.push_back(tmp[k - 1].second);
        }
        return ans;
    }



    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& qs) {
        vector<int> inds(nums.size()), ans;
        iota(begin(inds), end(inds), 0);

        for (auto& q : qs) {
            int k = q[0] - 1, start = nums[0].size() - q[1], lenToComp = q[1];

            auto cmp = [&](int i, int j) {
                int cmp = nums[i].compare(start, lenToComp, nums[j], start, lenToComp);
                return cmp == 0 ? i < j : cmp < 0;
            };

            // sort(begin(inds), end(inds), cmp);
            nth_element(begin(inds), begin(inds) + k, end(inds), cmp);
            ans.push_back(inds[k]);
        }
        return ans;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




