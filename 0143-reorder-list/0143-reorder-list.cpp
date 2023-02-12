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
    ListNode* findMid(ListNode* head){
        ListNode* fast = head, *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL, *cur = head, *nxt = head;    
        while(nxt){
            nxt = nxt->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    
    void merge(ListNode* l1, ListNode* l2){
        ListNode *cur = l1;
        l1 = l1->next;
        while(l1 && l2){
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        while(l1){
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        while(l2){
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
    }
    
public:
    void reorderList(ListNode* head) {
        if(head == NULL || (head && head->next == NULL) || (head && head->next && head->next == NULL))
            return;
        
        ListNode* l1 = head, *mid = findMid(head);
        ListNode* l2 = reverse(mid->next);
        mid->next= NULL;
        merge(l1,l2);
    }
};














