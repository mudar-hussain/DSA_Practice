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
    TreeNode* current = NULL;
    
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode *right = root->right;
        TreeNode *left = root->left;
        if(current){
            current->left = NULL;
            current->right = root;
        }
        current = root;
        flatten(left);
        flatten(right);
        return;
    }
};