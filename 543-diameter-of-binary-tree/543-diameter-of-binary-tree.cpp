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
    int dia = 0;
public:
    int solve(TreeNode *root){
        if(root==NULL)
            return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        int temp=1+max(l,r);
        int ans=max(temp,l+r+1);
        dia=max(dia,ans);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return dia-1;
        
    }
};