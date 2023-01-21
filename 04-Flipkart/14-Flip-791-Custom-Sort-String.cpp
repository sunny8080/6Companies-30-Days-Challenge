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


// Link :- https://leetcode.com/problems/custom-sort-string/description/


class Solution {
public:
    string customSortString1(string order, string s) {
        unordered_map<char, int> mpp;
        for (auto ch : s) mpp[ch]++;
        string ans;
        for (auto ch : order) {
            int cnt = mpp[ch];
            while (cnt--) ans += ch;
            mpp.erase(ch);
        }
        for (auto x : mpp) {
            char ch = x.first;
            int cnt = x.second;
            while (cnt--) ans += ch;
        }
        return ans;
    }

    string customSortString(string order, string s) {
        sort(s.begin(), s.end(),
            [&](char a, char b) {  return order.find(a) < order.find(b);});
        return s;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



