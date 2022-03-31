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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1 = headA, *l2 = headB;
        while(l1 != l2){
            // if(l1 == l2) return l1;
            l1 = !l1? headB:l1->next;
            l2 = !l2? headA:l2->next;
        }
        
        return l1;
    }
    //1st Approach
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* fast, *slow;
//         ListNode* cal = headA;
//         int l1 = 0, l2 = 0;
//         while(cal){
//             cal = cal->next;
//             l1++;
//         }
//         cal = headB;
//         while(cal){
//             cal = cal->next;
//             l2++;
//         }
//         int diff = abs(l1-l2);
//         if(l1>l2) {
//             fast = headA;
//             slow = headB;
//         }else{
//             fast = headB;
//             slow = headA;
//         }
//         while(diff--) fast = fast->next;
//         while(fast  && slow){
//             if(fast==slow) return fast;
//             fast = fast->next;
//             slow = slow->next;
            
//         }
//         return NULL;
//     }
};