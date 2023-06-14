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
 
    
    int inorder(TreeNode* root, int &prev, int &ans){
        if(root == NULL)
            return 0;
        
        int l  = inorder(root->left, prev, ans);
        
        // if(prev != -1)
            ans = min(ans, abs(root->val-prev));
        // else ans = min(ans, root->val);
        
        prev = root->val;
        
        int r = inorder(root->right, prev, ans);
        
        return ans;
        
    }
    int getMinimumDifference(TreeNode* root) {
        
        int prev  = INT_MAX;
        
        int ans = INT_MAX;
        
       return  inorder(root, prev, ans);
       
        
    }
};