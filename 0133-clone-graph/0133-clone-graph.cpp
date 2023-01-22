/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* solve(Node* root, unordered_map<Node*, Node*> &um){
        if(root == NULL)
            return root;
        
        Node *node = new Node(root->val);
        um[root] = node;
        vector<Node*> neighbors;
        for(auto i: root->neighbors){
            if(um.find(i) != um.end())
                neighbors.push_back(um[i]);
            else
                neighbors.push_back(solve(i, um));
        }
        
        node->neighbors = neighbors;
        return node;
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        unordered_map<Node*, Node*> um;
        return solve(node, um);
    }
};