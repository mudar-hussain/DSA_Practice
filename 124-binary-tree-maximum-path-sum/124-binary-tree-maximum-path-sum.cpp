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
    int solve(TreeNode *root, int &ans){
        if(root == NULL) return 0;
        int lTree = solve(root->left, ans);
        int rTree = solve(root->right, ans);
        
        ans = max({ans, root->val + lTree + rTree,  root->val + lTree,  root->val + rTree, root->val});
        
        return max({ root->val, root->val + lTree,  root->val + rTree});
            
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
    
};