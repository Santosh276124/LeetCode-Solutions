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
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        
        while(l1 != NULL)
        {
            temp->next = l1;
                temp = l1;
                l1 = l1->next;
        }
        while(l2 != NULL)
        {
            temp->next = l2;
                temp = l2;
                l2 = l2->next;
        }
        
        return ans->next;
    }
    ListNode* findMid(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast -> next;
            if(fast != NULL)
                fast = fast->next;
            
            prev = slow;
            slow = slow->next;
        }
        
        return prev;
    }
    ListNode* sortList(ListNode* head) {
        
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* middle = findMid(head);
        
        // cout<<middle->val<<" ";
        
        ListNode* l1 = head;
        ListNode* l2 = middle->next;
        middle->next = NULL;
        
        ListNode* left = sortList(l1);
        ListNode* right = sortList(l2);
        
        ListNode* ans = merge(left, right);
        
        return ans;
        
        // return NULL;
        
        
    }
};