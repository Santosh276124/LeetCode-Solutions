//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int k, vector<int> &arr) {
        vector<int> v;
        int sum = 0, ans = 0;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }
        for(int i = 1; i * i <= sum; i++) {
            if(sum%i == 0) {
                v.push_back(i);
                if(i != sum/i) v.push_back(sum/i);
            }
        }
        for(int i = v.size() - 1; i >= 0; i--) {
            
            int cur = 0, mx = sum/v[i], cnt = 0;
            for(int j = 0; j < n; j++) {
                cur += arr[j];
                if(cur%v[i] == 0) {
                    cur = 0;
                    cnt++;
                }
            }
            if(cur != 0 && cur%v[i] == 0) cnt++;
            
            if(cnt >= k) ans = max(ans, v[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends