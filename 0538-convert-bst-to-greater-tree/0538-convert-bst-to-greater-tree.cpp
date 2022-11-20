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
   
    void inorder(TreeNode* root, vector<int> &temp)
    {
        if(root == NULL) return;
        
        inorder(root->left, temp);
        temp.push_back(root->val);
        inorder(root->right, temp);
    }
   
    void inorderToTree(TreeNode* root, unordered_map<int,int> &m)
    {
        if(root == NULL) return;
        
        if(m.count(root->val)) root->val = m[root->val];
        
        inorderToTree(root->left, m);
        inorderToTree(root->right, m);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        
        if(root==NULL || (root->left == NULL && root->right == NULL)) return root;
        vector<int> temp;
        inorder(root, temp);
        
        
        unordered_map<int,int> m;
         int sum = 0;
        for(int i = temp.size()-1; i >= 0; i--)
        {
            sum += temp[i];
            
            m[temp[i]] = sum;
            
        }
        
        
        inorderToTree(root, m);
        
        return root;
        
        
    }
};