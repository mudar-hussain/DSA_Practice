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
    //Practice
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        else if(list2 == NULL)
            return list1;
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
                if(list1 == NULL) tail->next = list2;
            }else{
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
                if(list2 == NULL) tail->next = list1;
            }
        }
        return head->next;
        
    }
    
    //2md Approach
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     if(!list1) return list2;
    //     if(!list2) return list1;
    //     if(list1->val <= list2->val){
    //         list1->next = mergeTwoLists(list1->next,list2);
    //         return list1;
    //     }else{
    //         list2->next = mergeTwoLists(list1, list2->next);
    //         return list2;
    //     }
    // }
    //1st Approach
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     if(!list1) return list2;
    //     if(!list2) return list1;
    //     ListNode *tail;
    //     if(list1->val < list2->val){
    //         tail = list1;
    //         list1 = list1->next;
    //     }else{
    //         tail = list2;
    //         list2 = list2->next;
    //     }
    //     ListNode *ans = tail;
    //     while(list1 && list2){
    //         if(list1->val < list2->val){
    //             tail->next = list1;
    //             list1 = list1->next;   
    //         }else{
    //             tail->next = list2;
    //             list2 = list2->next; 
    //         }
    //         tail = tail->next;
    //     }
    //     if(list1) tail->next = list1;
    //     else  tail->next = list2;
    //     return ans;
    // }
};
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    