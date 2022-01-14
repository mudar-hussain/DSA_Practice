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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int& start, int is, int ie){
        if(is>ie) return NULL;
        int mid = um[postorder[start]];
        TreeNode *root = new TreeNode(postorder[start]);
        start--;
        root->right = solve(postorder,inorder,start,mid+1,ie);
        root->left = solve(postorder,inorder,start,is,mid-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        if(!n) return NULL;
        
        for(int i = 0; i<n; i++){
            um[inorder[i]] = i;
        }
        int start = n-1;
        return solve(postorder,inorder,start,0,n-1);
    }
};