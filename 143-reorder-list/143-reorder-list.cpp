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
        ListNode *t = head;
        while(t){
            i++;
            t = t->next;
        }
        return i;
    }
    void reorderList(ListNode* head) {
        if(head == NULL) return;
        int n = len(head);
        if(n == 1 || n==2) return;
        int t = n/2+1;
        // cout<<n;
        ListNode* last = head, *cur = head;
        while(t--){
            last = last->next;
        }
        cout<<last->val;
        stack<ListNode*> s;
        while(last != NULL){
            s.push(last);
            last = last->next;
        }
        ListNode *temp;
        while(!s.empty()){
            temp = cur->next;
            cur->next = s.top();
            s.pop();
            cur = cur->next;
            cur->next = temp;
            cur = cur->next;
        }
        if(n%2==0)
            cur = cur->next;
        else 
            cur = cur->next->next;
        cur->next = NULL;
        return;
    }
};















