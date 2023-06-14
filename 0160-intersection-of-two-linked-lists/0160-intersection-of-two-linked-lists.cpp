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
    int findLength(ListNode* head){
        if(head == NULL)
            return 0;
        
        int n = 0;
        ListNode* curr  = head;
        
        while(curr != NULL){
            n++;
            curr = curr->next;
        }
        return n;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* curr1 = headA;
       ListNode* curr2 = headB;
        
        int n1 = findLength(headA);
        int n2 = findLength(headB);
        
        
        int n = abs(n1-n2);
        
        if(n1 > n2){
            while(n--){
                curr1 = curr1->next;
            }
        }
        else{
            while(n--){
                 curr2 = curr2->next;
            }
        }
    
        
        
        while(curr1 != NULL && curr2 != NULL){
            
            if(curr1 == curr2) return curr1;
            
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
     
      
        

        
        return NULL;
        
    }
};