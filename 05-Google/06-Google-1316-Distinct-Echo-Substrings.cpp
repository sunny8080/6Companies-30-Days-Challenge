#include<bits/stdc++.h>
using namespace std;

#define ll                 long long
// #define int                long long
// #define mod                1000000007
#define inf                1e18
const ll N = 1e5 + 5;
void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}


// Link :- https://leetcode.com/problems/distinct-echo-substrings/description/ 



#define ll                 long long

class Solution {
public:
    // Giving TLE // brute
    ll distinctEchoSubstrings1(string& s) {
        ll n = s.size(), p = 31, pwr = 1, hash = 0, mod = 1e9 + 7;
        set<ll> st;
        map<ll, vector<int>> mpp; // {hash, {ending_ind, ..}}

        pwr = 1;
        for (int l = 1; l <= n; l++) {
            hash = 0;
            mpp.clear();
            pwr = (pwr * p) % mod;

            for (int i = 0; i < n; i++) {
                hash = (hash * 1ll * p + (s[i] - 'a' + 1)) % mod;
                if (i >= l) hash = (hash - pwr * 1ll * (s[i - l] - 'a' + 1) + mod) % mod;
                hash += (hash < 0 ? mod : 0);

                if (i >= l && mpp.count(hash) && binary_search(mpp[hash].begin(), mpp[hash].end(), i - l)) {
                    if (st.find(hash) == st.end()) st.insert(hash);
                }
                if (i >= l - 1) mpp[hash].push_back(i);
            }
        }
        return st.size();
    }




    // brute force // accepted
    int distinctEchoSubstrings2(string& s) {
        unordered_set<string> st;
        for (int i = 0; i < s.size(); i++) {
            // assume ith index as start of string, so first substring s[i...i+len-1] and second is s[i+len...i+len+len-1]
            for (int len = 1; i + 2 * len <= s.size(); len++) {
                // compare both by compare()
                if (s.compare(i, len, s, i + len, len) == 0) st.insert(s.substr(i, len));
            }
        }
        return st.size();
    }




    // by hashing // accepted
    int distinctEchoSubstrings(string s) {
        ll n = s.size(), prm = 31, mod = 1000000007;
        // h[i] : store hash of s[0....i] // p[i] store prem^i
        vector<ll> h(n, 0), p(n, 0);

        // preprocessing : calculate hash array and prime power
        h[0] = s[0] % mod;
        p[0] = 1;
        for (int i = 1; i < n; i++) {
            h[i] = (h[i - 1] * prm + s[i]) % mod;
            p[i] = (p[i - 1] * prm) % mod;
        }


        // cal hash of s[i...j]  // inclusive
        auto calHash = [&](int i, int j) {
            auto res = (h[j] - (i >= 1 ? h[i - 1] * p[j - i + 1] : 0)) % mod;
            return (res + mod) % mod;
        };


        // store hashes instead of string to reduce the time
        unordered_set<ll> st;
        for (int i = 0; i < n; i++) {
            // assume ith index as start of string, so first substring s[i...i+len-1] and second is s[i+len...i+len+len-1]
            for (int len = 1; i + 2 * len <= n; len++) {
                // compare both by hashing
                if (calHash(i, i + len - 1) == calHash(i + len, i + 2 * len - 1))
                    st.insert(calHash(i, i + len - 1));
            }
        }
        return st.size();
    }

};



int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




