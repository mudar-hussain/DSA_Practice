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
    Node* createGraph(Node* node, unordered_map<int, Node*>& um){
        Node *root = new Node(node->val);
        um[node->val] = root;
        
        for(auto i: node->neighbors){
            if(um[i->val] == NULL)
                root->neighbors.push_back(createGraph(i, um));
            else
                root->neighbors.push_back(um[i->val]);
                
        }
        return root;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        unordered_map<int, Node*> um;
        return createGraph(node, um);
    }
};




























