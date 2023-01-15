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




// Link :- https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/


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
    int cnt = 0;

    // {sum, noOfNodes}
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return pair<int, int>(0, 0);
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int sum = left.first + right.first + root->val;
        int noOfNodes = left.second + right.second + 1;
        cnt += root->val == (sum / noOfNodes);
        return pair<int, int>(sum, noOfNodes);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};

int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



