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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        int lvl = 1;
        int maxSum = INT_MIN;
        
        int ans = 1;
        
        while(!q.empty()){
            
            int len = q.size();
            
            int lvlSum = 0;
            
            for(int i = 0; i < len; i++){
                auto node = q.front();
                q.pop();
                
                lvlSum += node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }
            
            if(lvlSum > maxSum){
                maxSum = lvlSum;
                ans = lvl;
            }
            
            lvl++;
            
        }
        
        return ans;
        
    }
};