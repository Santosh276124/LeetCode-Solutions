//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
   Node* reverseList(Node* head)
   {
       Node* curr = head;
       Node* prev = NULL;
       
       while(curr != NULL)
       {
           Node* forward = curr->next;
           curr->next = prev;
           prev = curr;
           curr = forward;
       }
       
       return prev;
   }
    Node *reverse(Node *head, int k)
    {
        // code here
        
        if(head == NULL || head->next == NULL) return head;
        
        Node* curr1 = head;
        
        Node* curr2 = head;
        
        while(k-- > 1)
        {
            curr2 = curr2->next;
        }
        
        Node* forward = curr2->next;
        curr2->next = NULL;
        curr2 = forward;
        
        Node* newcurr1 = reverseList(curr1);
        Node* newcurr2 = reverseList(curr2);
        
        Node* root = newcurr1;
 
        while(root->next != NULL)
        {
            root = root->next;
        }
        
        root->next = newcurr2;
        
        return newcurr1;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends