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




// Link :- https://leetcode.com/problems/airplane-seat-assignment-probability/description/


class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        // more - https://www.youtube.com/watch?v=TAD3iC49v-Q
        // in this case n doesn't matter
        // so assume n=2 always
        // if 1st choose his own seat => p(2nd pass) = 0.5
        // if 1st doesn't choose his own seat => p(2nd pass) = 0.5
        return n == 1 ? 1 : 0.5;
    }
};
;



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



