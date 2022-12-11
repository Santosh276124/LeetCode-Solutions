//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
          unordered_map<int, int> mp;

        for(int i=0; i<nums.size(); i++){

            if(nums[i]%k!=0) mp[nums[i]%k]++;

        }

        for(int i=0; i<nums.size(); i++){

            int x = nums[i]%k;

            if(mp.find(k-x) != mp.end()){

                mp[x]--;

                mp[k-x]--;

                if(mp[x] == 0) mp.erase(x);

                if(mp[k-x] == 0) mp.erase(k-x);

            }

        }

        return mp.size() == 0 ? true : false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends