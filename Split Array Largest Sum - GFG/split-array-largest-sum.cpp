//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   bool check( int arr[] ,int N, int K , int sum )

    {

        int temp = 0 ;

        int count = 0 ;

        for( int i = 0 ; i < N ; i++ )

        {

            temp += arr[i] ;

            if( temp > sum )

            {

                

                temp = arr[i] ;

                count++ ;

            }

        }

        

        if( temp <= sum )

            {

               

              count++ ;

            }

            

            if( count <= K ) return true ;

            

            return false ;

    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
          int sum = 0 ;

        int low = 1 ;

        for( int i = 0 ; i < N ; i++ )

        {

            sum += arr[i] ;

            low = max( low , arr[i] ) ;

        }

        

        

        int high = sum ;

        int ans = 0 ;

        while( low <= high  )

        {

            int mid = low + (high-low)/2 ;

            

            if( check ( arr , N , K , mid ) )

            {

                high = mid - 1  ;

                ans =  mid      ;

                // cout<<ans<<endl ;

            }

            else{

                low = mid + 1 ;

            }

        }

        

        return ans ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends