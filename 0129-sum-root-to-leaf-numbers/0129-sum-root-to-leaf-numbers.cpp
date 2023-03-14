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
 
    
    int findNum(vector<int> &arr)
    {
        int num = 0;
        
        for(int i = 0; i < arr.size(); i++)
        {
            num = num * 10 + arr[i];
        }
        
        return num;
    }
    
    int ans = 0;
    void preOrder(TreeNode* root, vector<int> path)
    {
        
        if(root == NULL) return;
        
        path.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL){
            
            ans += findNum(path);
     
            
            return;
            
        }
  
        
        preOrder(root->left,path);
        
        preOrder(root->right, path);

        // path.pop_back();

       
    }
    int sumNumbers(TreeNode* root) {
         
        int num = 0;
    
        vector<int> path;
        preOrder(root, path);
        
        return ans;
        
    }
};