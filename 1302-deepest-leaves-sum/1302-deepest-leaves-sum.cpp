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
    int findHeight(TreeNode* root){
        if(root == NULL)
            return 0;
        
        return 1+max(findHeight(root->left), findHeight(root->right));
    }
    
    int dfs(TreeNode* root, int &height, int currHeight){
        if(root == NULL)
            return 0;
        int sum = dfs(root->left, height, currHeight+1);
        sum += dfs(root->right, height, currHeight+1);
        if(currHeight == height){
            sum += root->val;
        }
        
        return sum;
        
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return root->val;
        int height = findHeight(root);
        
        return dfs(root, height, 1);
        
        
        
    }
};