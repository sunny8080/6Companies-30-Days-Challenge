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



// Link :- https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/


class Solution {
    int findTheWinnerHelp(int n, int k) {
        return (n == 0) ? 0 : (findTheWinnerHelp(n - 1, k) + k) % n;
    }
public:
    // brute force
    int findTheWinner1(int n, int k) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = i + 1;

        int i = 0;
        while (nums.size() > 1) {
            i = (i + k - 1) % nums.size();
            nums.erase(nums.begin() + i);
        }
        return nums[0];
    }


    // queue/list simulation
    int findTheWinner2(int n, int k) {
        vector<bool> nums(n, 1);
        int i = 0, cnt = n;
        while (cnt > 1) {
            for (int j = 0; j < k; j++, i++) while (!nums[i % n]) i++;
            nums[(i - 1) % n] = 0;
            cnt--;
        }
        for (i = 0; !nums[i]; i++);
        return i + 1;
    }


    // Joseph's Problem
    int findTheWinner(int n, int k) {
        return findTheWinnerHelp(n, k) + 1;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




