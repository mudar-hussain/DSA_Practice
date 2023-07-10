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
    int depth = INT_MAX;
    void dfs(TreeNode* root, int level){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            depth = min(depth, level);
            return;
        }
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
public:
    int minDepth(TreeNode* root) {
        dfs(root, 1);
        return depth==INT_MAX?0:depth;
    }
};