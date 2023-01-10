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



// Link :- https://leetcode.com/problems/invalid-transactions/description/



class Solution {
public:
    vector<string> invalidTransactions(vector<string>& trans) {
        vector<string> ans;
        int n = trans.size(); // {name, time, amt, city  }
        vector<string> name(n), city(n);
        vector<int> time(n), amt(n), invalid(n, 0);

        for (int i = 0; i < n; i++) {
            stringstream ss(trans[i]);
            string tmp;

            getline(ss, tmp, ',');
            name[i] = tmp;

            getline(ss, tmp, ',');
            time[i] = stoi(tmp);

            getline(ss, tmp, ',');
            amt[i] = stoi(tmp);

            getline(ss, tmp, ',');
            city[i] = tmp;
        }

        for (int i = 0; i < n; i++) {
            if (amt[i] > 1000) invalid[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (abs(time[i] - time[j]) <= 60 && name[i] == name[j] && city[i] != city[j]) invalid[i] = invalid[j] = 1;
            }
        }

        for (int i = 0; i < n; i++) if (invalid[i]) ans.push_back(trans[i]);
        return ans;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



