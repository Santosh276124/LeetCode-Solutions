//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        int mod = 1e5;
        
        vector<int> dist(100000, 1e9);
        queue<pair<int,int>> q;
        
        q.push({start, 0});  //node, steps
        dist[start] = 0;
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            int node = front.first;
            int steps = front.second;
            
            if(node == end) return steps;
            
            for(auto it : arr)
            {
                int num = (it * node)%mod;
                
                if(steps + 1 < dist[num])
                {
                    dist[num] = 1 + steps;
                    
                    q.push({num, 1 + steps});
                }
            }
            
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends