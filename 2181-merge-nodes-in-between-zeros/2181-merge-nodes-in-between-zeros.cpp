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
    ListNode* mergeNodes(ListNode* head) {
        int currSum = 0;
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        while(head){
            if(head->val == 0 && currSum != 0){
                curr->next = new ListNode(currSum);
                currSum = 0;
                curr = curr->next;
            }
            currSum += head->val;
            head = head->next;
        }
        return dummy->next;
    }
};