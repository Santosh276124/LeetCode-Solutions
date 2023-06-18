//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    // static bool comp(pair<int,int> &a, pair<int,int> &b){
        
    //     if(a.second == b.second)
    //         return a.first < b.first;
    //     return a.second < b.second;
    // }
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // vector<pair<int,int>> nums;
        
        // for(int i = 0; i < n; i++){
        //     nums.push_back({arr[i],1});
        //     nums.push_back({dep[i],-1});
        // }
        
        // sort(nums.begin(), nums.end());
        
        map<int,int> mp;
        
        int ans = 0;
        int maxi = 0;
        
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
            mp[dep[i]+1]--;
            
            
        }
        
        for(auto m : mp){
            ans += m.second;
            maxi  = max(maxi, ans);
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends