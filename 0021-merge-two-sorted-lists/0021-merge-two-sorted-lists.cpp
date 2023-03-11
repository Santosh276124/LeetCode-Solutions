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
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        if(list1->next == NULL){
            list1->next = list2;
            return list1;
        }
        
        ListNode* c1 = list1;
        ListNode* c2 = list2;
        ListNode* n1 = c1->next;
        ListNode* n2 = c2->next;
        
        while(n1 != NULL && c2 != NULL)
        {
            if(c2 -> val >= c1 -> val && c2->val <= n1->val)
            {
                c1->next = c2;
                n2 = c2->next;
                c2->next = n1;
                c1 = c2;
                c2 = n2;
            }
            else
            {
                c1 = n1;
                n1 = n1->next;
                if(n1 == NULL)
                {
                    c1->next = c2;
                    return list1;
                }
            }
        }
        return list1;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        if(list1->val <= list2->val)
        {
            ListNode* ans = merge(list1, list2);
            return ans;
        }
        else{
            ListNode* ans = merge(list2, list1);
            return ans;
        }
        
      
    }
};