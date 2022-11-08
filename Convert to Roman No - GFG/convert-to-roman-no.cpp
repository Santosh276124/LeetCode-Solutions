//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string convertToRoman(int n) {
        // code here
        vector<pair<int, string>> pair = { {1000, "M"}, {900, "CM"}, {500, "D"}, 
            {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9,"IX"}, {5, "V"}, 
            {4, "IV"}, {1, "I"} };
            
        string ans = "";
      for(auto i : pair){
          while(n >= i.first)
          {
              ans += i.second;
              n -= i.first;
          }
      }  
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		Solution ob;
    	cout << ob.convertToRoman(N) << endl;
	}
	return 0;
}
// } Driver Code Ends