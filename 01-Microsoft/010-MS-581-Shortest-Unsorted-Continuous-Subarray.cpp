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




// Link : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/


class Solution {
public:
    // O(NlogN)
    int findUnsortedSubarray1(vector<int>& nums) {
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        int n = nums.size(), s = -1, e = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != tmp[i]) {
                if (s == -1) s = i;
                e = i;
            }
        }
        return (s == -1) ? 0 : (e - s + 1);
    }



    // O(N)
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), mini = INT_MAX, maxi = INT_MIN, flag;

        flag = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) flag = 1;
            if (flag) mini = min(mini, nums[i]);
        }

        flag = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) flag = 1;
            if (flag) maxi = max(maxi, nums[i]);
        }

        int l = 0, r = 0;
        for (l = 0; l < n; l++) if (mini < nums[l]) break;
        for (r = n - 1; r >= 0; r--) if (maxi > nums[r]) break;
        // cout<<l<<" "<<r<<" ";
        // cout<<mini<<" "<<maxi<<" ";

        return r - l < 0 ? 0 : r - l + 1;
    }


    // O(N)
    int findUnsortedSubarray3(vector<int>& nums) {
        int n = nums.size(), prev = nums[0], s = INT_MAX, e = INT_MIN;
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            while (stk.size() && nums[stk.top()] > nums[i]) {
                s = min(s, stk.top());
                stk.pop();
            }
            stk.push(i);
        }

        stack<int> stk2;
        for (int i = n - 1; i >= 0; i--) {
            while (stk2.size() && nums[stk2.top()] < nums[i]) {
                e = max(e, stk2.top());
                stk2.pop();
            }
            stk2.push(i);
        }
        return s == INT_MAX ? 0 : e - s + 1;
    }


};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



