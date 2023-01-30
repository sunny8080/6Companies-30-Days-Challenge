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


// Link :- https://leetcode.com/problems/number-of-matching-subsequences/description/



class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& ws) {
        vector<pair<int, int>> waiting[128]; // {words[i], words[i][ind]}
        for (int i = 0; i < ws.size(); i++) {
            waiting[ws[i][0]].push_back({ i, 1 });
        }

        for (auto c : s) {
            auto tmp = waiting[c];
            waiting[c].clear();
            // move to next index of string who is waiting for char c
            for (auto it : tmp) {
                waiting[ws[it.first][it.second++]].push_back(it);
            }
        }

        // return no of string which is waiting for null char 
        return waiting[0].size();
    }



    int numMatchingSubseq1(string s, vector<string>& ws) {
        vector<pair<string, int>> waiting[128]; // {string, next_ind}
        for (auto& w : ws) {
            waiting[w[0]].push_back({ w, 1 });
        }

        for (auto c : s) {
            auto tmp = waiting[c];
            waiting[c].clear();
            // move to next index of string who is waiting for char c
            for (auto it : tmp) {
                waiting[it.first[it.second++]].push_back(it);
            }
        }

        // return no of string which is waiting for null char 
        return waiting[0].size();
    }
};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



