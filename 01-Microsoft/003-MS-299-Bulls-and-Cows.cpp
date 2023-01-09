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



// Link : https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string sec, string gs) {
        map<char, int> mpp;
        map<char, int> mpp2;
        int bull = 0, cow = 0, n = sec.size();
        for (int i = 0; i < n; i++) {
            if (sec[i] != gs[i]) mpp[sec[i]]++, mpp2[gs[i]]++;
        }

        for (int i = 0; i < n; i++) { // visit guess
            if (sec[i] == gs[i]) bull++;
            else cow += min(mpp[gs[i]], mpp2[gs[i]]), mpp[gs[i]] = 0;
        }

        string ans = to_string(bull) + "A" + to_string(cow) + "B";
        return ans;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



