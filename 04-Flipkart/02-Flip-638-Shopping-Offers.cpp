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




// Link :- https://leetcode.com/problems/shopping-offers/description/


class Solution {
    int shoppingOffersHelp(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, map<vector<int>, int>& dp) {
        if (dp.count(needs)) return dp[needs];
        int mini = 0, n = price.size();

        // buy all on regular price
        for (int i = 0; i < n; i++) mini += needs[i] * price[i];
        // mini = inner_product(needs.begin(), needs.end(), price.begin(), 0);

        for (auto& offer : special) {
            if (offer.back() >= mini) continue; // prunnig
            int canUse = 1;
            for (int i = 0; i < n; i++) {
                if (needs[i] < offer[i]) canUse = 0;
                needs[i] -= offer[i];
            }

            // if we can use this offer, then use it
            if (canUse) mini = min(mini, offer.back() + shoppingOffers(price, special, needs));

            // back tracking
            for (int i = 0; i < n; i++) needs[i] += offer[i];
        }
        return dp[needs] = mini;
    }


public:
    // top down dp without memoization
    int shoppingOffers1(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int mini = 0, n = price.size();

        // buy all on regular price
        for (int i = 0; i < n; i++) mini += needs[i] * price[i];
        // mini = inner_product(needs.begin(), needs.end(), price.begin(), 0);

        for (auto& offer : special) {
            if (offer.back() >= mini) continue; // prunnig
            int canUse = 1;
            for (int i = 0; i < n; i++) {
                if (needs[i] < offer[i]) canUse = 0;
                needs[i] -= offer[i];
            }

            // if we can use this offer, then use it
            if (canUse) mini = min(mini, offer.back() + shoppingOffers(price, special, needs));

            // back tracking
            for (int i = 0; i < n; i++) needs[i] += offer[i];
        }
        return mini;
    }


    // dp with memoization
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<vector<int>, int> dp;
        return shoppingOffersHelp(price, special, needs, dp);
    }
};

int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



