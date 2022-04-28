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
    //2nd approach (Morris)
    void flatten(TreeNode* root) {
        TreeNode *curr = root;
        while(curr != NULL){
            if(curr->left != NULL){
                TreeNode *pre = curr->left;
                while(pre->right)
                    pre = pre->right;
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    
    }
    
    //1st Approach (BruteForce)
//     void flatten(TreeNode* root) {
//         if(root == NULL) return ;
//         while(root->left == NULL && root->right != NULL)
//             root = root->right;
        
//         TreeNode *next = root->right;
//         TreeNode *curr = root;
//         curr->right = curr->left;
//         curr->left = NULL;
//         while(curr->right) 
//             curr = curr->right;
//         curr->right = next;
//         flatten(root->right);
//     }
};