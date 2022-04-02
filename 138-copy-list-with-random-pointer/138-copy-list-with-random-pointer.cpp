/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //2nd Approach
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        unordered_map<Node*, Node*> um;
        Node *temp = head;
        while(temp){
            um[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp){
            um[temp]->next = um[temp->next];
            um[temp]->random = um[temp->random];
            temp = temp->next;
        }
        return um[head];
        
    }
    
    //1st Approach
//     Node* copyRandomList(Node* head) {
//         if(!head) return head;
//         if(!head->next) {
//             Node *a = new Node(head->val);
//             if(head->random) a->random = a;
//             return a;
//         }
        
//         unordered_map<Node*, Node*> um;
//         Node *temp = head;
//         Node *ans = new Node(-1);
//         Node *tans = ans;
//         while(temp){
//             Node *t = new Node(temp->val);
//             tans->next = t;
//             tans = t;
//             um[temp] = tans;
//             temp = temp->next;
//         }
//         temp = head;
//         tans = ans->next;
//         while(temp){
//             if(temp->random){
//                 tans->random = um[temp->random];
//             }
//             temp = temp->next;
//             tans = tans->next;
//         }
//         return ans->next;
            
            
        
//     }
};














    