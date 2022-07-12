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
    //Approach 2
    ListNode* reverseList(ListNode *head){
        ListNode *prev = NULL, *cur = head, *nxt = head;
        while(nxt != NULL){
            nxt = nxt->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    ListNode* findMid(ListNode *head){
        ListNode *fast = head, *slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    void merge(ListNode *l1, ListNode *l2){
        ListNode *cur = l1;
        l1 = l1->next;
        bool f = false;
        while(l1 && l2){
            if(f){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
            f = !f;
        }
        if(l1){
            cur->next = l1;
        }else{
            cur->next = l2;
        }
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode *l1 = head, *mid = findMid(head);
        ListNode *l2 = reverseList(mid->next);
        mid->next = NULL;
        merge(l1, l2);
        return;
        
        
    }
    //Approach 1
    // int len(ListNode *head){
    //     int i = 0;
    //     ListNode *t = head;
    //     while(t){
    //         i++;
    //         t = t->next;
    //     }
    //     return i;
    // }
    // void reorderList(ListNode* head) {
    //     if(head == NULL) return;
    //     int n = len(head);
    //     if(n == 1 || n==2) return;
    //     int t = n/2+1;
    //     // cout<<n;
    //     ListNode* last = head, *cur = head;
    //     while(t--){
    //         last = last->next;
    //     }
    //     cout<<last->val;
    //     stack<ListNode*> s;
    //     while(last != NULL){
    //         s.push(last);
    //         last = last->next;
    //     }
    //     ListNode *temp;
    //     while(!s.empty()){
    //         temp = cur->next;
    //         cur->next = s.top();
    //         s.pop();
    //         cur = cur->next;
    //         cur->next = temp;
    //         cur = cur->next;
    //     }
    //     if(n%2==0)
    //         cur = cur->next;
    //     else 
    //         cur = cur->next->next;
    //     cur->next = NULL;
    //     return;
    // }
};















