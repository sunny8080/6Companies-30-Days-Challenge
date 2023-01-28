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


// Link :- https://leetcode.com/problems/shuffle-an-array/description/


class Solution {
    vector<int> nums1, nums2;
public:
    Solution(vector<int>& nums) {
        nums1 = nums;
        nums2 = nums1;
    }

    vector<int> reset() {
        nums2 = nums1;
        return nums2;
    }

    vector<int> shuffle() {
        // unsigned seed = 0;
        // auto myRandom = [](int i) {
        //     return rand() % i;
        // };
        // random_shuffle(nums2.begin(), nums2.end(), myRandom);
        // return nums2;


        for (int i = nums2.size() - 1; i >= 0; i--) {
            int j = rand() % (i + 1);
            swap(nums2[i], nums2[j]);
        }
        return nums2;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



