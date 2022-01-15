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
public:
     vector<int> ans;
    void solve(TreeNode *root, int k){
        if(ans.size()>=k) return;
        if(!root) return;
        solve(root->left, k);
        ans.push_back(root->val);
        solve(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        solve(root, k);
        if(ans.size()<k) return -1;
        return ans[k-1];
    }
};