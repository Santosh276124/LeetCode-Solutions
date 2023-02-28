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
    bool isSame(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL) return true;
        
        if(root1 == NULL || root2 == NULL) return false;
        
        bool l = isSame(root1->left, root2->left);
        bool r = isSame(root1->right, root2->right);
        
        bool val = (root1->val==root2->val);
        
        return (l && r) && val;
    }
    void solve(TreeNode* root1, TreeNode* root2, set<TreeNode*>& ans, unordered_map<TreeNode*, bool>& mp)
    {
        if(mp[root1] || mp[root2]) return;
        if(root1 == NULL || root2 == NULL) return;
        
        
        TreeNode* c1 = root1;
        TreeNode* c2 = root2;
        
        if(root1->val == root2->val && isSame(c1, c2))
        {
            ans.insert(root1);
            mp[root1] = true;
            mp[root2] = true;
            // return;
        }
        
        solve(root1 , root2->left, ans, mp);
        solve(root1, root2->right, ans, mp);
        solve(root1->left, root2, ans, mp);
        solve(root1->right, root2, ans, mp);
    }
    string dfs(TreeNode* root,  unordered_map<string,int>& vis, vector<TreeNode*>& ans)
    {
        if(root==NULL) return "N";
        string temp = to_string(root->val) + "," + dfs(root->left, vis, ans) + "," + dfs(root->right, vis, ans);
        

        if(vis[temp] == 1)
            ans.push_back(root);
        
        vis[temp]++;
        
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
//         set<TreeNode*> ans;
//         unordered_map<TreeNode*, bool> mp;
        
//         solve(root->left, root->right, ans, mp);
        
//         vector<TreeNode*> res;
        
//         for(auto s : ans)
//         {
//             res.push_back(s);
//         }
        
        unordered_map<string,int> vis;
        vector<TreeNode*> ans;
        
        dfs(root, vis, ans);
        
        return ans;
    }
};