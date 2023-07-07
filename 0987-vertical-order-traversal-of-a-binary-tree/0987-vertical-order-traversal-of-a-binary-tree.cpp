

class Solution {
public:
    void solve(TreeNode* root, int r, int c, map<int, map<int,vector<int> > >& mp){
        
        if(root == NULL) return;
        
        
        
        solve(root->left, r+1, c-1, mp);
        
        solve(root->right, r+1, c+1, mp);
        
        mp[c][r].push_back(root->val);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, map<int,vector<int> > > mp;
        
        solve(root, 0, 0, mp);
        
        vector<vector<int>> ans;
        
        for(auto i : mp){
          // cout<<i.first<<":";
            vector<int> temp;
            for(auto j : i.second){  
                // cout<<j.first<<"->";
                vector<int> temp1;
                for(auto k : j.second){
                    // cout<<k<<" ";
                    temp1.push_back(k);
                } 
                
                sort(temp1.begin(), temp1.end());
                for(auto el : temp1)
                    temp.push_back(el);
                // cout<<endl;
                // sort(temp.begin(), temp.end());
            }
            // cout<<endl;
            
            ans.push_back(temp);
            
        }
        
        return ans;
        
    }
};