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
    int ans = 0;
    
    int zigZag(TreeNode* root, int isLeft, int currCount){
        if(root == NULL){
            return 0;
        }
        
        //currCount
        if(isLeft){
            currCount += 1+zigZag(root->right, 0, currCount);
            ans = max(ans, zigZag(root->left, 1, 0));
        }else{
            currCount += 1+zigZag(root->left, 1, currCount);
            ans = max(ans, zigZag(root->right, 0, 0));
        }
        
        ans = max(ans, currCount);
        return currCount;
        
        
    }
public:
    int longestZigZag(TreeNode* root) {
        ans = 0;
        zigZag(root->left, 1, 0);
        zigZag(root->right, 0, 0);
        return ans;
    }
};