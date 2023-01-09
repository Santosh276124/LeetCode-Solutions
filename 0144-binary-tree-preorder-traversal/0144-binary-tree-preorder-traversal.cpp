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
    
    void solve(TreeNode* root, vector<int> &ans)
    {
        
        if(root == NULL)
           return;
           
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* curr = root;
        
        while(!s.empty())
        {
            if(curr != NULL)
            {
                ans.push_back(curr->val);
                if(curr->right)
                {
                    s.push(curr->right);
                }
                curr = curr->left;
            }
            else
            {
                curr = s.top();
                s.pop();
            }
        }
        
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        
        solve(root, ans);
        
        return ans;
    }
};