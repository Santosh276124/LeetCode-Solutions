//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{
    // write code here
    long long MOD = 1e9+7;
      long long ans = 0;

        long long totalCount = N * M - 1;

        int dx[8] = {-2,-2,2,2,1,1,-1,-1};

        int dy[8] = {1,-1,-1,1,-2,2,2,-2};

        for(int i =0 ; i < N ; i++){

            for(int j = 0 ; j < M ; j++){

                int cnt = 0;

                for(int k = 0;k < 8; k++){

                    int nx = dx[k] + i;

                    int ny = dy[k] + j;

                    if(nx >=0 && ny >= 0 && nx < N && ny < M){

                        cnt++;

                    }

                }

                ans = ans + (totalCount - cnt)%MOD;

                ans = ans%MOD; 

            }

        }

        return ans;
}