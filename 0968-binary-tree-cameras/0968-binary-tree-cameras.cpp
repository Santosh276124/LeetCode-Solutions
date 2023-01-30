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
    int cam =0;
    string postOrder(TreeNode* root)
    {
        if(root == NULL) return "ok";
        
        string l = postOrder(root->left);
        string r = postOrder(root->right);
        
        if(l == "want" || r == "want")
        {
            cam++;
            return "provide";
        }
        else if(l == "provide" || r == "provide")
        {
            return "ok";
        }
        
        return "want";
        
    }
    int minCameraCover(TreeNode* root) {
        
        if(postOrder(root) == "want")
            cam++;
        
        return cam;
    }
};