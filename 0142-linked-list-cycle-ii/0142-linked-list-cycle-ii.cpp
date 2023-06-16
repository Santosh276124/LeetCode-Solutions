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
     ListNode* hasCycle(ListNode *head) {
        
        if(head == NULL) return NULL;
        
      ListNode* s = head;
        ListNode* f = head;
        
        while(f != NULL && f->next != NULL){
            s = s->next;
            f = f->next;
            if(f != NULL)
                f = f->next;
            
            if(s == f)
                return s;
        }
        
        return NULL;
        
    }
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* cycle = hasCycle(head);
        
        // cout<<cycle->val<<" ";
        
        if(cycle == NULL) return NULL;
        
        ListNode* f = cycle;
        ListNode* s = head;
        
        while(f != s){
            s = s->next;
            f = f->next;
        }
        
        return s;
        
    }
};