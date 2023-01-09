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



// Link :- https://leetcode.com/problems/count-good-triplets-in-an-array/description/




#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


// Using policy based ds
class Solution1 {
public:
    // O(N^2)
    long long goodTriplets1(vector<int>& nums1, vector<int>& nums2) {
        long long cnt = 0, n = nums1.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) mpp[nums2[i]] = i;

        for (int i = 1; i <= n - 2; i++) {
            int left = 0, right = 0;

            unordered_map<int, int> mpp2;
            for (int j = i - 1; j >= 0; j--) mpp2[nums1[j]]++;
            for (int j = mpp[nums1[i]] - 1; j >= 0; j--) left += mpp2[nums2[j]];
            mpp2.clear();

            for (int j = i + 1; j < n; j++) mpp2[nums1[j]]++;
            for (int j = mpp[nums1[i]] + 1; j < n; j++) right += mpp2[nums2[j]];
            cnt += left * 1ll * right;
        }
        return cnt;
    }


    // O(N^2)
    long long goodTriplets2(vector<int>& nums1, vector<int>& nums2) {
        long long cnt = 0, n = nums1.size();
        unordered_map<int, int> pos2;
        for (int i = 0; i < n; i++) pos2[nums2[i]] = i;

        set<int> left, right;
        left.insert(pos2[nums1[0]]);
        for (int i = 2; i < n; i++) right.insert(pos2[nums1[i]]);

        for (int i = 1; i <= n - 2; i++) {
            int k = pos2[nums1[i]];
            int a = distance(left.begin(), left.lower_bound(k)); // O(N)
            int b = right.size() - distance(right.begin(), right.lower_bound(k));
            cnt += a * 1ll * b;

            left.insert(pos2[nums1[i]]);
            right.erase(pos2[nums1[i + 1]]);
        }

        return cnt;
    }


    // Using policy based data str -  O(NlogN) 
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long cnt = 0, n = nums1.size();
        unordered_map<int, int> pos2;
        for (int i = 0; i < n; i++) pos2[nums2[i]] = i;

        oset<int> left, right;
        left.insert(pos2[nums1[0]]);
        for (int i = 2; i < n; i++) right.insert(pos2[nums1[i]]);

        for (int i = 1; i <= n - 2; i++) {
            int k = pos2[nums1[i]];
            int a = left.order_of_key(k); // O(logN)
            int b = right.size() - right.order_of_key(k);
            cnt += a * 1ll * b;

            left.insert(pos2[nums1[i]]);
            right.erase(pos2[nums1[i + 1]]);
        }

        return cnt;
    }
};







// using BIT(fenwick tree) // (NlogN)
const int n = (int)1e5;
int bit[n + 1];

class Solution {

    // bit -> 1 indexed
    // update => increase ith value of  bit by val
    // ind is 0-based
    void update(int ind, int val) {
        for (int i = ind + 1; i <= n; i += i & (-i)) bit[i] += val;
    }

    // return prefix sum in [1...ind]
    int prefixSum(int ind) {
        int sum = 0;
        for (int i = ind + 1; i > 0; i -= i & (-i)) sum += bit[i];
        return sum;
    }

public:
    // O(NlogN)
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long cnt = 0, n = nums1.size();
        unordered_map<int, int> pos2;
        for (int i = 0; i < n; i++) pos2[nums2[i]] = i;

        memset(bit, 0, sizeof bit);

        for (int i = 0; i < n - 1; i++) {
            int mid = pos2[nums1[i]];
            // left = no of matched elements before middle one // right =  no of matched elements after middle one
            // right = (total no of elements in nums2 after middle ) - (mo of mismatched elements)
            int left = prefixSum(mid), right = (n - mid - 1) - (i - left);
            cnt += left * 1ll * right;
            update(mid, 1);
        }
        return cnt;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



