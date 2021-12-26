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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *t1 = NULL, *t2 = head, *t3 = head->next;
        while(t2 != NULL){
            t2->next = t1;
            t1 = t2;
            t2 = t3;
            if(t3 != NULL) t3 = t3->next;
            
        }
        return t1;
    }
};