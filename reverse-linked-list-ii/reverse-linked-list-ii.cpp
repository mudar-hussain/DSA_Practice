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
    ListNode* reverse(ListNode* s, ListNode* e){
        ListNode* p = NULL, *c = s, *n = s->next;
        while(p!=e){
            c->next = p;
            p = c;
            c = n;
            if(n!=NULL) n = n->next;
        }
        return p;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL|| left==right ) return head;
        ListNode* beforeStart = new ListNode(-1), *temp = head;
        beforeStart->next = head;
        right = right-left;
        int i;
        if(left==1)  i = 1;
        else  i = 0;
        left--;
        while(left--){
            beforeStart = beforeStart->next;
            if(beforeStart==NULL) return head;
        }
        ListNode *s=beforeStart->next, *e = s;
        
        while(right--){
            e = e->next;
            if(e == NULL) return head;
        }
        ListNode *afterEnd = e->next;
        cout<<s->val<<e->val;
        e = reverse(s,e);
        beforeStart->next = e;
        s->next = afterEnd;
        return i? e:head; 
    }
};














