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


// Link :- https://leetcode.com/problems/factorial-trailing-zeroes/description/



class Solution {
public:
    int trailingZeroes(int n) {
        int cnt5 = 0, pwr5 = 5;
        while (n >= pwr5) cnt5 += n / pwr5, pwr5 *= 5;
        return cnt5;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



