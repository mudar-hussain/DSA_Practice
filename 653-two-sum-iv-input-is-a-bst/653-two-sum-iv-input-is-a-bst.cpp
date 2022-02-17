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
    void st(TreeNode *root, stack<TreeNode *> &s, int direction){
        if(!root) return;
        s.push(root);
        if(direction){
            while(root->left){
                
                root = root->left;
                s.push(root);
            }
        }else{
            while(root->right){
                root = root->right;
                s.push(root);
            }
        }
        
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        stack<TreeNode*> mins, maxs;
        st(root,mins, 1);
        st(root,maxs, 0);
        while(!mins.empty() && !maxs.empty() && mins.top()->val < maxs.top()->val){
            int x = mins.top()->val;
            int y = maxs.top()->val;
            if(x+y == k) return true;
            else if(x+y < k) {
                TreeNode *temp = mins.top();
                mins.pop();
                st(temp->right, mins, 1);
            }
            else{
                TreeNode *temp = maxs.top();
                maxs.pop();
                st(temp->left, maxs, 0);
            }
             
        }
        return false;
        
    }
};










