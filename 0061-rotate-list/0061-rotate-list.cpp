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
        
        if(head == NULL || head->next == NULL) return head;
        
        int n = 0;
        ListNode* curr = head;
        while(curr != NULL){
            n++;
            curr = curr->next;
        }
        
        if(n == k || k == 0 || k%n == 0) return head;
        
        k = k%n;  //if k > n
        
        k = n-k; //to move pointer
        k--;
        
        ListNode* temp = head;
    
        while(k--){
            temp = temp->next;
        }
        
        ListNode* nhead = temp->next;
        
        temp->next = NULL;
        
        curr = nhead;
        while(curr->next != NULL)
            curr = curr->next;
        
        curr->next = head;
        
        return nhead;
        
        
        
    }
};