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


// Link :- https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/



class Solution {
    // check we can create rhombus with side (sz+1) or not
    bool isValid(int sz, int i, int j, int n, int m) {
        return (j - sz >= 0) && (j + sz < m) && (i + sz < n) && (i - sz >= 0);
    }
public:
    vector<int> getBiggestThree(vector<vector<int>>& g) {
        set<int> s;
        int n = g.size(), m = g[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // assume (i,j) as center and generate all possible Rhombus with increasing size
                // top = (i-sz, j) || right = (i, j-sz) || bottom = (i-sz, j)  || left = (i, j-sz)

                for (int sz = 0; isValid(sz, i, j, n, m); sz++) {
                    int sum = 0, x = i - sz, y = j;
                    while (x <= i) sum += g[x++][y++]; y -= 2; // top -> right  
                    while (y >= j) sum += g[x++][y--]; x -= 2; // right -> bottom  
                    while (x >= i) sum += g[x--][y--]; y += 2; // bottom -> left 
                    while (y < j) sum += g[x--][y++]; // left -> top 

                    s.insert(sum);
                    if (s.size() > 3) s.erase(begin(s));
                }
            }
        }

        return vector<int>(s.rbegin(), s.rend());
    }
};

int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



