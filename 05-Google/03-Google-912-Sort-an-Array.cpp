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


// Link :- https://leetcode.com/problems/sort-an-array/description/


class Solution {
    // merge - [l ... mid] and [mid+1 ... r]
    void merge(vector<int>& nums, int l, int mid, int r, vector<int>& tmp) {
        int i = l, j = mid + 1, k = l;
        while (i <= mid && j <= r) {
            tmp[k++] = (nums[i] <= nums[j] ? nums[i++] : nums[j++]);
        }

        while (i <= mid) tmp[k++] = nums[i++];
        while (j <= r) tmp[k++] = nums[j++];

        for (int i = l; i <= r; i++) nums[i] = tmp[i];
    }


    void mergeSort(vector<int>& nums, int l, int r, vector<int>& tmp) {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        mergeSort(nums, l, mid, tmp);
        mergeSort(nums, mid + 1, r, tmp);
        merge(nums, l, mid, r, tmp);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> tmp(nums.size());
        mergeSort(nums, 0, nums.size() - 1, tmp);
        return nums;
    }
};

int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




