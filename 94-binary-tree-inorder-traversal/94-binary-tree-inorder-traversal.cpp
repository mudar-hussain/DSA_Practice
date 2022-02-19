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
    // void inorder(TreeNode* root, vector<int>& v){
    //     if(!root) return;
    //     inorder(root->left,v);
    //     v.push_back(root->val);
    //     inorder(root->right,v);
    // }
    void pushLeft(TreeNode *root, stack<TreeNode*> &s){
        while(root){
            s.push(root);
            root = root->left;
        }
            
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        pushLeft(root, s);
        // inorder(root,v);
        while(!s.empty()){
            TreeNode *temp = s.top();
            s.pop();
            v.push_back(temp->val);
            pushLeft(temp->right, s);
        }
        return v;
    }
    
};





















