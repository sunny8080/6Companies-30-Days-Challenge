#include<bits/stdc++.h>
using namespace std;

#define ll                 long long
// #define int                long long
// #define mod                1000000007
#define inf                1e18
const ll N = 1e5 + 5;
void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}


// Link :- https://leetcode.com/problems/maximum-subarray-min-product/description/


class Solution {
public:
    int maxSumMinProduct1(vector<int>& nums) {
        long n = nums.size(), mod = 1e9 + 7, maxi = INT_MIN;
        vector<long> right(n), left(n), pre(n + 1, 0);
        stack<long> stk;

        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() && nums[stk.top()] >= nums[i]) stk.pop();
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        while (stk.size()) stk.pop();


        for (int i = 0; i < n; i++) {
            while (stk.size() && nums[stk.top()] >= nums[i]) stk.pop();
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);

            // do simultaneously prefix sum
            pre[i + 1] = (pre[i] + nums[i]);
        }

        // assume ith index as minimum element
        // take minimum of  (pre[right[i]]  - pre[left[i]+1])*nums[i] 
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, (pre[right[i]] - pre[left[i] + 1]) * nums[i]);
        }
        return maxi % mod;
    }


    int maxSumMinProduct(vector<int>& nums) {
        long n = nums.size(), mod = 1e9 + 7, maxi = INT_MIN;
        vector<long> pre(n + 1, 0);
        stack<long> stk;
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

        for (int i = 0; i <= n; i++) {
            while (stk.size() && (i == n || nums[stk.top()] >= nums[i])) {
                int ind = stk.top();
                stk.pop();
                int r = i, l = stk.empty() ? -1 : stk.top();
                maxi = max(maxi, (pre[r] - pre[l + 1]) * nums[ind]);
            }
            stk.push(i);
        }
        return maxi % mod;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




