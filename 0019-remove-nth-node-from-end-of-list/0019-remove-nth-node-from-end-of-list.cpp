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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return NULL;
        if(n == 1 && head->next == NULL)
            return NULL;
        if(head->next && head->next->next == NULL){
            if(n == 1){
                head->next = NULL;
                return head;
            }
            if(n == 2){
                return head->next;
            }
            
        }
        ListNode* prev = head, *cur = head->next, *nxt = head->next;
        n-=1;
        while(n--){
            nxt = nxt->next;
        }
        if(nxt == NULL)
            return head->next;
        while(nxt->next){
            prev = prev->next;
            cur = cur->next;
            nxt = nxt->next;
        }
        prev->next = cur->next;
        return head;
    }
};









