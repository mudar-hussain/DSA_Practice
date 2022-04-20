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
    //2nd Approach (BFS)
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int, map<int, vector<int>>> mp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            TreeNode *temp = curr.first;
            int line = curr.second.first;
            int row = curr.second.second;
            mp[line][row].push_back(temp->val);
            
            if(temp->left) q.push({temp->left, {line-1, row+1}});
            if(temp->right) q.push({temp->right, {line+1, row+1}});
            
        }
        for(auto line: mp){
            vector<int> v;
            
                for(auto row: line.second){
                    sort(row.second.begin(), row.second.end());
                    for(int val: row.second)
                        v.push_back(val);
                }
            
            
            ans.push_back(v);
        }
        return ans;
        
    }
        
        
    //1st Approach(DFS)
    
//     map<int,map<int,priority_queue<int, vector<int>, greater<int>>>> m;
//     void solve(TreeNode *root, int col, int row){
//         if(!root) return;
        
//         m[col][row].push(root->val);
//         solve(root->left,col-1,row+1);
//         solve(root->right,col+1,row+1);
//     }
    
// public:
    
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(!root) return ans;
//         solve(root,0,0);
        
//         for(auto m1: m){
//             vector<int> v;
//             for(auto m2: m1.second){
//                 while(!m2.second.empty()){
//                     v.push_back(m2.second.top());
//                     m2.second.pop();
//                 }
//             }
        
//             ans.push_back(v);
//         }
//         return ans;
        
//     }
    
};