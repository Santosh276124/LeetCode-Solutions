class Solution {
public:
    int n;
    int m;
    int binarySearch(int curr , vector<int> &arr, long long tar){
        
        int s = 0;
        int e = m-1;
        
        while(s <= e){
            int mid = s  + (e-s)/2;
            long long  prod = (arr[mid] * long(curr) );
            if(prod >= tar)
                e = mid-1;
            
            else
                s = mid+1;
        }
        
        return m-s;
        
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        // sort(spells.begin(), spells.end());
        sort(potions.begin(), potions.end());
        
         n = spells.size();
         m = potions.size();
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            
            int val = binarySearch(spells[i], potions, success);
            
            ans.push_back(val);
            
        }
        
        return ans;
        
    }
};