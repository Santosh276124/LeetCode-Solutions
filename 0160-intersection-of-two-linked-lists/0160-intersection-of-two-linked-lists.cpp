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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == headB) return headA;
        
        ListNode* curr1 = headA;
    
        
        while(curr1 != NULL)
        {
            ListNode* curr2 = headB;
            while(curr2 != NULL)
            {
                if(curr2 == curr1)
                    return curr2;
                
                curr2 = curr2->next;
                
            }
            
            curr1 = curr1->next;
        }
        
        return NULL;
    }
};