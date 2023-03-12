//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
int lowerBound(vector<int> &arr, int tar)
{
    int s = 0;
    int e = arr.size()-1;
    int ans = -1;
    while(s <= e)
    {
        int mid = s + (e-s)/2;
        
        if(arr[mid] < tar){
            // ans = mid;
            s = mid+1;
        }
        else{
            ans = mid;
            e = mid-1;
        }
    }
    
    return ans;
}
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        
        int ansInd = 0;
        int ansCnt = 0;
        
        for(int i = 0; i < N; i++)
        {
            vector<int> arr = mat[i];
            
            int lb = lowerBound(arr, 1);
            
            // cout<<lb<<" ";
            
            int ind = lb;
            int cnt = 0;
            if(ind != -1)
            {
                cnt = N-ind;
                
                if(cnt > ansCnt)
                {
                    ansCnt = cnt;
                    ansInd = i;
                }
            }
   
        }
        
        return {ansInd, ansCnt};
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends