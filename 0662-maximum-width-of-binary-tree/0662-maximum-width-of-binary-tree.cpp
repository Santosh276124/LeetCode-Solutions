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
        if(root == NULL) return 0;
        
        queue<pair<TreeNode*, long> > q;
        q.push({root, 1});
        
        long ans = 0;
        
        while(!q.empty()){
            
            int len = q.size();
            long mini=INT_MAX;
            long maxi = INT_MIN;
            
            for(int i = 0; i < len; i++){
                auto front = q.front();
                q.pop();
                TreeNode* node = front.first;
                long ind = front.second;
                
                mini = min(mini, ind);
                maxi = max(maxi, ind);
                
                ind = ind-mini;
                
                if(node->left) q.push({node->left, 2*ind});
                if(node->right) q.push({node->right, 2*ind+1});
                
                
            }
            
            
            ans = max(ans, maxi-mini+1);
            
        }
        
        return (int)ans;
    }
};