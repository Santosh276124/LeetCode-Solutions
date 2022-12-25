//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();
        
        set<long long int> zerowala;
        set<long long int> nonzerowala;
        
        // row sum
        for(int i = 0; i < n; i++)
        {
            long long int sum = 0;
            bool iszero = false;
            for(int j = 0; j < m; j++)
            {
                sum += matrix[i][j];
                if(matrix[i][j] == 0)
                  iszero = true;
            }
            
            if(iszero == true)
              zerowala.insert(sum);
            else
              nonzerowala.insert(sum);
        }
        // col sum
        for(int i = 0; i < n; i++)
        {
            long long int sum = 0;
            bool iszero = false;
            for(int j = 0; j < m; j++)
            {
                sum += matrix[j][i];
                if(matrix[j][i] == 0)
                  iszero = true;
            }
            
            if(iszero == true)
              zerowala.insert(sum);
            else
              nonzerowala.insert(sum);
        }
        // diag sum left to right
        long long int sum = 0;
        bool iszero = false;
        for(int i = 0; i < n; i++)
        {
            
            sum += matrix[i][i];
            
            if(matrix[i][i] == 0)
              iszero = true;
        
        }
        if(iszero == true)
              zerowala.insert(sum);
        else
          nonzerowala.insert(sum);
          
        // diag sum right to left
         sum = 0;
         iszero = false;
        for(int i = 0; i < n; i++)
        {
        
                sum += matrix[i][n-i-1];
                if(matrix[i][n-i-1] == 0)
                  iszero = true;
           
        }
        if(iszero == true)
              zerowala.insert(sum);
        else
          nonzerowala.insert(sum);
          
          
        // for(auto s : zerowala)
        //   cout<<s<<" ";
        
        if((nonzerowala.size() > 1) || (zerowala.size() != nonzerowala.size()))
          return -1;
          
        if(*nonzerowala.begin() <= *zerowala.begin())
          return -1;
        
        return *nonzerowala.begin()- *zerowala.begin();
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends