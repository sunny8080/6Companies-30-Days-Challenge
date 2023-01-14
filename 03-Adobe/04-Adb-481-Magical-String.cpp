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




// Link :- https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/



class Solution {
public:
    int magicalString1(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;
        vector<int> nums(n);
        nums[0] = 1, nums[1] = 2, nums[2] = 2;
        int ind = 3, cnt = 1, nextNum = 1, countInd = 2;

        while (ind < n) {
            int times = nums[countInd++];
            while (times-- && ind < n) {
                nums[ind++] = nextNum;
                cnt += (nextNum == 1);
            }
            nextNum ^= 3;
        }
        return cnt;
    }


    int magicalString(int n) {
        string s = "122";
        int i = 2;
        while (s.size() < n) {
            // int times = s[i++] - '0';
            // char ch = s.back() ^ 3;
            // while (times--) s += ch;

            s += string(s[i++] - '0', s.back() ^ 3);
        }
        return count(s.begin(), s.begin() + n, '1');
    }
};

int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



