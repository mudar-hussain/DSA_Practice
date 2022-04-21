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
    //2nd Approach (BFS)
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        queue<TreeNode*> q1;
        q1.push(p);
        queue<TreeNode*> q2;
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
        
            if(q1.front()->val != q2.front()->val) return false;
            
            if(q1.front()->left)  q1.push(q1.front()->left);
            if(q2.front()->left)  q2.push(q2.front()->left);
            if(q1.size() != q2.size()) return false;
            
            if(q1.front()->right) q1.push(q1.front()->right);
            if(q2.front()->right) q2.push(q2.front()->right);
            if(q1.size() != q2.size()) return false;
            
            q1.pop();
            q2.pop();
            
        }
        return true;
    }

    //1st Approach (DFS)
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p == nullptr && q == nullptr) return true;
//         if(p == nullptr || q == nullptr) return false;
        
//         return(p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
        
//     }
};