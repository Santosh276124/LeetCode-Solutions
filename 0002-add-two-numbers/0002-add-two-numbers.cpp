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
    void insertAtTail(ListNode* &tail, int data)
    {
        ListNode* temp = new ListNode(data);
        
        tail->next = temp;
        tail = temp;
  
    }
    ListNode* findSum(ListNode* l1, ListNode* l2)
    {
        int carry = 0;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        
        while(curr1 != NULL || curr2 != NULL || carry != 0)
        {
            int sum = 0;
            
            if(curr1 != NULL){
                sum += curr1->val;
                curr1 = curr1->next;
            }
            if(curr2 != NULL){
                sum += curr2->val;
                curr2 = curr2->next;
            }
            
            sum += carry;
            
            int digit = sum%10;
            
            carry = sum/10;
            
            insertAtTail(temp, digit);
             
        }
        
        return dummy->next;
    }
    ListNode* reverse(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL)
        {
            ListNode* fr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fr;
        }
        
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        
        ListNode* ans = findSum(l1, l2);
        
        
        return ans;
        
    }
};