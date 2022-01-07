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
    pair<int,int> ans;
    void solve(TreeNode* root,int row){
        if(!root) return;
        if(ans.first<row){
            ans.first = row;
            ans.second = root->val;
        }
        solve(root->left,row+1);
        solve(root->right,row+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return -1;
        ans.first = -1;
        solve(root,0);
        return ans.second;
    }
};