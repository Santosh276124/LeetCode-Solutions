//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int n, vector<int>& arr) {
        
        
        stack<int> st;
        vector<int> ans(n);
        
        for(int i = n-1; i >= 0; i--){
            st.push(arr[i]);
        }
        
 
        
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() <= arr[i])
                st.pop();
                
            if(st.empty())
                ans[i] = -1;
            else 
                ans[i] = st.top();
                
            st.push(arr[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends