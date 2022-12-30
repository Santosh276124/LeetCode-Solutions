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
//     bool isValid(TreeNode* root)
//     {
        
//     }
public:
    bool isUnivalTree(TreeNode* root) {
        
      // return isValid(root);
        if(root == NULL) return true;
        
        bool left = isUnivalTree(root->left);
        bool right = isUnivalTree(root->right);
        
//         case which will return false
//         1
        if(left == false || right == false)
            return false;
//         2
        if(root->left && root->val != root->left->val)
            return false;
//         3
        if(root->right && root->val != root->right->val)
            return false;
        
//         rest cases
        return true;
    }
};