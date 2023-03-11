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
        
        ListNode* ans = new ListNode(-1);
        
        ListNode* c1 = list1;
        ListNode* c2 = list2;
        ListNode* temp = ans;
        
        while(c1 != NULL && c2 != NULL)
        {
            if(c1->val <= c2->val)
            {
                temp->next = new ListNode(c1->val);
                c1 = c1->next;
                temp = temp->next;
            }
            else{
                temp->next = new ListNode(c2->val);
                c2 = c2->next;
                temp = temp->next;
            }
        }
        
        while(c1 != NULL)
        {
            temp->next = new ListNode(c1->val);
            c1 = c1->next;
            temp = temp->next;
        }
        while(c2 != NULL)
        {
            temp->next = new ListNode(c2->val);
            c2 = c2->next;
            temp = temp->next;
        }
        
        return ans->next;
    }
};