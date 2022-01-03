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
    map<int,map<int,priority_queue<int, vector<int>, greater<int>>>> m;
    void solve(TreeNode *root, int col, int row){
        if(!root) return;
        
        m[col][row].push(root->val);
        solve(root->left,col-1,row+1);
        solve(root->right,col+1,row+1);
    }
    
public:
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        solve(root,0,0);
        
        for(auto m1: m){
            vector<int> v;
            for(auto m2: m1.second){
                while(!m2.second.empty()){
                    v.push_back(m2.second.top());
                    m2.second.pop();
                }
            }
        
            ans.push_back(v);
        }
        return ans;
        
    }
    
};