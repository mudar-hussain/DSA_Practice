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
    int dfs(TreeNode* root, unordered_map<int, int> um, int level){
        if(root == NULL){
            return 0;
        }
        
        if(root->val % 2 == 0){
            um[level] = 1;
        }else
            um[level] = -1;
        
        um[level-2]--;
        
        int l = dfs(root->left, um, level+1);
        int r = dfs(root->right, um, level+1);
        
        if(um[level-2]==0){
            return root->val + l + r;
        }else{
            return l + r;
        }
        
        
    }
    int sumEvenGrandparent(TreeNode* root) {
        unordered_map<int, int> um;
        return dfs(root, um, 0);
        
    }
};