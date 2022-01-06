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
    int ht(TreeNode *root){
        if(!root) return 0;
        int left = ht(root->left);
        int right  = ht(root->right);
        if(left<0 || right<0 || abs(left-right)>1) return -1;
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return ht(root)>0;
         
        }
};