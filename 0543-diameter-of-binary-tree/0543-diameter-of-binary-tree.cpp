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
    int maxDepth(TreeNode* root) {
        
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        int leftDia = diameterOfBinaryTree(root->left);
        int rightDia = diameterOfBinaryTree(root->right);
        
        int curvePoint = maxDepth(root->left) + maxDepth(root->right);
        
        return max(leftDia, max(rightDia, curvePoint));
        
    }
};