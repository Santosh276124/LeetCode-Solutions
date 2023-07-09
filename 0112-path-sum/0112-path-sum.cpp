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
    bool solve(TreeNode* root, int targetSum){
         if(root == NULL) return false;
        
        targetSum -= root->val;
        
        if(root->left == NULL && root->right == NULL){
            if(targetSum == 0)
                return true;
            return false;
        }
        
        bool l = solve(root->left, targetSum);
        bool r = solve(root->right, targetSum);
        
        targetSum += root->val;
        
        return l||r;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
       return solve(root, targetSum);
    }
};