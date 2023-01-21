#include<bits/stdc++.h>
using namespace std;

#define ll                 long long
// #define int                long long
// #define mod                1000000007
#define inf                1e18
const ll N = 1e5 + 5;
void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}



// Link :- https://leetcode.com/problems/number-of-ways-to-separate-numbers/description/


class Solution {

    bool isLessEqual(string a, string b) {
        if (a.size() < b.size()) return 1;
        if (a.size() > b.size()) return 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] < b[i]) return 1;
            else if (a[i] > b[i]) return 0;
        }
        return 1;
    }

    // return true if s[i...(i+len-1)] <= s[j...(j+len-1)]
    bool compare(int i, int j, int len, vector< vector<int>>& lcp, string& s) {
        int commonLen = lcp[i][j];
        if (commonLen >= len) return 1; // check equality
        if (s[i + commonLen] < s[j + commonLen]) return 1; // first substring is smaller
        return 0;
    }


public:
    // O(N^3)
    int numberOfCombinations1(string num) {
        if (num[0] == '0') return 0;
        int n = num.length(), mod = 1e9 + 7;

        // dp[i][j] = number of ways to form a list when number ending at index i and having length l
        vector< vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i + 1] = 1;
            for (int l = 1; l <= i; l++) {
                int j = i - l + 1;
                if (num[j] == '0') {
                    dp[i][l] = 0;
                    continue;
                }

                int length = 0;
                if (j < l) length = j;
                else if (isLessEqual(num.substr(j - l, l), num.substr(j, l))) length = l;
                else length = l - 1;

                // we can choose all numebers ending at j-1 and have length<l
                for (int k = 1; k <= length; k++) dp[i][l] = (dp[i][l] + dp[j - 1][k]) % mod;
            }
        }

        long cnt = 0;
        for (int j = 1; j <= n; j++) cnt = (cnt + dp[n - 1][j]) % mod;
        return cnt;
    }




    // O(N^2)
    int numberOfCombinations(string num) {
        if (num[0] == '0') return 0;
        int n = num.length(), mod = 1e9 + 7;

        // lcp[i][j] : len of longest common prefix of num[i...] and num[j...] 
        vector< vector<int>> lcp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (num[i] == num[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }


        // dp[i][j] = number of ways to form a list when number ending at index i and having length l
        // pref[i][len] = number of ways to form a list when number ending at index i and having length 1->len
        // pref[i][len] = sum(dp[i][1] + dp[i][2] + ... dp[i][len])
        vector< vector<int>> pref(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int l = 1; l <= i + 1; l++) {
                int j = i - l + 1, tmp = 0;

                if (num[j] == '0') pref[i][l] = 0;
                else if (j == 0) pref[i][l] = 1;
                else {
                    int length = 0;
                    if (j < l) length = j;
                    else if (compare(j - l, j, l, lcp, num)) length = l;
                    else length = l - 1;
                    pref[i][l] = pref[j - 1][length];
                }

                // we can choose all numebers ending at j-1 and have length<l
                pref[i][l] = (pref[i][l] + pref[i][l - 1]) % mod;
            }
        }

        return pref[n - 1][n];
    }
};



int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




