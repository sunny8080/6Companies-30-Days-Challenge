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


// Link :- https://leetcode.com/problems/house-robber-iii/description/


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
    unordered_map<TreeNode*, int> mpp;

    pair<int, int> robHelp(TreeNode* root) {
        if (!root) return pair<int, int>(0, 0);
        pair<int, int> left = robHelp(root->left), right = robHelp(root->right), p;
        p.first = max(left.first, left.second) + max(right.first, right.second); // not take root
        p.second = root->val + left.first + right.first; // take root 
        return p;
    }


public:
    // O(2^N)
    int rob1(TreeNode* root) {
        if (!root) return 0;
        int ans = root->val; // take root
        if (root->left) ans += rob(root->left->left) + rob(root->left->right);
        if (root->right) ans += rob(root->right->left) + rob(root->right->right);
        return max(ans, rob(root->left) + rob(root->right));
    }


    // O(N)
    int rob2(TreeNode* root) {
        if (!root) return 0;
        if (mpp[root]) return mpp[root]; // dp

        int ans = root->val; // take root
        if (root->left) ans += rob(root->left->left) + rob(root->left->right);
        if (root->right) ans += rob(root->right->left) + rob(root->right->right);
        return mpp[root] = max(ans, rob(root->left) + rob(root->right));
    }


    // O(N)
    int rob(TreeNode* root) {
        auto res = robHelp(root);
        return max(res.first, res.second);
    }
};

int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



