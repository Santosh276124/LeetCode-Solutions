//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isPossible(int minDist, vector<int>& nums, int k){
        
        int n = nums.size();
        
        int lastCow = nums[0];
        
        int cnt = 1;
        for(int i = 1; i < n; i++){
            
            if(nums[i] - lastCow >= minDist){
                cnt++;
                
                lastCow = nums[i];
            }
            
        }
        if(cnt >= k)
            return true;
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        sort(stalls.begin(), stalls.end());
        
        int l= 0;
        int h = stalls[n-1] - stalls[0];
        
        while(l <= h){
            int mid = l + (h-l)/2;
            
            if(isPossible(mid, stalls, k))
                l = mid+1;
            else
                h = mid-1;
        }
        
        return h;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends