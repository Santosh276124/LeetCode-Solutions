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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void copyNodes(ListNode* head, vector<int> &ans)
    {
       ListNode* temp = head;
        while(temp != NULL)
        {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        
        
    }
    
    TreeNode* solve(int s, int e, vector<int> &ans)
    {
        if(s>e) return NULL;
        
        int mid = (s+e)/2;
        
        TreeNode* root = new TreeNode(ans[mid]);
        
        root->left = solve(s, mid-1, ans);
        root->right = solve(mid+1, e, ans);
        
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        
        if(head == NULL) return NULL;
        
        vector<int> ans;
        
        copyNodes(head, ans);
        
       return solve(0, ans.size()-1, ans);
        
        
    }
};