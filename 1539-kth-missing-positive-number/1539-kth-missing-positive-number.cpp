class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
            
            unordered_map<int,int> mp;
        for(int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        int cnt = 0;
        for(int i = 1; ; i++)
        {
            if(mp.count(i) == false)
                cnt++;
            else
                continue;
            
            if(cnt == k)
                return i;
            
            
        }
            
        return -1;    
            
            
            
            
    }
};