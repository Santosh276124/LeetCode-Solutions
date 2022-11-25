class Solution {
  
   
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        stack<int> left, right;         // to store index of smaller element in left and right side
        vector<int> prev(n), next(n);  //for no. of elements on both side of that element that                                           are greater than the current element
        
        for(int i = 0; i < n; i++)
        {
            prev[i] = i;
            next[i] = n-i-1;
        }
        
        for(int i = 0; i < n; i++)
        {
            while(!left.empty() && arr[left.top()] > arr[i])
            {
                next[left.top()] = i-left.top()-1;
                left.pop();
            }
            left.push(i);
        }
        
        for(int i = n-1; i >= 0; i--)
        {
            while(!right.empty() && arr[right.top()] >= arr[i])
            {
                prev[right.top()] = right.top()-i-1;
                right.pop();
            }
            right.push(i);
        }
         int mod = 1e9+7;
         int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int val1 = (prev[i]+1)%mod;
            int val2 = (next[i]+1)%mod;
            int val3 = arr[i]%mod;
            long long prod = (val1*val2)%mod;
           
            prod = (prod*val3)%mod;
            
            ans += (prod%mod);
            ans %= mod;
        }
      return ans%mod;
        
    }
};