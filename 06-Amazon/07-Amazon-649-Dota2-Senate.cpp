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


// Link :- https://leetcode.com/problems/dota2-senate/description/


class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> dq, rq;
        int t = 0;
        for (int i = 0; i < s.size(); i++) {
            s[i] == 'D' ? dq.push(t++) : rq.push(t++);
        }

        while (dq.size() && rq.size()) {
            if (dq.front() == min(dq.front(), rq.front())) {  // d chance
                dq.push(t++);
            } else { // r chance
                rq.push(t++);
            }
            rq.pop();
            dq.pop();
        }
        return dq.size() ? "Dire" : "Radiant";
    }
};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



