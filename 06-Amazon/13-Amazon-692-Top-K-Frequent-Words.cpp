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



// Link :- https://leetcode.com/problems/top-k-frequent-words/


class Solution {
public:
    vector<string> topKFrequent1(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for (auto& w : words) mpp[w]++;
        vector<pair<int, string>> arr;
        for (auto& x : mpp) arr.push_back({ x.second, x.first });

        auto cmp = [&](pair<int, string>& a, pair<int, string>& b) {
            return (a.first == b.first) ? a.second < b.second : a.first > b.first;
        };

        sort(arr.begin(), arr.end(), cmp);

        vector<string> ans;
        for (int i = 0; i < k; i++) ans.push_back(arr[i].second);
        return ans;
    }





    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for (auto& w : words) mpp[w]++;

        auto cmp = [&](pair<int, string>& a, pair<int, string>& b) {
            return (a.first == b.first) ? a.second < b.second : a.first > b.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp) > pq(cmp);

        for (auto& x : mpp) {
            pq.push({ x.second, x.first });
            if (pq.size() > k) pq.pop();
        }

        vector<string> ans(k--);
        while (pq.size()) ans[k--] = pq.top().second, pq.pop();
        return ans;
    }


};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



