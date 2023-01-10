#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll                 long long
// #define int                long long
#define ull                unsigned long long
#define ff                 first
#define ss                 second
#define pb                 push_back
#define mp                 make_pair
#define pii                pair<int,int>
#define vi                 vector<int>
#define vll                vector<ll> 
#define vvi                vector< vector<int>>
#define vvll               vector< vector<ll>>
#define vpii               vector<pair<int,int>>
#define mii                map<int,int>
#define pqb                priority_queue<int>
#define pqs                priority_queue<int, vector<int>, greater<int>>
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x,y)            fixed<<setprecision(y)<<x
#define mk(arr, n, type)   type *arr=new type[n];
#define wt(x)              int x; cin>>x; while( x-- )
#define sp                 ' '
#define nl                 char(10)
#define PRT(ar)            for( auto i : ar ) cout<<i<<sp; cout<<nl;
#define mems(x,ch)         memset(x,ch,sizeof(x))
#define sortv(x)           sort(x.begin(),x.end())
#define sortvr(x)          sort(x.rbegin(),x.rend())
#define all(x)             x.begin(), x.end()
#define fr(t,a,b)          for( int t=(a); t<=(b); t++)
#define frr(t,a,b)         for( int t=(a); t>=(b); t--)
#define cn(x)              int x; cin>>x;
#define ri(x)              cin >> x
#define rii(x, y)          cin >> x >> y
#define riii(x, y, z)      cin >> x >> y >> z
#define riiii(x, y, z, w)  cin >> x >> y >> z >> w
#define rvi(nums)          for (auto& x : nums) cin >> x;
#define dri(x)             int x; cin >> x
#define drs(s)             string s; cin >> s
#define drii(x, y)         int x, y; cin >> x >> y
#define driii(x, y, z)     int x, y, z; cin >> x >> y >> z
#define driiii(x, y, z, w) int x, y, z, w; cin >> x >> y >> z >> w
#define drvi(nums, n)      vector<int> nums(n); for (auto& x : nums) cin >> x;
#define iff(x, y)  if(x) y

const ll N = 1e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
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




