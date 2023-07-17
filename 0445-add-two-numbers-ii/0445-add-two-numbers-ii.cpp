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
        
        ListNode* curr  = head;
        ListNode* prev = NULL;
        
        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
       ListNode* rhead1 = reverse(l1);
        
       ListNode* rhead2 = reverse(l2);
        
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        
        ListNode* c1 = rhead1;
        ListNode* c2 = rhead2;
        
        int carry = 0;
        while(c1!=NULL && c2 != NULL){
            int sum = c1->val + c2->val + carry;
            int dg = sum%10;
            carry = sum/10;
            
            dummy->next = new ListNode(dg);
            dummy = dummy->next;
            
            c1 = c1->next;
            c2 = c2->next;
        }
        
        while(c1!=NULL){
            int sum = c1->val + carry;
            int dg = sum%10;
            carry = sum/10;
            
            dummy->next = new ListNode(dg);
            dummy = dummy->next;
            
            c1 = c1->next;
        }
        
        while(c2 != NULL){
            int sum =  c2->val + carry;
            int dg = sum%10;
            carry = sum/10;
            
            dummy->next = new ListNode(dg);
            dummy = dummy->next;
      
            c2 = c2->next;
        }
        
        while(carry > 0){
            
            int dg = carry%10;
            carry = carry/10;
            
            dummy->next = new ListNode(dg);
            dummy = dummy->next;
     
        }
        
        
       ListNode* res =  reverse(ans->next);
        
        return res;
    }
};