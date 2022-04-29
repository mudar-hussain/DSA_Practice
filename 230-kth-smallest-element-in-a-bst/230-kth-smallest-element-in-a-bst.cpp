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
    void inorder(TreeNode* root, int k, vector<int> &ans) {
        if(root == NULL) return;
        if(ans.size()>k) return;
        inorder(root->left, k,ans);
        ans.push_back(root->val);
        return inorder(root->right, k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL || k == 0) return -1;
        vector<int> ans;
        inorder(root, k, ans);
        return ans[k-1];
    }
};