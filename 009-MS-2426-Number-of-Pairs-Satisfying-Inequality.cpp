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



// Link :- https://leetcode.com/problems/number-of-pairs-satisfying-inequality/


#define ll   long long
class Solution {
    // merge 2 subarray => [l...mid] [mid+1...r]
    ll merge(vector<int>& nums, int l, int mid, int r, int diff) {
        ll cnt = 0; int i = l, j = mid + 1, k = 0;

        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j] + diff) {
                cnt += (r - j + 1);
                i++;
            } else j++;
        }
        sort(nums.begin() + l, nums.begin() + r + 1);
        return cnt;
    }


    // merge sort 2 subarray => [l...r]
    ll mergeSort(vector<int>& nums, int l, int r, int diff) {
        ll cnt = 0;
        if (l >= r) return cnt;
        int mid = (l + r) / 2;
        cnt += mergeSort(nums, l, mid, diff);
        cnt += mergeSort(nums, mid + 1, r, diff);
        cnt += merge(nums, l, mid, r, diff);
        return cnt;
    }

public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        // nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff   //  i < j reduced to  
        // nums[i] <= nums[j] + diff // i < j
        for (int i = 0; i < nums1.size(); i++) nums1[i] -= nums2[i];
        return mergeSort(nums1, 0, nums1.size() - 1, diff);
    }
};

int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



