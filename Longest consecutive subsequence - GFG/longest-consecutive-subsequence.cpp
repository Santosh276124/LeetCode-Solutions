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
      
      sort(nums, nums+n);
      
      int len = 1;
      
      int j = 0;
      
      int curr = 1;
      
      for(int i = 0; i < n-1; i++){
          
          if(nums[i+1] == nums[i])
            continue;
          
          if(nums[i+1]-nums[i] == 1){
              curr++;
              len = max(len, curr);
              
          }
          else{
              curr = 1;
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