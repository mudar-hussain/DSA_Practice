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
    bool symmetric(TreeNode *p, TreeNode *q){
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        
        if(p->val != q->val)
            return false;
        
        return symmetric(p->left, q->right) && symmetric(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        
        
        
        return symmetric(root->left, root->right);
        
    }
};