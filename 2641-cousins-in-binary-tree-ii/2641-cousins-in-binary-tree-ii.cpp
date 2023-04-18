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
    void updateTree(TreeNode* root, int sibSum, vector<int>& lvlSum, int lvl = 0){
        
        if(root==NULL) return;
        
        root->val = lvlSum[lvl] - sibSum;
        
        sibSum = (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
        
        
        updateTree(root->left, sibSum, lvlSum, lvl+1);
        
        updateTree(root->right, sibSum, lvlSum, lvl+1);
        
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        vector<int> lvlSum;
        
        int lvl = 0;
        
        while(!q.empty()){
            
            int len = q.size();
            
            lvlSum.resize(max(int(lvlSum.size()), lvl+1));
           
            
            int sum = 0;
            
            for(int i = 0; i < len; i++){
                auto front = q.front();
                q.pop();
                
                sum += front->val;
                
                if(front->left)
                    q.push(front->left);
                
                if(front->right)
                    q.push(front->right);
            }
            
            lvlSum[lvl] = sum;
            
            lvl++;
            
        }
        
        //update tree
        
        updateTree(root, root->val, lvlSum);
        
        return root;
        
        
    }
};