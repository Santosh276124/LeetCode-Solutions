//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        
        if(n == 1) return str;
        
        string lowerCase = "";
        string upperCase = "";
        
        for(int i = 0; i < n; i++)
        {
            if(islower(str[i])) lowerCase += str[i];
            else upperCase += str[i];
        }
        
        sort(lowerCase.begin(), lowerCase.end());
        sort(upperCase.begin(), upperCase.end());
        
        int j, k= 0;
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            if(islower(str[i]))
            {
                ans += lowerCase[j];
                j++;
            }
            else
            {
                ans += upperCase[k];
                k++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends