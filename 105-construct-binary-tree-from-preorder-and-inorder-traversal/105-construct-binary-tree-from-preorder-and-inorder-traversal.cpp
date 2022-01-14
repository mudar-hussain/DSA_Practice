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
    unordered_map<int,int> um;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int& start, int is, int ie){
        if(is>ie) return NULL;
        int mid = um[preorder[start]];
        TreeNode *root = new TreeNode(preorder[start]);
        start++;
        root->left = solve(preorder,inorder,start,is,mid-1);
        root->right = solve(preorder,inorder,start,mid+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(!n) return NULL;
        
        for(int i = 0; i<n; i++){
            um[inorder[i]] = i;
        }
        int start = 0;
        return solve(preorder,inorder,start,0,n-1);
        
    }
};