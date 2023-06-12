//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int nums[], int n)
    {
      if(n == 0) return 0;
      
      unordered_map<int,int> mp;
      
      for(int i = 0; i < n; i++){
          mp[nums[i]]++; 
      }
      
      int len = 0;
    
      
      for(int i = 0; i < n; i++){
          
        //   check if starting val
        if(!mp.count(nums[i]-1)){

            int val = nums[i];
            
            int curr = 1;
            while(mp.count(val+1)){
                curr++;
  
                val += 1;
            }
            
            len = max(len, curr);
            
        }
        
    
      }
      
      return len;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends