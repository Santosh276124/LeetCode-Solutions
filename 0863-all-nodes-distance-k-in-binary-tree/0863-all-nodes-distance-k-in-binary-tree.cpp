/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, TreeNode* par,unordered_map<TreeNode*, TreeNode*> &back_edge )
    {
        
        if(root == NULL) return;
        
        back_edge[root] = par;
        
        dfs(root->left, root, back_edge);
        dfs(root->right, root, back_edge);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        //step1 make backedges
        unordered_map<TreeNode*, TreeNode*> back_edge;
        
        TreeNode* par = new TreeNode(-1);
        
        dfs(root, par, back_edge);
        
        // for(auto m : back_edge){
        //     // cout<<(m.first)->val<<"->"<<(m.second)->val<<"/ ";
        // }
    
        //step2 run bfs
        unordered_map<int,int> vis;
        queue<pair<TreeNode*, int>> q;
        
        q.push({target, 0});  //node, distance from tar
        
        vis[target->val] = 1;
        
        vector<int> ans;
        
        while(!q.empty()){
            
            int len = q.size();
            
            for(int i = 0; i < len; i++){
                
                auto front = q.front();
                q.pop();
                
                TreeNode* node = front.first;
                int dis = front.second;
                
                if(dis == k){
                    ans.push_back(node->val);
                }
                
                if(node->left && vis[node->left->val] == 0){
                    vis[node->left->val] = 1;
                    q.push({node->left, dis+1});
                }
                
                if(node->right && vis[node->right->val] == 0){
                    vis[node->right->val] = 1;
                    q.push({node->right, dis+1});
                }
                
                if((back_edge[node])->val != -1 && vis[back_edge[node]->val] == 0){
                    vis[back_edge[node]->val] = 1;
                    q.push({back_edge[node], dis+1});
                }
                
            }
            
        }
        
        // cout<<back_edge[root]->val<<" ";
        
        
        return ans;
    }
};