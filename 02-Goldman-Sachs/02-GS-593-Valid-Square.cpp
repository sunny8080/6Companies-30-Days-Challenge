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



// Link :- https://leetcode.com/problems/valid-square/description/


class Solution {
    int dist(vector<int>& a, vector<int>& b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
public:
    // valid square has 4 equal sized side and has 2 equal diagonal 
    bool validSquare1(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<vector<int>, int> mpp;
        mpp[p1] = mpp[p2] = mpp[p3] = mpp[p4] = 1;
        if (mpp.size() != 4) return 0;

        auto cmp = [&](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return (a[0] < b[0]);
        };
        vector<vector<int>> a({ p1, p2, p3, p4 });
        sort(a.begin(), a.end(), cmp);

        if (dist(a[0], a[3]) != dist(a[1], a[2])) return 0;
        map<int, int> mpp2;
        mpp2[dist(a[0], a[1])]++;
        mpp2[dist(a[0], a[2])]++;
        mpp2[dist(a[3], a[1])]++;
        mpp2[dist(a[3], a[2])]++;
        if (mpp2.size() != 1) return 0;

        return 1;
    }



    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> st({ dist(p1, p2), dist(p1, p3), dist(p1, p4), dist(p2, p3), dist(p2, p4), dist(p3, p4) });
        return !st.count(0) && st.size() == 2;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



