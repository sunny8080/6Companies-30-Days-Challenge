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


// Link :- https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/description/


class Solution {
public:
    int maxConsecutive(int b, int t, vector<int>& spec, int maxi = 0) {
        sort(spec.begin(), spec.end());
        for (int i = 1; i < spec.size(); i++)
            maxi = max(maxi, spec[i] - spec[i - 1] - 1);
        return max({ maxi, spec[0] - b, t - spec.back() });
    }


    // insert bottom-1 and top+1 in special, to manage 1st and last consecutive floors
    int maxConsecutive1(int b, int t, vector<int>& spec, int maxi = 0) {
        spec.insert(spec.begin(), { b - 1, t + 1 });
        sort(spec.begin(), spec.end());
        for (int i = 1; i < spec.size(); i++)
            maxi = max(maxi, spec[i] - spec[i - 1] - 1);
        return maxi;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




