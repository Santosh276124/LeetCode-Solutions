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
    vector<string> ans;
    void dfs(TreeNode* root, string temp)
    {
        if(root == NULL)
            return;
        
        temp += (root->val + 'a');
        
        if(root->left == NULL && root->right == NULL){
            
            reverse(temp.begin(), temp.end());
            
            ans.push_back(temp);
            
            return;
        }
        
        dfs(root->left, temp);
        
        dfs(root->right, temp);
        
        
    }
    string smallestFromLeaf(TreeNode* root) {
        
        string temp = "";
        
        dfs(root, temp);
        
        string res = ans[0];
        
    
        for(int i = 1; i < ans.size(); i++)
        {
            if(ans[i] < res){
                res = ans[i];
            }
           
        }

        
        return res;
    }
};