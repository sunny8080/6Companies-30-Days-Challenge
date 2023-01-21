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


// Link :- https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/


#define ll                 long long
#define mod                1000000007

class Solution {
public:
    bool hasAllCodes1(string s, int k) {
        ll hash = 0, p = 31, pwr = 1;

        for (int i = 0; i < k; i++) pwr = (pwr * p) % mod;
        unordered_set<ll> st;
        for (int i = 0; i < s.size(); i++) {
            hash = (hash * p + s[i]) % mod;
            if (i <= k - 2) continue;
            if (i >= k) hash = (hash - s[i - k] * pwr + mod) % mod;
            if (hash < 0) hash += mod;
            st.insert(hash);
        }
        return st.size() == (1 << k);
    }


    bool hasAllCodes(string s, int k) {
        ll hash = 0, need = (1 << k), allone = (1 << k) - 1;

        unordered_set<ll> st;
        for (int i = 0; i < s.size(); i++) {
            hash = ((hash << 1) & allone) | (s[i] - '0');
            if (i >= k - 1) st.insert(hash);
        }
        return st.size() == (1 << k);
    }
};


int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




