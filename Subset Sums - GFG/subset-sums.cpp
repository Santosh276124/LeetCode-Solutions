//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    void solve(int ind, vector<int> &nums, vector<int>& ans, int sum)
    {
        if(ind == nums.size())
        {
            ans.push_back(sum);
            sum = 0;
            return;
        }
        
        solve(ind+1, nums, ans, sum);
        
        solve(ind+1, nums, ans, sum+nums[ind]);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        
        vector<int> ans;
       
       solve(0, arr, ans, 0);
       return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends