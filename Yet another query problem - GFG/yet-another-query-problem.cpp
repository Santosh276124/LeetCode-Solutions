//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        vector<int> ans;
        
        vector<int> prefr(N, 0);
        
        for(int i = 0; i < N; i++)
        {
            int val = A[i];
            int cnt = 0;
            for(int j = i; j < N; j++)
            {
                if(val == A[j])
                    cnt++;
            }
            
            prefr[i] = cnt;
        }
      
        
        for(auto q : Q)
        {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            
            int freq = 0;
            
            for(int i = l; i <= r; i++)
            {

                
                if(prefr[i] == k)
                    freq++;
                
            }
            
            ans.push_back(freq);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends