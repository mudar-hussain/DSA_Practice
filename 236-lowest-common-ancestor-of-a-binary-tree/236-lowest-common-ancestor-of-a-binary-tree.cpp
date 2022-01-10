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
    TreeNode* ans;
    bool isthere(TreeNode *root, TreeNode* p, TreeNode* q){
        if(!root) return false;
        if(root->val == p->val || root->val == q->val){
            return true;
        }
        return (isthere(root->left,p,q) || isthere(root->right,p,q));
    }
    
    void solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(ans) cout<<ans->val<<" ";
        if(!root || ans) return;
        if(root->val == p->val || root->val == q->val){
            if(isthere(root->left,p,q) || isthere(root->right,p,q)){
                ans = root;
                return;
            }
        }
        if(root->left && root->right){
            if(isthere(root->left,p,q) && isthere(root->right,p,q)) {
                ans = root;
                return;
            }
        }
        if(root->left){
            if(isthere(root->left,p,q)){
                solve(root->left,p,q);
                return;
            }
            
        }
        if(root->right){
            if(isthere(root->right,p,q)){
                solve(root->right,p,q);
                return;
            }
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        solve(root,p,q);
        return ans;
        
    }
};