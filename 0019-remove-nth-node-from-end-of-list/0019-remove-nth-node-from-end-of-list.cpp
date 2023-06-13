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
    ListNode* reverse(ListNode* head){
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr != NULL){
            ListNode* fr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fr;
        }
        
        return prev;
        
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* nhead = reverse(head);
        
        ListNode* dummy = new ListNode(-1);
        
        dummy->next = nhead;
        
        ListNode* prev = dummy; 
        ListNode* curr = nhead;
        
        while(n-- > 1){
            curr = curr->next;
            prev = prev->next;
        }
        
        prev->next = curr->next;
        curr->next = NULL;
        
        dummy->next = reverse(dummy->next);
        
        return dummy->next;
        
        
        
    }
};