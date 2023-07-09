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
   
    void solve(TreeNode* root, int &tar, vector<int> path, int &ans){
        
        if(root == NULL) return;
        
        path.push_back(root->val);
        // cout<<root->val<<" ";
        long long int curr = 0;
        for(int i = path.size()-1; i >= 0; i--){
            curr += path[i];
            if(curr == tar)
                ans++;
          
        }
        
        solve(root->left, tar, path, ans);
        solve(root->right, tar, path, ans);
        
        
        
        // path.pop_back();
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL) return 0;
        
        int ans = 0;
        vector<int> path;
        
        solve(root, targetSum, path, ans);

        return ans;
    }
};