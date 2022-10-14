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
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode* curr = head;
        int n = 0;
        while(curr != NULL)
        {
            n++;
            curr = curr->next;
        }
        
        int mid = n/2;
        
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        curr = head;
        ListNode* prev = dummy;
        
        while(mid--)
        {
            curr = curr->next;
            prev = prev->next;
        }
        
        prev->next = curr->next;
        delete(curr);
        
        return dummy->next;
        
    }
};