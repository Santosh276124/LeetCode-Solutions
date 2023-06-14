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
    void deleteNode(ListNode* node) {
        
        ListNode* curr = node;
        ListNode* fr = node->next;
        
       
        
        while(fr->next != NULL){
            
            swap(curr->val, fr->val);
            
            fr = fr->next;
            curr = curr->next;
            
        }
        
        swap(curr->val, fr->val);
        
        curr->next = NULL;
        
        return;
        
    }
};