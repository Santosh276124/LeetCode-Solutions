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
    int tot = 0;
    int mod = 1e9+7;
public:
    // function to convert the tree into sum tree - this works in linear time
    int convert_To_SumTree(TreeNode* root) {
        if(root == NULL)    return 0;
        if(root->left == NULL and root->right == NULL)
            return root->val;
        int leftSum = convert_To_SumTree(root->left);
        int rightSum = convert_To_SumTree(root->right);
        
        root->val += leftSum+rightSum;
        return root->val;
    }
    void splitTree(TreeNode* root, long long& res) {
        if(root == NULL)
            return;
        
        // maximise sum from left
        if(root->left) {
            long long sum1 = root->left->val;
            long long sum2 = tot - sum1;
            long long curr = sum1*sum2;
            if(curr > res)
                res = curr;
        }
        
        // maximise sum from right
        if(root->right) {
            long long sum1 = root->right->val;
            long long sum2 = tot - sum1;
            long long curr = sum1*sum2;
            if(curr > res)
                res = curr;
        }
        
        // call  for left and right
        splitTree(root->left, res);
        splitTree(root->right, res);
    }
    int maxProduct(TreeNode* root) {
        // convert the tree into sum tree
        // so that each node stores the sum of its
        // left and right subtrees
        tot = convert_To_SumTree(root);
        
        if(tot == 0)    return 0;
        
        // now try to split at every location 
        // and get the maximum ans
        long long res = 0;
        splitTree(root, res);
        return res%mod;
    }
};