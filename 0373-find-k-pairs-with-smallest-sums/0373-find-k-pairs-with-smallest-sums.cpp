class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        int m = nums2.size();
            
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>> > pq;
        
        set<pair<int,int>> st;
        
        pq.push({nums1[0]+nums2[0], {0,0}});
        st.insert({0, 0});
        
        vector<vector<int>> ans;
        
        while(k-- && !pq.empty()){
            
            auto top = pq.top();
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            
            ans.push_back({nums1[i], nums2[j]});
            
            pq.pop();
            
            if(i+1 < n && st.find({i+1, j}) == st.end()){
                pq.push({nums1[i+1]+nums2[j], {i+1, j}});
                st.insert({i+1, j});
            }
            
            if(j+1 < m && st.find({i, j+1}) == st.end()){
                pq.push({nums1[i]+nums2[j+1], {i, j+1}});
                st.insert({i, j+1});
            }
     
            
        }
        
        return ans;
    }
};