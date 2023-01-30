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


// Link :- https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/


#define mod                1000000007
#define ll                 long long

class Solution {
    // return k size subarray match is possible or not
    bool query(vector<int>& nums1, vector<int>& nums2, int k) {
        map<ll, ll> mpp; // {hash, end_ind}
        ll hash = 0, p = 31, pwr = 1;

        for (ll i = 0; i < k; i++) pwr = (pwr * p) % mod;
        for (ll i = 0; i < nums1.size(); i++) {
            hash = (hash * p + nums1[i]) % mod;
            if (i >= k) hash = (hash - nums1[i - k] * pwr) % mod;
            if (hash < 0) hash += mod;
            if (i >= k - 1) mpp[hash] = i;
        }

        hash = 0;
        for (ll i = 0; i < nums2.size(); i++) {
            hash = (hash * p + nums2[i]) % mod;
            if (i >= k) hash = (hash - nums2[i - k] * pwr) % mod;
            if (hash < 0) hash += mod;

            if (i >= k - 1 && mpp.find(hash) != mpp.end()) {
                ll i1 = mpp[hash], i2 = i, cnt = k;
                while (cnt > 0) {
                    if (nums1[i1--] != nums2[i2--]) break;
                    cnt--;
                }
                if (cnt == 0) return 1;
            }
        }
        return 0;
    }
public:
    // O((M+N)*log(min(M,N)))
    int findLength1(vector<int>& nums1, vector<int>& nums2) {
        ll n1 = nums1.size(), n2 = nums2.size(), l = 0, r = min(n1, n2), maxi = 0;
        while (l <= r) {
            ll mid = (l + r) >> 1; // size of the window
            if (query(nums1, nums2, mid)) {
                maxi = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return maxi;
    }


    // O(M*N)
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int maxi = 0;
        int dp[nums1.size() + 1][nums2.size() + 1]; // dp[i][j] - longest common prefix of A[i:] and B{j:}
        memset(dp, 0, sizeof dp);

        for (int i = nums1.size() - 1; i >= 0; i--) {
            for (int j = nums2.size() - 1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }
        return maxi;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



