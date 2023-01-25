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


// Link :- https://leetcode.com/problems/strictly-palindromic-number/description/


class Solution {
public:
    bool isStrictlyPalindromic1(int n) {
        for (int i = 2; i <= n - 2; n++) {
            int t = n;
            string tmp = "";
            while (t) tmp += to_string(t % i), t /= i;
            string tmp2 = tmp;
            reverse(tmp2.begin(), tmp2.end());
            if (tmp != tmp2) return 0;
        }
        return 1;
    }


    bool isStrictlyPalindromic(int n) {
        // becoz there is no such number which is strictly palindromic
        return false;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




