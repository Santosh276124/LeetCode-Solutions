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

    // vector<int> nums;
    int n;
    ListNode* head;
    Solution(ListNode* head) {
        // ListNode* curr = head;
        // while(curr != NULL)
        // {
        //     nums.push_back(curr->val);
        //     curr = curr->next;
        // }
        
        n = 0;
        this->head = head;
        ListNode* curr = head;
        while(curr != NULL)
        {
            n++;
            curr = curr->next;
        }
    
    }
    
    int getRandom() {
        
        // int n = nums.size();
        // int ind = rand()%n;
        // return nums[ind];
        
        int ind = rand()%n;
        ListNode* curr = head;
        while(ind--)
        {
            curr = curr->next;
        }
        
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */