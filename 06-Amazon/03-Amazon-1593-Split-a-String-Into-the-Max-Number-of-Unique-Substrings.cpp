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


// Link :- https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/


class Solution {
    int maxi = INT_MIN;

    void solve(int ind, string& s, unordered_set<string>& st) {
        if (ind == s.size()) {
            maxi = max(maxi, (int)st.size());
            return;
        }

        string tmp;
        for (int i = ind; i < s.size(); i++) {
            tmp += s[i];
            if (st.find(tmp) == st.end()) {
                st.insert(tmp);
                solve(i + 1, s, st);
                st.erase(tmp);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        solve(0, s, st);
        return maxi;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



