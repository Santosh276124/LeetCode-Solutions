//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        vector<int> row_with_all_0;
        
        for(int i = 0; i < n; i++){
            auto vec = M[i];
            
            if(accumulate(vec.begin(), vec.end(), 0) == 0)
                row_with_all_0.push_back(i);
            
        }
        
        int ans = -1;
        
        for(int i = 0; i < row_with_all_0.size(); i++){
            
            int per = row_with_all_0[i];
            
            bool fl = false;
            
            for(int j = 0; j  < n; j++){
                
                if(j != per){
                    if(M[j][per] != 1){
                        fl = true;
                        break;
                    }
                        
                }
                
            }
            
            if(fl == false)
                ans = per;
            
        }
        
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends