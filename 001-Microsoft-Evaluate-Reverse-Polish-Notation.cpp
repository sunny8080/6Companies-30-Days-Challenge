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



// LeetCode :- https://leetcode.com/problems/evaluate-reverse-polish-notation/description/


class Solution {
    bool isOp(string s) {
        map<string, int> mpp = { { "+", 1 }, { "-", 2 }, { "*", 3 }, { "/", 4 } };
        return mpp[s];
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto& x : tokens) {
            int op = isOp(x);
            if (op != 0) {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                int ans;
                if (op == 1) ans = a + b;
                else if (op == 2) ans = a - b;
                else if (op == 3) ans = a * b;
                else  ans = a / b;
                stk.push(ans);
            } else {
                stk.push(stoi(x));
            }
        }
        return stk.top();
    }
};




int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



