//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int N, int k) {
        // code here
        
        int totalSum = 0;
        int n = cardPoints.size();
        for(int i = 0; i < n; i++)
        {
            totalSum += cardPoints[i];
        }
        if(n == k) return totalSum;
        int currSum = 0;
        int j = 0;
        int maxSum = 0;
        for(int i = 0; i < n; i++)
        {
            currSum += cardPoints[i];
            
            if(i-j+1 == n-k)
            {
                maxSum = max(maxSum, totalSum-currSum);
                currSum -= cardPoints[j];
                j++;
            }
        }
        return maxSum;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends