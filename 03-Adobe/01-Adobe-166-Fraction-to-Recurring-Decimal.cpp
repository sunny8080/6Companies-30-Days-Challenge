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



// Link:- https://leetcode.com/problems/fraction-to-recurring-decimal/description/

class Solution {
public:
    string fractionToDecimal(int ni, int di) {
        string ans, frac;
        // if ((ni < 0 || di < 0) && (ni > 0 || di > 0)) ans += "-";
        if (ni != 0 && (ni > 0 ^ di > 0)) ans += "-";

        long n = labs(ni);
        long d = labs(di);
        ans += to_string(n / d);
        n %= d;
        if (n == 0) return ans;

        unordered_map<int, int> mpp;

        for (int i = 1;i <= (int)1e4 && n; i++) {
            if (mpp[n]) {
                frac.insert(mpp[n] - 1, "(");
                frac += ")";
                break;
            }
            mpp[n] = i;
            n *= 10;
            frac += to_string(n / d);
            n %= d;
        }

        return ans + "." + frac;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




