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


// Link :- https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/submissions/888081790/


class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // auto x = min_element(right.begin(), right.end());;
        // int rightMax = (x == right.end()) ? 0 : n - *x;
        // auto y = max_element(left.begin(), left.end());;
        // int leftMax = (y == left.end()) ? 0 : *y;
        // return max(rightMax, leftMax);

        return max(right.empty() ? 0 : n - *min_element(right.begin(), right.end()),
            left.empty() ? 0 : *max_element(left.begin(), left.end()));
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



