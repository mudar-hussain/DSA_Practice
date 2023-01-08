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
    pair<int, int> dfs(TreeNode *root, int &ans){
        if(root == NULL)
            return {0,0};
        int sum = root->val;
        int count = 1;
        
        pair<int, int> l = dfs(root->left, ans);
        pair<int, int> r = dfs(root->right, ans);
        
        sum += l.first + r.first;
        count += l.second + r.second;
        
        if(sum/count == root->val)
            ans++;
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};