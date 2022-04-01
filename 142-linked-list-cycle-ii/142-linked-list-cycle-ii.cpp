/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        unordered_set<ListNode *> ht;
        ListNode *fast = new ListNode();
        fast = head;
        // ListNode *slow = fast;
        while(fast){
            if(ht.find(fast)!=ht.end()){
                return fast;
            }
            ht.insert(fast);
            fast = fast->next;
        }
        return NULL;
    }
    // ListNode *detectCycle(ListNode *head) {
    //     if(!head || !head->next) return NULL;
    //     ListNode *fast = new ListNode();
    //     fast->next = head;
    //     ListNode *slow = fast;
    //     while(fast && fast->next){
    //         if(fast==slow){
    //             fast = head;
    //         }
    //     }
    //     return NULL;
    // }
};