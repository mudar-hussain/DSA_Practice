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
//     void invert(TreeNode *p,  TreeNode *q, TreeNode *root){
//         if(!p && !q) return;
//         if(p && q){
//             TreeNode *temp = root->left;
//             root->left = root->right;
//             root->right = temp;
//             return invert(p-left,p-right);
//             return invert(q-left,q-right);
//         }
        
        
//     }
    TreeNode* invertTree(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return root;
        
        if(root->left!=NULL && root->right!=NULL){
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
             // delete temp;
            invertTree(root->left);
            invertTree(root->right);
        }
        else if(!root->left){
            root->left = root->right;
            root->right = NULL;
            invertTree(root->left);
        }
        else if(!root->right){
            root->right = root->left;
            root->left = NULL;
            invertTree(root->right);
        }
        return root;
        
        
        
    }
};