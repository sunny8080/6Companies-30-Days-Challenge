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



// Link :- https://leetcode.com/problems/closest-prime-numbers-in-range/description/

#define ll                 long long
ll N = 1e6;
vector<int> primes;


class Solution {
    void primeSieve(ll N) {
        vector<int> sieve(N + 1, 1);
        sieve[0] = sieve[1] = 0;

        for (ll i = 2; i <= N; i++) {
            // i is prime if sieve[i] = 1
            if (sieve[i] == 1) {
                primes.push_back(i);
                for (ll j = i * 1ll * i; j <= N; j += i) {
                    sieve[j] = 0;
                }
            }
        }
    }

public:
    vector<int> closestPrimes(int left, int right) {
        if (primes.size() == 0) primeSieve(N);
        vector<int> ans = { -1, -1 };

        int l = lower_bound(primes.begin(), primes.end(), left) - primes.begin();
        int r = upper_bound(primes.begin(), primes.end(), right) - primes.begin() - 1;
        // cout << primes[l] << " " << primes[r] << "\n";

        if (r - l + 1 < 2) return ans;
        int a = l, mini = INT_MAX;

        for (int i = l; i < r; i++) {
            if (primes[i + 1] - primes[i] < mini) {
                ans[0] = primes[i], ans[1] = primes[i + 1];
                mini = primes[i + 1] - primes[i];
            }
        }
        // cout<<ans[0]<<" "<<ans[1]<<"\n";

        return ans;
    }
};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



