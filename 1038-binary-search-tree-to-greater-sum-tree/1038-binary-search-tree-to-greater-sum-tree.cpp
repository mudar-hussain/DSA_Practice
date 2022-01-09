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
    int solve(TreeNode *root, int sum){
        if(!root) return sum;
        if(root->left && root->right){
            sum = root->val + solve(root->right,sum);
            root->val =  sum;
            sum = solve(root->left,sum);
            
        }else if(root->left){
            sum += root->val;
            root->val = sum;
            sum = solve(root->left,sum);
            
            
        }else if(root->right){
            sum = root->val + solve(root->right,sum);
            root->val = sum; 
            
        }else {
            sum += root->val;
            root->val = sum;
        }
        
        return sum;
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return root;
        solve(root,0);
        return root;
    }
};