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
        
        int n = 0;
        int m = 0;
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        
        while(curr1 != NULL)
        {
            n++;
            curr1 = curr1->next;
        }
        while(curr2 != NULL)
        {
            m++;
            curr2 = curr2->next;
        }
        
        curr1 = headA;
        curr2 = headB;
        
        if(n > m)
        {
            int k = n-m;
            while(k--)
            {
                curr1 = curr1->next;
            }
        }
        else{
            int k1 = m-n;
            while(k1--){
                curr2 = curr2->next;
            }
        }
        
        while(curr1 != NULL && curr2 != NULL)
        {
            if(curr1 == curr2)
                return curr1;
            
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        return NULL;
        
    }
};