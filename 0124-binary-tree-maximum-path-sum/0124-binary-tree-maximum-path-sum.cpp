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
    int ans = -1e9;
    int solve(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        // if(root->left == NULL && root->right == NULL)
        //     return root->val;
        
        int l = solve(root->left);
        
        int r = solve(root->right);
        
        int curve_pathSum = l + r + root->val;
        
        int root_itself = root->val;
        
        int koi_ek = max(l, r)+root->val;
        
        ans = max({ans, curve_pathSum, root_itself, koi_ek});
        
        return max(root_itself, max(l, r)+root->val );
   
        
    }
    int maxPathSum(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        if(root->left == NULL && root->right == NULL)
            return root->val;
        
        int  val = solve(root);
        
        return ans;
        
    }
};