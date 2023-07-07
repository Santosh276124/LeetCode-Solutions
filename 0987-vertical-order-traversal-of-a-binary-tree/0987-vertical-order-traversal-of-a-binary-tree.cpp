

class Solution {
public:
    void solve(TreeNode* root, int r, int c, map<int, map<int,multiset<int> > >& mp){
        
        if(root == NULL) return;
        
        
        
        solve(root->left, r+1, c-1, mp);
        
        solve(root->right, r+1, c+1, mp);
        
        mp[c][r].insert(root->val);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, map<int,multiset<int> > > mp;
        
        solve(root, 0, 0, mp);
        
        vector<vector<int>> ans;
        
        for(auto i : mp){
            vector<int> temp;
            for(auto j : i.second){  
                for(auto k : j.second){
                    temp.push_back(k);
                } 
            }
            ans.push_back(temp);
            
        }
        
        return ans;
        
    }
};