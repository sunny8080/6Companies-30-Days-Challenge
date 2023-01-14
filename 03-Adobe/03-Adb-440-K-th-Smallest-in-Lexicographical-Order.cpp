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



// Link :- https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/


class Solution {
    // return no of nos in [1...n] with the prefix pre
    // range [1...10500] => no which come under this range with prefix=10 are {100, 101, 102, 1087, 10129...}  
    int countPrefix(long prefix, int n) {
        if (prefix >= n) return prefix == n;

        // suppose prefix is 2
        // [2...2] => [20...29] => [200...2999] =>[2000...29999] => ...
        long minPrefix = prefix, maxPrefix = prefix, cnt = 1;
        while (1) {
            minPrefix = minPrefix * 10;
            maxPrefix = maxPrefix * 10 + 9;

            // 3 case => ||   n...[x...y ]   ||    [x...n...y]   ||   [x...y]...n
            if (n < minPrefix) break;
            if (minPrefix <= n && n <= maxPrefix) {
                cnt += (n - minPrefix + 1);
                break;
            }
            cnt += (maxPrefix - minPrefix + 1); // (minPrefix<=n && maxPrefix<=n)  
        }
        return cnt;
    }

    int solve(int n, int k, long prefix) {
        for (int i = (prefix == 0) ? 1 : 0; i <= 9; i++) {
            if (k == 0) return prefix;
            int preCnt = countPrefix(prefix * 10 + i, n);

            if (preCnt >= k) {
                // fix 1 digit
                return solve(n, k - 1, prefix * 10 + i);
            } else {
                // remove no with current digit
                k -= preCnt;
            }
        }
        return prefix;
    }

public:
    int findKthNumber(int n, int k) {
        return solve(n, k, 0);
    }
};


int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




