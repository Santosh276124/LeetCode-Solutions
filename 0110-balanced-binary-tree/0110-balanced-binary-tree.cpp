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
    int height(TreeNode* root){
        if(root == NULL) return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL) return true;
        
        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);
        
        bool val = abs( height(root->left)-height(root->right) ) <= 1; 
        
        return l && r && val;
            
    }
};