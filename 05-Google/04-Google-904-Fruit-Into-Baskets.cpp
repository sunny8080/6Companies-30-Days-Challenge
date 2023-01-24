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



// Link :- https://leetcode.com/problems/fruit-into-baskets/description/



class Solution {
public:
    // TC : O(N) // SC : (N)
    int totalFruit1(vector<int>& nums) {
        int n = nums.size(), prev1 = nums[0], prev2 = -1, cnt = 1, maxi = cnt, l = 0;;
        map<int, int> mpp = { { nums[0], 0 } };

        // carry the range and record last occurence of previous two numbers
        for (int i = 1; i < n; i++) {
            if (prev2 == -1) {
                if (nums[i] != prev1) prev2 = nums[i];
                mpp[nums[i]] = i;
                maxi = max(maxi, ++cnt);
            } else {
                if (nums[i] == prev1 || nums[i] == prev2) {
                    mpp[nums[i]] = i;
                    maxi = max(maxi, ++cnt);
                } else {
                    int& tmp = (nums[i - 1] == prev1 ? prev2 : prev1); // update range and cnt
                    cnt = cnt - (mpp[tmp] - l + 1) + 1;
                    l = mpp[tmp] + 1;
                    mpp.erase(tmp);
                    tmp = nums[i];
                    mpp[nums[i]] = i;
                }
            }
        }
        return maxi;
    }

    // TC : O(N) // SC : (N)
    int totalFruit2(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int left, right;
        for (left = 0, right = 0; right < nums.size(); right++) {
            mpp[nums[right]]++;

            // no need to reduce window size
            if (mpp.size() > 2) {
                if (--mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
        }
        return right - left;
    }


    // TC : O(N) // SC : O(1)
    int totalFruit3(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int left = 0, maxi = 0;
        for (int right = 0; right < nums.size(); right++) {
            mpp[nums[right]]++;

            // no need to reduce window size
            while (mpp.size() > 2) {
                if (--mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }


    // TC : O(N) // SC : O(1)
    int totalFruit(vector<int>& nums) {
        int first = 0, last = 0, cntFirst = 0, cntLast = 0, cur = 0, maxi = 0;

        //  ....abbbcc... // first=b, cntFirst=3 // last=c, cntLast=2
        for (auto x : nums) {
            cur = (x == first || x == last) ? cur + 1 : cntLast + 1;
            cntLast = (x == last) ? cntLast + 1 : 1;
            if (x != last) first = last, last = x;
            maxi = max(maxi, cur);
        }
        return maxi;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



