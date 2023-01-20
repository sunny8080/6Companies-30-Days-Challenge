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


// Link :- https://leetcode.com/problems/find-in-mountain-array/description/


class MountainArray {
public:
    int get(int index);
    int length();
};



/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */


class Solution {
public:
    int findInMountainArray(int target, MountainArray& nums) {
        int n = nums.length(), l = 0, r = n - 1, maxi = INT_MIN, mxInd;
        while (l <= r && l < n && r >= 0) {
            int mid = (l + r) >> 1;
            int t = nums.get(mid);
            if (t > maxi) maxi = t, mxInd = mid;
            if (t < nums.get(mid + 1)) l = mid + 1;
            else r = mid - 1;
        }
        // cout << maxi << " "<<mxInd<<" ";

        // apply binary search on [0...mxInd]
        l = 0, r = mxInd;
        while (l <= r) {
            int mid = (l + r) >> 1, t = nums.get(mid);
            if (t == target) return mid;
            else if (t < target) l = mid + 1;
            else r = mid - 1;
        }

        // iff still not foundd, apply binary search on [mxInd... n-1]
        l = mxInd + 1, r = n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1, t = nums.get(mid);
            if (t == target) return mid;
            else if (t < target) r = mid - 1;
            else l = mid + 1;
        }

        return -1;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



