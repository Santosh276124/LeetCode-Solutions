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
    ListNode* rotateRight(ListNode* head, int k) {
        
     
        if(head == NULL || k == 0) return head;
        
//         step1 find length
        int len = 0;
        
        ListNode* curr = head, *prev = head;
        while(curr != NULL)
        {
            len++;
            prev = curr;
            curr = curr->next;
        }
        
        if(len == k) return head;
        
        // step2
        if(k > len )
            k = k%len;
        
        
        curr = head;
        
        // step3
        //make it circular
        prev->next = head;
        
        
//         step4 iterate for n
        int n = len-k;
        
        while(n-- > 1)
        {
            curr = curr->next;
        }
        
//         step5
        head = curr->next;
        curr->next = NULL;
        
        return head;
        
        
    }
};