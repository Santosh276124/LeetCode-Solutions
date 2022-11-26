//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
    
    int ind = 0;
    Node* solve(string str)
    {
        if(str.length() == 0 || ind >= str.length())
           return NULL;
          
        int num = 0;
        while(ind < str.length() && str[ind] != '(' && str[ind] != ')')
        {
            int val = (int)(str[ind]-'0');
            num = num*10 + val;
            ind++;
        }
        
        Node* root = NULL;
        if(num > 0)
          root = new Node(num);
        
       //for left child
       if(ind < str.length() && str[ind] == '(')
       {
           ind++;
           root->left = solve(str);
       }
        
       if(ind < str.length() && str[ind] == ')')
       {
           ind++;
           return root;
       }
       
       if(ind < str.length() && str[ind] == '(')
       {
           ind++;
           root->right = solve(str);
       }
        
       if(ind < str.length() && str[ind] == ')')
       {
           ind++;
           
       }
        return root;  
        
    }
    
public:
    // function to construct tree from string
    Node *treeFromString(string str){
      
        if(str.length() == 0) return NULL;
        
         return solve(str);
        
        
        
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends