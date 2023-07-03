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
     void postorder(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
   
        postorder(root->left, ans);
        postorder(root->right, ans);
        
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* curr= root;
        
        while(true){
            
            if(curr != NULL){
                
                ans.push_back(curr->val);
                st.push(curr);
                curr = curr->right;
                
            }
            else{
                
                if(st.empty()) break;
                
                curr = st.top();
                st.pop();
                curr=curr->left;
                
            }
            
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};