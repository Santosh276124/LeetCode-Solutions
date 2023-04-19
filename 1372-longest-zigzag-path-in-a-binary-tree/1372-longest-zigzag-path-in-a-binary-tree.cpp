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
    int maxLen = 0;
    void solve(TreeNode* root, int l, int r){
        
        if(root == NULL) return;
        
        maxLen = max(maxLen, max(l, r));
        
        solve(root->left, r+1, 0);
        
        solve(root->right, 0, l+1);
        
    }
    int longestZigZag(TreeNode* root) {
        
        solve(root, 0, 0);
        
        return maxLen;
        
    }
};