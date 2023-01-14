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
    int maxSum = INT_MIN;
    int solve(TreeNode* root)
    {
        if(!root) return 0;
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        // case1
        int neeche_hi_answer_mil_gya = l+r+root->val;
        
//         case2
        int dono_me_se_koi_ek_acha = max(l, r) + root->val;
        
//         case3
        int sirf_root_acha_hai = root->val;
        
        maxSum = max({maxSum, neeche_hi_answer_mil_gya, dono_me_se_koi_ek_acha, 
                     sirf_root_acha_hai});
        
//         case 1 ko return nhi kr sakte bc wo path complete hai aage nhi extend kr sakte
        return max(dono_me_se_koi_ek_acha, sirf_root_acha_hai);
        
    }
    int maxPathSum(TreeNode* root) {
        
        solve(root);
        return maxSum;
        
    }
};