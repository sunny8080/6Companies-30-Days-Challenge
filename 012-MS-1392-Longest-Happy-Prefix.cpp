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



// Link :- https://leetcode.com/problems/longest-happy-prefix/description/


class Solution {
public:
    string longestPrefix(string s) {
        // apply KMP
        int n = s.size();
        if (n <= 1) return "";
        // find longest prefix which is also suffix ending at i
        vector<int> lps(n);
        lps[0] = 0;

        // int i = 1, j = 0;
        // while (i < n) {
        //     if (s[i] == s[j]) {
        //         lps[i] = j + 1;
        //         i++, j++;
        //     } else if (j != 0) {
        //         j = lps[j - 1];
        //     } else {
        //         lps[i++] = 0;
        //     }
        // }


        // KMP shorter code
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && s[i] != s[j]) j = lps[j - 1];
            if (s[i] == s[j]) j++;
            lps[i] = j;
        }

        int maxLenLps = lps[n - 1];
        return s.substr(0, maxLenLps);
    }
};




int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



