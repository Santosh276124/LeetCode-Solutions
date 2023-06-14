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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        
        while( curr1 != NULL && curr2 != NULL )
        {
            int sum = curr1->val + curr2->val + carry;
            int dg = sum%10;
            
            curr->next = new ListNode(dg);
      
             carry = sum/10;
            
            curr1 = curr1->next;
            curr2 = curr2->next;
            
            curr = curr->next;
   
        } 
        
        while(curr1 != NULL){
            int sum = curr1->val + carry;
            int dg = sum%10;
            
            curr->next = new ListNode(dg);
      
             carry = sum/10;
            
            curr1 = curr1->next;
            
            curr = curr->next;
        }
        while(curr2 != NULL){
            int sum = curr2->val + carry;
            int dg = sum%10;
            
            curr->next = new ListNode(dg);
      
             carry = sum/10;
            
            curr2 = curr2->next;
            
            curr = curr->next;
        }
        
        while(carry != 0){
            
            curr->next = new ListNode(carry);
      
             carry = carry/10;
            
            curr = curr->next;
        }
        
        return dummy->next;
    }
};