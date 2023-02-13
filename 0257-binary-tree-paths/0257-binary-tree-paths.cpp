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
    vector<string> ans;
    void solve(TreeNode* root, string s)
    {
        if(root == NULL) return;
        
        s += to_string(root->val);
        s += "->";
        
        if(root->left == NULL && root -> right == NULL)
        {
            s.pop_back();
            s.pop_back();
            
            ans.push_back(s);
            
            return;
        }
        
        solve(root->left, s);
        solve(root->right, s);
        
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        string s = "";
        solve(root, s);
        return ans;
    }
};