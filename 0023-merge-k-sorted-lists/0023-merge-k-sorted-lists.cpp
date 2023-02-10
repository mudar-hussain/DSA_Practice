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
    class cmp{
        public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val>b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(auto l: lists){
            if(l != NULL)
                q.push(l);
        }
        if(q.empty())
            return NULL;
        ListNode *head = new ListNode(), *tail = head;
        
        while(!q.empty()){
            auto temp = q.top();
            q.pop();
            if(temp == NULL)
                continue;
            tail->next = temp;
            tail = tail->next;
            
            if(temp->next)
                q.push(temp->next);
        }
        return head->next;
    }
};












