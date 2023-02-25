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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        map<int, map<int, vector<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});
        
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int col = q.front().second.first;
            int row = q.front().second.second;
            q.pop();
            
            mp[col][row].push_back(temp->val);
            
            if(temp->left) q.push({temp->left, {col-1, row+1}});
            
            if(temp->right) q.push({temp->right, {col+1, row+1}});
            
        }
        
        for(auto i: mp){
            vector<int> v;
            for(auto j: i.second){
                sort(j.second.begin(), j.second.end());
                v.insert(v.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(v);
        }
        
        
        return ans;
        
    }
};










