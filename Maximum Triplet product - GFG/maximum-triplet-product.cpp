//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Complete the function
    	priority_queue<long long> maxHeap;
    	priority_queue<long long , vector<long long>, greater<long long> > minHeap;
    	
    	for(int i = 0; i < n; i++)
    	{
    	    
	        minHeap.push(arr[i]);

	        maxHeap.push(arr[i]);
    	    
    	}
    
    	
    	long long max1 = maxHeap.top();
    	maxHeap.pop();
    	long long max2 = maxHeap.top();
    	maxHeap.pop();
    	long long max3 = maxHeap.top();
    	maxHeap.pop();
    	
    	long long min1 = minHeap.top();
    	minHeap.pop();
    	long long min2 = minHeap.top();
    	minHeap.pop();
    	
    	return max(min1*min2*max1, max1*max2*max3);
    	
     }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends