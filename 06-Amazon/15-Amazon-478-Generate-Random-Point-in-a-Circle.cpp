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


// Link :- https://leetcode.com/problems/generate-random-point-in-a-circle/description/



class Solution {
    double rad, cenX, cenY;
    double PI = 3.14159265359;
public:
    Solution(double radius, double x_center, double y_center) {
        tie(rad, cenX, cenY) = { radius, x_center, y_center };
    }

    double getRand() {
        return (double)rand() / RAND_MAX;
    }

    vector<double> randPoint() {
        double theta = getRand() * 2 * PI,
            len = sqrt(getRand()) * rad,
            x = cenX + len * cos(theta),
            y = cenY + len * sin(theta);
        return vector<double>({ x, y });
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */



int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




