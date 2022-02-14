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
    TreeNode* util(TreeNode * root){
        if(root->left) return util(root->left);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key){
            if(!root->left && !root->right){
                return NULL;
            }else if(root->left && root->right){
                TreeNode *temp = util(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
                return root;
            } else{
                 if(root->left) return root->left;
                 if(root->right) return root->right;
            }
        } else if(key > root->val)
                root->right = deleteNode(root->right, key);
        else
            root->left = deleteNode(root->left, key);
        return root;
        
        
    }
};
















