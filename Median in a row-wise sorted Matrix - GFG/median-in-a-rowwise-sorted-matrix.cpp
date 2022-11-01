//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{ 
    int countLessThanMid(vector<vector<int>> &matrix, int i, int Mid, int C)
    {
        int l = 0;
        int h = C-1;
        
        while(l <= h)
        {
            int m = l + (h-l)/2;
            
            if(matrix[i][m] <= Mid)
            l = m+1;
            
            else
            h = m-1;
            
        }
        return l;
    }
public:
    int median(vector<vector<int>> &matrix, int R, int C){
     
       int l = 1;
       int h = 2001;
       
       while(l <= h)
       {
           int mid = (l+h)/2;
           int cnt = 0;
           for(int i = 0; i < R; i++)
           {
               cnt += countLessThanMid(matrix, i, mid, C);
           }
           
           if(cnt <= (R*C)/2)
           l = mid+1;
           else
           h = mid-1;
           
       }
       
       return l;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends