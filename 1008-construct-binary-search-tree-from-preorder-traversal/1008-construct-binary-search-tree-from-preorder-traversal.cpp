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
    int nextgreater(vector<int> arr, int l, int r){
        for(int i = l; i<=r; i++){
            if(arr[i]>arr[l]) return i;
        }
        
        return r+1;
    }
    TreeNode* preConstruct(vector<int> preorder, int l, int r){
        
        if(l>r) return NULL;
        TreeNode* root = new TreeNode(preorder[l]);
        int g = nextgreater(preorder, l, r);
        cout<<g;
        root->left = preConstruct(preorder, l+1, g-1);
        root->right = preConstruct(preorder, g, r);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return preConstruct(preorder, 0, preorder.size()-1);
    }
};