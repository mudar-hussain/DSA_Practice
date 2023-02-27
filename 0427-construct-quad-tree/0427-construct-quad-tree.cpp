/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    Node* solve(vector<vector<int>> &grid, int n, int i, int j){
        Node* root = new Node(grid[i][j], true);
        if(n == 1){
            return root;
        }
        
        root->topLeft = solve(grid, n/2, i, j);
        root->topRight = solve(grid, n/2, i, j+n/2);
        root->bottomLeft = solve(grid, n/2, i+n/2, j);
        root->bottomRight = solve(grid, n/2, i+n/2, j+n/2);
        
        bool allLeaf = (root->topLeft->isLeaf == 1 
                        && root->topRight->isLeaf == 1 
                        && root->bottomLeft->isLeaf == 1 
                        && root->bottomRight->isLeaf == 1);
        
        bool allValEq = (root->topLeft->val == root->topRight->val 
                         && root->topRight->val == root->bottomLeft->val
                         && root->bottomLeft->val == root->bottomRight->val);
        
        if(allLeaf && allValEq){
                    
            root->topLeft = NULL;
            root->topRight = NULL;
            root->bottomLeft = NULL;
            root->bottomRight = NULL;
            
        }else
            root->isLeaf = false;
            
        
        return root;
    }
    
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        
        return solve(grid, n, 0, 0);
    }
};































