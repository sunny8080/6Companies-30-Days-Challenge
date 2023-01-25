#include<bits/stdc++.h>
using namespace std;

#define ll                 long long
#define int                long long
// #define mod                1000000007
#define inf                1e18
const ll N = 1e5 + 5;
void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}



// Link :- https://leetcode.com/problems/k-divisible-elements-subarrays/description/


class Trie {
    unordered_map<int, Trie*> mpp;
    int cnt = 0;
public:

    // insert recursively
    int insert(int i, int k, int p, vector<int>& nums) {
        if (i == nums.size() || k - (nums[i] % p == 0) < 0) return 0;
        if (mpp[nums[i]] == NULL) mpp[nums[i]] = new Trie();
        mpp[nums[i]]->cnt++;
        return (mpp[nums[i]]->cnt == 1) + mpp[nums[i]]->insert(i + 1, k - (nums[i] % p == 0), p, nums);
    }
};




class Trie2 {
    struct node {
        unordered_map<int, node*> mpp;
        int cnt = 0;
    };
    node* root;
public:
    Trie2() {
        root = new node();
    }

    // insert iteratively
    int insert(int i, int k, int p, vector<int>& nums) {
        node* cur = root;
        int ans = 0, divCnt = 0;
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] % p == 0) divCnt++;
            if (divCnt > k) break;
            if (cur->mpp[nums[j]] == NULL) cur->mpp[nums[j]] = new node(), ans++;
            cur = cur->mpp[nums[j]];
            cur->cnt++;
        }
        return ans;
    }
};



class Solution {
public:

    // O(N^3)
    int countDistinct1(vector<int>& nums, int k, int p) {
        int ans = 0, n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            for (int j = i, cnt = 0; j < n; j++) {
                if (nums[j] % p == 0) cnt++;
                if (cnt > k) break;
                tmp.push_back(nums[j]);
                st.insert(tmp);
            }
        }
        return st.size();
    }


    // O(N^2) // by Trie
    int countDistinct(vector<int>& nums, int k, int p) {
        int cnt = 0;

        // Trie* root = new  Trie();
        // for (int i = 0; i < nums.size(); i++)
        //     cnt += root->insert(i, k, p, nums);

        Trie2* root2 = new  Trie2();
        for (int i = 0; i < nums.size(); i++)
            cnt += root2->insert(i, k, p, nums);

        return cnt;
    }

};


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



