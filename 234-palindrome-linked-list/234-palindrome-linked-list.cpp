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
            head = head->next;
            i++;
        }
        return i;
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        int n = len(head);
        int i = 0;
        stack<int> s;
        while(i<n/2){
            s.push(head->val);
            head = head->next;
            i++;
        }
        // i--;
        if(n%2) {
            head = head->next;
            i++;
        }
        while(i<n){
            if(head->val != s.top()) return false;
            s.pop();
            head = head->next;
            i++;
        }
        return true;
        
    }
};








