/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
public:
    //2nd Approach
    
    int length(ListNode *head){
        int l = 0;
        while(head != NULL){
            head = head->next;
            l++;
        }
        return l;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL ) return head;
        int len = length(head);
        
        ListNode *dummy = new ListNode();
        dummy->next = head;
        
        ListNode *prev = dummy;
        ListNode *curr, *nex;
        while(len>=k){
            curr = prev->next;
            nex = curr->next;
            for(int i = 1; i<k; i++){
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev = curr;
            len -= k;
        }
        return dummy->next;
        
        
    }
    
    //1st Approach
//     ListNode* reverse(ListNode* s, ListNode* e){
//         ListNode *p = NULL, *c = s, *n = s->next;
//         while(p!=e){
//             c->next = p;
//             p = c;
//             c = n;
//             if(n!=NULL) n = n->next;
//         }
//         return p;
//     }
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(head == NULL || head->next == NULL || k == 1) return head;
//         ListNode *dummy = new ListNode(-1);
//         dummy->next = head;
//         ListNode *beforeStart = dummy, *e = head;
//         int i = 0;
//         while(e!=NULL){
            
//             i++;
//             if(i%k == 0){
//                 ListNode *s = beforeStart->next, *afterEnd = e->next;
//                 reverse(s,e);
//                 beforeStart->next = e;
//                 s->next = afterEnd;
//                 beforeStart = s;
//                 e = s->next;
                
//             }else{
//                 e = e->next;
//             }
            
            
//         }
//         return dummy->next;
//     }
};













