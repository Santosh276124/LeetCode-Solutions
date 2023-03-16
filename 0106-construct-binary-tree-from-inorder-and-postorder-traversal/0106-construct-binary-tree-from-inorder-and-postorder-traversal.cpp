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
    TreeNode* solve(int &rootInd, int inStart, int inEnd, vector<int>& in, vector<int>& post, unordered_map<int,int>& mp){
        if(rootInd < 0 || inEnd < inStart)
            return NULL;
        
        int rootVal = post[rootInd--];
        
        int rootPos = mp[rootVal];
        
        TreeNode* root = new TreeNode(rootVal);  
        
        root->right = solve(rootInd, rootPos+1, inEnd, in, post, mp);
        
        root->left = solve(rootInd, inStart, rootPos-1, in, post, mp);
        
       
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        
        unordered_map<int,int> mp;
        
        for(int i = 0; i < in.size(); i++)
        {
            mp[in[i]] = i;
        }
        int n = post.size();
        
        int rootInd = n-1;
        
        TreeNode* ans = solve(rootInd, 0, n-1, in, post, mp);
        
        return ans;
    }
};