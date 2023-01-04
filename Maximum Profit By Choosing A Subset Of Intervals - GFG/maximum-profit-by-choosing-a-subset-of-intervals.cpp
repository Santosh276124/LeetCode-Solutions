//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        
        vector<pair<int,pair<int,int>> > events;  //{ startTime, {endTime, profit} }
        
        for(int i = 0; i < intervals.size(); i++)
        {
            events.push_back({intervals[i][0], {intervals[i][1], intervals[i][2]}});
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        
        sort(events.begin(), events.end());
        
        int maxVal = 0;
        for(auto &e : events)
        {
            while(!pq.empty() && pq.top().first <= e.first)
            {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }
            
            pq.push({e.second.first, maxVal + e.second.second});
        }
        
        while(!pq.empty())
        {
            maxVal = max(maxVal, pq.top().second);
            pq.pop();
        }
        return maxVal;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends