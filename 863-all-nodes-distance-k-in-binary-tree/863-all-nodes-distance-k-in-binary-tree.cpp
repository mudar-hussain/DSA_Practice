/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    unordered_map<TreeNode*,TreeNode*> mp;
    unordered_set<TreeNode*> vis;
    void dfs(TreeNode *target, int k){
        if(!target) return;
        if(vis.count(target) == true) return;
        vis.insert(target);
        if(k == 0){
            ans.push_back(target->val);
            return;
        }
        dfs(target->left,k-1);
        dfs(target->right,k-1);
        dfs(mp[target],k-1);
        
        
    }
    void parent(TreeNode *root, TreeNode *p){
        if(!root) return;
        mp[root] = p;
        parent(root->left,root);
        parent(root->right,root);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent(root,NULL);
        dfs(target, k);
        return ans;    
            
        }
    
};