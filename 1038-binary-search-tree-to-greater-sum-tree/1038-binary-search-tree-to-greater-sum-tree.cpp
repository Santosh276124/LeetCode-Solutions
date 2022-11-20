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
    int currSum = 0;
    void inorderSum(TreeNode* root)
    {
        if(root == NULL)
            return;
       
        inorderSum(root->right); 
        currSum += root->val;
        root->val = currSum;
        inorderSum(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
     
        inorderSum(root);
        return root;
    }
};