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
    vector<vector<int>> ans;
    void pathSum(TreeNode *root,vector<int> paths, int sum,int targetSum){
        if(!root) return;
        sum += root->val;
        paths.push_back(root->val);
        if(!root->left && !root->right){
            if(sum == targetSum)
                ans.push_back(paths);
            return;
        }
        pathSum(root->left,paths,sum,targetSum);
        pathSum(root->right,paths,sum,targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> paths;
        int sum = 0;
        pathSum(root,paths,sum,targetSum);
        return ans;
    }
};










