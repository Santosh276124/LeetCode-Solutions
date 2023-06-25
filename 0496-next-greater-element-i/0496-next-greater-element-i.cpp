class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        unordered_map<int,int> next_grt_el;
        
        stack<int> st;
        st.push(-1);
        
        for(int i = m-1; i >= 0; i--){
            
            while(st.top() != -1 && st.top() <= nums2[i])
                st.pop();
            
            next_grt_el[nums2[i]] = st.top();
            
            st.push(nums2[i]);
            
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(next_grt_el[nums1[i]]); 
        }
        
        return ans;
        
    }
};