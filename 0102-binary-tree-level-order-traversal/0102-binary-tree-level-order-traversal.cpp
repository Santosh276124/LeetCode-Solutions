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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(root == NULL) return ans;
        
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()){
            int len = q.size();
            vector<int> temp;
            for(int i = 0; i < len; i++){
                auto front = q.front();
                q.pop();
                temp.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(temp.size() > 0)
                ans.push_back(temp);
        }
        
        return ans;
    }
};