//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int a1[], int a2[], int n) {
            // code here 
            vector<int> temp;
            
            int i = 0;
            int j = 0;
            while(i < n && j < n){
                if(a1[i] <= a2[j]){
                    temp.push_back(a1[i]);
                    i++;
                }
                else{
                    temp.push_back(a2[j]);
                    j++;
                }
            }
            
            while(i < n){
                temp.push_back(a1[i]);
                    i++;
            }
            
            while(j < n){
                temp.push_back(a2[j]);
                    j++;
            }
            
            int ans = 0;
            int m = temp.size();
            
            int ind = m/2;
            return temp[ind]+temp[ind-1];
            
            
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends