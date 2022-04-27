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
        unordered_map<int, int> um;
    
        TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index, int lb, int ub) {
            if(lb>ub) return NULL;
            TreeNode *res = new TreeNode(preorder[index++]);
            if(lb == ub) return res;
            int mid = um[res->val];
            
            res->left = solve(preorder, inorder, index, lb, mid-1);
            res->right = solve(preorder, inorder, index, mid+1, ub);
            
            return res;

        }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        um.clear();
        for(int i = 0; i<preorder.size(); i++){
            um[inorder[i]] = i;
        }
        TreeNode *root = solve(preorder, inorder, index, 0, preorder.size()-1);
        return root;
    }
};