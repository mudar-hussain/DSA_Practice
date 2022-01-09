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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 1;
        int level = 0;
        int sum = INT_MIN;
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int tt = 0;
            level++;
            while(size--){
                TreeNode *temp = q.front();
                q.pop();
                tt += temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
            }
            if(tt>sum){
                ans = level;
                sum = tt;
            }
        }
        return ans;
    }
};