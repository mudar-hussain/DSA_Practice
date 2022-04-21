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
    //2nd Approach (DFS)
    void dfs(TreeNode *root,int level,vector<list<int>> &ans){
        if(!root) return;
        if(ans.size()<level+1){
            // First time reached this level
            ans.push_back(list<int>({root->val}));
        }else{
            if(level%2==0){
                ans[level].push_back(root->val);                
            }else{
                ans[level].push_front(root->val);                                
            }
        }
        dfs(root->left,level+1,ans);
        dfs(root->right,level+1,ans);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<list<int>> ans;
        dfs(root,0,ans);
        
        vector<vector<int>>ret;
        for(list<int> l:ans){
            ret.push_back(vector<int>(l.begin(),l.end()));
        }
        return ret;
    }
    
    //1st Approach (BFS)
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//       vector<vector<int>> ans;
//         if(!root) return ans;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             int size = q.size();
//             vector<int> vv;
//             while(size--){
//                 TreeNode *temp = q.front();
//                 q.pop();
//                 vv.push_back(temp->val);
//                 if(temp->left) q.push(temp->left);
//                 if(temp->right) q.push(temp->right);
                
//             }
//             ans.push_back(vv);
//         }
//         for(int i = 1; i<ans.size();i+=2){
//             reverse(ans[i].begin(),ans[i].end());
//         }
//         return ans;
//     }
};