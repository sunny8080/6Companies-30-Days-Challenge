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




// Link :- https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/


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
    void inOrderTrav(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inOrderTrav(root->left, nums);
        nums.push_back(root->val);
        inOrderTrav(root->right, nums);
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), i = 0, j = 0, k = 0;
        vector<int> tmp(n1 + n2);
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) tmp[k++] = nums1[i++];
            else tmp[k++] = nums2[j++];
        }

        while (i < n1) tmp[k++] = nums1[i++];
        while (j < n2) tmp[k++] = nums2[j++];
        return tmp;
    }


    void pushAllLeft(stack<TreeNode*>& stk, TreeNode* root) {
        // while (root) stk.push(root), root = root->left;
        while (root) stk.push(exchange(root, root->left));
    }
public:
    // TC : O(2*n) // SC : O(2*n)   // n=n1+n2 
    vector<int> getAllElements1(TreeNode* root1, TreeNode* root2) {
        vector<int> in1, in2;
        inOrderTrav(root1, in1);
        inOrderTrav(root2, in2);
        return merge(in1, in2);
    }



    // TC : O(n) // SC : O(n)   // n=n1+n2 
    vector<int> getAllElements2(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        stack<TreeNode*> s1, s2;
        pushAllLeft(s1, root1);
        pushAllLeft(s2, root2);

        while (s1.size() && s2.size()) {
            stack<TreeNode*>& s = s1.top()->val < s2.top()->val ? s1 : s2;
            auto top = s.top();
            s.pop();
            ans.push_back(top->val);
            pushAllLeft(s, top->right);
        }

        while (s1.size()) {
            auto top = s1.top();
            s1.pop();
            ans.push_back(top->val);
            pushAllLeft(s1, top->right);
        }

        while (s2.size()) {
            auto top = s2.top();
            s2.pop();
            ans.push_back(top->val);
            pushAllLeft(s2, top->right);
        }

        return ans;
    }




    // TC : O(n) // SC : O(n)   // n=n1+n2  // shorter => one pass
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        stack<TreeNode*> s1, s2;
        pushAllLeft(s1, root1);
        pushAllLeft(s2, root2);

        while (s1.size() || s2.size()) {
            stack<TreeNode*>& s = s1.empty() ? s2 : (s2.empty() ? s1 : (s1.top()->val < s2.top()->val ? s1 : s2));
            auto top = s.top();
            s.pop();
            ans.push_back(top->val);
            pushAllLeft(s, top->right);
        }
        return ans;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



