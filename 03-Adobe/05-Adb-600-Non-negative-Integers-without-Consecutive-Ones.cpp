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



// Link :- https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/



class Solution {
public:
    int findIntegers(int n) {
        // fib[i] = no of binary numbers with i bits such that these numbers don't contain consecutive 1's
        // fib[i] = fib[i-1] + fib[i-2]
        int fib[32];
        fib[0] = 1, fib[1] = 2;
        for (int i = 2; i < 32; i++) fib[i] = fib[i - 1] + fib[i - 2];

        int bit = 31, prev_bit = 0, cnt = 0;
        while (bit >= 0) {
            if (n & (1 << bit)) {
                cnt += fib[bit];
                if (prev_bit) { cnt--; break; }
                prev_bit = 1;
            } else prev_bit = 0;
            bit--;
        }
        return cnt + 1;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



