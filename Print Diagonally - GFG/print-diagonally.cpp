//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> a)
	{
		// Your code goes here
	   int	N = 2*n-1;
		vector<vector<int>> res(N);
		
		for(int i = 0; i < a.size(); i++)
		{
		    for(int j = 0; j < a[0].size(); j++)
		    {
		        res[i+j].push_back(a[i][j]);
		    }
		}
		
		vector<int> ans;
		
		for(int i = 0; i < res.size(); i++)
		{
		    for(int j = 0; j < res[i].size(); j++)
		    {
		        ans.push_back(res[i][j]);
		    }
		}
		
		return ans;
		
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends