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
    
    vector<int> v;
    TreeNode * predessor(TreeNode *root){
        if(!root) return NULL;
        TreeNode *cur = root->left;
        while(cur->right != NULL && cur->right != root){
            cur = cur->right;
        }
        return cur;
    }
    void morris(TreeNode *current){
        if(!current) return;
        while(current != NULL){
            if(!current->left){
                v.push_back(current->val);
                current = current->right;
            }else{
                TreeNode *pre = predessor(current);
                if(pre->right == NULL){
                    pre->right = current;
                    current = current->left;
                }
                else{
                    v.push_back(current->val);
                    pre->right = NULL;
                    current = current->right;
                }
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return v;
        morris(root);
        return v;
    }
};