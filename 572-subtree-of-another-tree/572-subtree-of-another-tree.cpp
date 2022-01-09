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
    bool identical(TreeNode *p, TreeNode *q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        
        return (p->val == q->val && identical(p->left,q->left) && identical(p->right,q->right));
    }
     // bool isSubtree(TreeNode* root, TreeNode* subRoot) {
     //     if(!root && !subRoot) return true;
     //     if(!root || !subRoot) return false;
     //     if(identical(root,subRoot)) return true;
     //     return ( isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
     // }
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->val == subRoot->val)
                if(identical(temp,subRoot)){
                    return true;
                }
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return false;
    }
};