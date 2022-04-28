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
    TreeNode* bst(vector<int>& preorder, int maxi, int mini, int &i){
        if(i >= preorder.size()) return NULL;
        if(preorder[i]<mini || preorder[i]>maxi) return NULL;
        TreeNode *root = new TreeNode(preorder[i]);
        i++;
        root->left = bst(preorder, root->val, mini, i);
        root->right = bst(preorder, maxi, root->val, i);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int i = 0;
        
        return bst(preorder, maxi, mini, i);
        
    }
};









