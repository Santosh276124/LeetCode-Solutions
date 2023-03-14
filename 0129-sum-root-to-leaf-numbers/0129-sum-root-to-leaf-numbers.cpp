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
    // vector<int> path;
    
//     int findNum(vector<int> &arr)
//     {
//         int num = 0;
        
//         for(int i = 0; i < arr.size(); i++)
//         {
//             num = num * 10 + arr[i];
//         }
        
//         return num;
//     }
    
    int ans = 0;
    void preOrder(TreeNode* root, int num)
    {
        
        if(root == NULL) return;
        
        num = num*10 + root->val;
        
        if(root->left == NULL && root->right == NULL){
            
            ans += num;
     
            
            return;
            
        }
  
        
        preOrder(root->left,num);
        
        preOrder(root->right, num);

        // path.pop_back();

       
    }
    int sumNumbers(TreeNode* root) {
         
        int num = 0;
    
        
        preOrder(root, num);
        
        return ans;
        
    }
};