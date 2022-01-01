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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        while(!q.empty()){
            int size = q.size();
            v.clear();
            while(size--){
                TreeNode *temp = q.front();
                v.push_back(temp->val);
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};