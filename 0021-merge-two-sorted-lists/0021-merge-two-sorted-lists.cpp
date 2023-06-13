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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL) return list2;
      if(list2 == NULL) return list1;
        
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        
        if(curr1->val > curr2->val)
            swap(curr1, curr2);
        
        
        
        ListNode* res = curr1;
        
        while(curr1 != NULL && curr2 != NULL){
            
            ListNode* temp = NULL;
            
            while(curr1 != NULL && curr1->val <= curr2->val){
                temp = curr1;
                curr1 = curr1->next;
            }
            
            temp->next = curr2;
            swap(curr1, curr2);
            
        }
        
        return res;
        
    }
};