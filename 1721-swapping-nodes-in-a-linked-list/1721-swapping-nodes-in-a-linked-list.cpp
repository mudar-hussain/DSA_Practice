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
        int ans = 0;
        while(head){
            ans++;
            head = head->next;
        }
        return ans;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int n = len(head);
        
        if(n==1 || k>n) return head;
        ListNode *curr = head, *temp;
        if(k>n/2){
            k = n-k+1;
            // if(n%2) k++;
        }
        cout<<k;
        for(int i = 1; i<=n; i++){
            if(i == k){
                temp = curr;
            }
            else if(i == n-k+1) {
                int t = curr->val;
                curr->val = temp->val;
                temp->val = t;
                break;
            }
            curr = curr->next;
        }
            return head;
    }
};













