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
    int widthOfBinaryTree(TreeNode* root) {
        
        long ans = 0;
        
        queue<pair<TreeNode* , long> > q;
        
        q.push({root, 0}); //0 -based indexing
        
        while(!q.empty())
        {
            int len = q.size();
            long maxi = INT_MIN;
            long mini = INT_MAX;
            
            for(int i = 0; i < len; i++)
            {
                auto front = q.front();
                q.pop();
                
                long ind = front.second;
                TreeNode* node = front.first;
                
                maxi = max(maxi, ind);
                mini = min(mini, ind);
                
                ind = ind-mini;
                
                if(node->left) q.push({node->left,  2*ind+1});
                if(node->right) q.push({node->right, 2*ind+2});
            }
            
            ans = max(ans, maxi-mini+1);
        }
        return ans;
        
    }
};