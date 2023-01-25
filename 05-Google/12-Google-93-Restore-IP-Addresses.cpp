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


// Link :- https://leetcode.com/problems/restore-ip-addresses/


class Solution {
    void solve(int ind, int cnt, string tmp, string& s, vector<string>& ans) {
        if (ind >= s.size() || cnt > 3) return;
        if (cnt == 3) {
            if (s.size() - ind <= 3) {
                string s1 = s.substr(ind);
                if ((s1[0] != '0' || s1 == "0") && stoi(s1) <= 255) {
                    tmp += s1;
                    ans.push_back(tmp);
                }
            }
            return;
        }

        tmp = tmp + s[ind] + ".";
        solve(ind + 1, cnt + 1, tmp, s, ans);
        tmp.pop_back();

        if (ind + 1 < s.size() && s[ind] != '0') {
            tmp = tmp + s[ind + 1] + ".";
            solve(ind + 2, cnt + 1, tmp, s, ans);
            tmp.pop_back();
        }

        if (ind + 2 < s.size() && s[ind] != '0' && stoi(s.substr(ind, 3)) <= 255) {
            tmp = tmp + s[ind + 2] + ".";
            solve(ind + 3, cnt + 1, tmp, s, ans);
            tmp.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        string tmp;
        vector<string> ans;
        solve(0, 0, tmp, s, ans);
        return ans;
    }
};




int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



