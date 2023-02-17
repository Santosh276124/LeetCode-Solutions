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
public:
    int mini;
    void solve(TreeNode* root, int &prev)
    {
        if(root == NULL) return;
        
        solve(root->left, prev);
        
        if(prev != -1)
            mini = min(mini, abs(prev-root->val) );
        
        prev = root->val;
        
        solve(root->right, prev);
        
    }
    int minDiffInBST(TreeNode* root) {
        
         mini = 1e9;
        int pre = -1;
        
        solve(root, pre);
        
        return mini;
        
    }
};