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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
	queue<pair<TreeNode*, double>> Queue;
	Queue.push({root, 0});
	double ans = INT_MIN;

	while(!Queue.empty()) {
		int size = Queue.size();
		double left = Queue.front().second, right = left;
		while(size--) {
			TreeNode* node = Queue.front().first;
			right = Queue.front().second;
			Queue.pop();
			if(node->left) Queue.push({node->left, (right-left)*2});
			if(node->right) Queue.push({node->right, (right-left)*2+1});
		}
		ans = max(ans, right-left+1);
	}
	return ans;
        
    }
};