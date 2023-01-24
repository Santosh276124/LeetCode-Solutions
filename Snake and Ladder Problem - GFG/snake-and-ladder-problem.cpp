//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int n, int arr[]){
        
        unordered_map<int,int> mp;
        for(int i = 0; i < 2*n-1; i++)
        {
            if(i%2 == 0)
               mp[arr[i]] = arr[i+1];
        }
        
        int steps = 0;
        queue<int> q;
        q.push(1);
        vector<bool> vis(30, false);
        
        vis[1] = true;
        
        while(!q.empty())
        {
            int len = q.size();
            for(int i = 0; i < len; i++)
            {
                int val = q.front();
                
                if(val == 30) return steps;
                
                q.pop();
                
                for(int j = 1; j <= 6; j++)
                {
                    int newVal = val + j;
                    
                    if(vis[newVal]) continue;
                    
                    vis[newVal] = true;
                    
                    if(mp.count(newVal))
                      q.push(mp[newVal]);
                     
                    else
                       q.push(newVal);
                    
                    
                }
            }
            steps++;
        }
        return -1;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends