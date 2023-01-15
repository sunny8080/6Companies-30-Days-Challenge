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




// Link :- https://leetcode.com/problems/stock-price-fluctuation/description/


// unordered map
class StockPrice1 {
    multiset<int> st;
    unordered_map<int, int> mpp; // {time, price}
    int curTime = 0;
    int curCost = 0;
public:
    StockPrice1() {}

    void update(int t, int price) {
        if (mpp[t]) st.erase(st.find(mpp[t]));
        mpp[t] = price;
        st.insert(price);
        if (t >= curTime) curTime = t, curCost = price;
    }

    int current() { return curCost; }
    int maximum() { return *st.rbegin(); }
    int minimum() { return *st.begin(); }
};



// ordered map
class StockPrice {
    multiset<int> st;
    map<int, int> mpp; // {time, price}
public:
    StockPrice() {}

    void update(int t, int price) {
        if (mpp[t]) st.erase(st.find(mpp[t]));
        mpp[t] = price;
        st.insert(price);
    }

    int current() { return rbegin(mpp)->second; }
    int maximum() { return *st.rbegin(); }
    int minimum() { return *st.begin(); }
};



/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



