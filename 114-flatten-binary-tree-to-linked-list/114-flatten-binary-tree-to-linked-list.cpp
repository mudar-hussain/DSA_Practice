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
    void flatten(TreeNode* root) {
        if(root == NULL) return ;
        while(root->left == NULL && root->right != NULL)
            root = root->right;
        
        TreeNode *next = root->right;
        TreeNode *curr = root;
        curr->right = curr->left;
        curr->left = NULL;
        while(curr->right) 
            curr = curr->right;
        curr->right = next;
        flatten(root->right);
    }
};