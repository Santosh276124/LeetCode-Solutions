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
    ListNode* findMid(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* s = head;
        ListNode* f = head->next;
        
        while(f != NULL && f->next != NULL){
            s = s->next;
            f = f->next;
            if(f != NULL)
                f = f->next;
        }
        return s;
    }
    
    ListNode* reverse(ListNode* head){
         if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* curr =head;
        ListNode* fr = NULL;
        ListNode* prev = NULL;
        
        while(curr != NULL){
            fr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fr;
        }
        
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode* mid = findMid(head);
        
        ListNode* rhead = reverse(mid->next);
        
        ListNode* curr2 = rhead;
        ListNode* curr1 = head;
        
        while(curr2 != NULL){
            if(curr1->val != curr2->val)
                return false;
            
            curr2 = curr2->next;
            curr1 = curr1->next;
        }
        return true;
        
    }
};