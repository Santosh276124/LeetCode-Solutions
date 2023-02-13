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
    void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int len = q.size();
            for(int i = 0; i < len; i++)
            {
                auto front = q.front();
                q.pop();
                
                if(front->left){
                    parent[front->left] = front;
                    q.push(front->left);
                }
                if(front->right){
                    parent[front->right] = front;
                    q.push(front->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* tarRef, int k) {
        
        
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = NULL;
       
        findParent(root, parent);
        
        // step 3  BFS in all direction
        unordered_map<TreeNode*, bool> vis;
        
        queue<TreeNode*> q;
        
        q.push(tarRef);
        vis[tarRef] = true;
        
        int cnt = 0;
        while(!q.empty())
        {
            int len = q.size();
            
            if(cnt++ == k) break;
            
            for(int i = 0; i < len; i++)
            {
                auto node = q.front();
                q.pop();
                
                if(node->left && vis[node->left] == false)
                {
                    vis[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && vis[node->right] == false)
                {
                    vis[node->right] = true;
                    q.push(node->right);
                }
                if(parent[node] && vis[parent[node]] == false)
                {
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
  
        }
        
        vector<int> ans;
        
        while(!q.empty())
        {
            int val = q.front()->val;
             q.pop();
             
            ans.push_back(val);
           
        }
        
        return ans;
    }
};