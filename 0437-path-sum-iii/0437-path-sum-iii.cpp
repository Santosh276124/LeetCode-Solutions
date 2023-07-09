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
   unordered_map<long long int,int> mp;
    void solve(TreeNode* root, int &tar, long long int currSum, int &ans){
        
        if(root == NULL) return;
        
        // path.push_back(root->val);
        currSum += root->val;
        if(currSum == tar)
            ans++;
        
        if(mp.count(currSum - tar))
            ans += mp[currSum-tar];
        
        mp[currSum]++;

        
        solve(root->left, tar, currSum, ans);
        solve(root->right, tar, currSum, ans);
        
        mp[currSum]--;
        
        // path.pop_back();
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL) return 0;
        
        int ans = 0;
        // vector<int> path;
        long long int curr = 0;
        solve(root, targetSum, curr, ans);

        return ans;
    }
};