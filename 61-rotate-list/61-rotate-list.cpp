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
    int len(ListNode *head){
        int i = 0;
        
        while(head){
            i++;
            head = head->next;
        }
        return i;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int size = len(head);
        k = size==0? k:k%size;
        if(k==0 || k==size || !head || !head->next) return head;
        
        
        int i = 0;
        ListNode *prev = head;
        while(prev && i<size-k-1){
            prev = prev->next;
            i++;
        }
        ListNode *h = prev->next;
        prev->next = NULL;
        prev = h;
        while(prev->next) prev = prev->next;
        prev->next = head;
        return h;
    }
};










