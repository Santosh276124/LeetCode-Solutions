//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
       
       stack<char> st;
       
       for(int i = 0; i < s.length(); i++)
       {
           if(s[i] != ']')
           {
               st.push(s[i]);
           }
           
           else
           {
               string currStr = "";
               while(st.top() != '[')
               {
                   currStr = st.top() + currStr;
                   st.pop();
               }
               
               st.pop();
               
               string num = "";
               while( !st.empty() && isdigit(st.top()))
               {
                   num = st.top() + num;
                   st.pop();
               }
               
               int k = stoi(num);
               while(k--)
               {
                   for(int j = 0; j < currStr.length(); j++)
                   {
                       st.push(currStr[j]);
                   }
               }
           }
       }
       
       string ans = "";
       
       while(!st.empty())
       {
           ans = st.top() + ans;
           st.pop();
       }
       
       return ans;
       
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends