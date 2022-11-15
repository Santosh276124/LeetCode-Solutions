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
    void preorder(TreeNode* root, int &cnt)
    {
        if(root == NULL) return;
        
        // if(root->left == NULL && root->right == NULL) return;
        
        cnt++;
        
        preorder(root->left, cnt);
        
        preorder(root->right, cnt);
        
        return;
    }
public:
    int countNodes(TreeNode* root) {
        
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        
        int cnt = 0;
        preorder(root, cnt);
        return cnt;
    }
};