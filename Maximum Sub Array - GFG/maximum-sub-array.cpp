//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
    
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    
	    int currSum = 0;
	    int maxSum = 0;
	    int j = 0;
	    int start = 0;
	    int end = -1;
	   
	    
	    for(int i = 0; i < n; i++)
	    {
	        if(a[i] >= 0)
	        {
	            currSum += a[i];
	            if(currSum >= maxSum)
	            {
	                maxSum = currSum;
	                start = j;
	                end = i;
	            }
	        }
	        else
	        {
	            currSum = 0;
	            j = i+1;
	            
	        }
	    }
	   
	    vector<int> ans;
	    for(int i = start; i <= end; i++)
	    {
	        ans.push_back(a[i]);
	    }
	  
	  if(ans.size() == 0) return {-1};
	    
	    return ans;
	    
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends