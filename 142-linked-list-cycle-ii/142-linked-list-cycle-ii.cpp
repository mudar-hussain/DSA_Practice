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
    //2nd Approach
    // ListNode *detectCycle(ListNode *head) {
    //     if(!head || !head->next) return NULL;
    //     unordered_set<ListNode *> ht;
    //     ListNode *fast = new ListNode();
    //     fast = head;
    //     while(fast){
    //         if(ht.find(fast)!=ht.end()){
    //             return fast;
    //         }
    //         ht.insert(fast);
    //         fast = fast->next;
    //     }
    //     return NULL;
    // }
    
    //1st Approach
    
    ListNode *detectCycle(ListNode *head) {
        // if(!head || !head->next) return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        bool flag = false;
        while(fast && fast->next){
            
            slow = slow->next;
            if(flag) fast = fast->next;
            else fast = fast->next->next;
            if(flag && fast == slow) return fast;
            else if(fast==slow){
                fast = head;
                flag = true;
                if(fast == slow) return fast;
            }
        }
        return NULL;
    }
};