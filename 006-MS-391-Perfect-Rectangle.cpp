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


// Link : https://leetcode.com/problems/perfect-rectangle/description/


class Solution {
    // If you want to understand : https://leetcode.com/problems/perfect-rectangle/solutions/87180/o-n-solution-by-counting-corners-with-detailed-explaination/

    // pos => 1-BL, 2-BR, 4-TR, 8-TL  // B-Bottom, T-Top, L-Left, R-Right
    bool insertCorner(int x, int y, int pos, unordered_map<int, unordered_map<int, int>>& mpp) {
        int& m = mpp[x][y];
        if (m & pos) return 0; // rectangle aligned
        m |= pos;
        return 1;
    }
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<int, unordered_map<int, int>> mpp; // {x, {y, pos}}
        int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;

        // step -1 : counting
        for (auto& rect : rectangles) {
            minx = min(minx, rect[0]);
            miny = min(miny, rect[1]);
            maxx = max(maxx, rect[2]);
            maxy = max(maxy, rect[3]);


            if (!insertCorner(rect[0], rect[1], 1, mpp)) return 0; // BL         
            if (!insertCorner(rect[2], rect[1], 2, mpp)) return 0; // BR       
            if (!insertCorner(rect[2], rect[3], 4, mpp)) return 0; // TR          
            if (!insertCorner(rect[0], rect[3], 8, mpp)) return 0; // TL          
        }

        // step 2 : checking
        bool valid_corners[16] = { 0 };
        bool valid_interior[16] = { 0 };
        valid_corners[1] = valid_corners[2] = valid_corners[4] = valid_corners[8] = 1;

        // T - junction can be formed by => {BR,BL=>2,1=>3}  {TR,BR=>4,2=>6}   {TL,BL=>8,1=>9}  {TL,TR =>8, 4 => 12 } 
        // Cross (+) can be formed by => {BL, BR, TR, TL  => 1, 2, 4, 8 => 15} 
        valid_interior[3] = valid_interior[6] = valid_interior[9] = valid_interior[12] = valid_interior[15] = 1;

        for (auto& it : mpp) {
            int x = it.first;
            for (auto& ity : it.second) {
                int y = ity.first, mask = ity.second;
                if (((x != minx && x != maxx) || (y != miny && y != maxy)) && !valid_interior[mask]) return 0;
            }
        }
        return 1;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



