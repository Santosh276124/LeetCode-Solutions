//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
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

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here 
        
        Node* curr1 = head1;
        Node* curr2 = head2;
        
        //brute force -> m*n
        // while(head1 != NULL)
        // {
        //     Node* temp = head2;
            
        //     while(temp != NULL)
        //     {
        //         if(temp == head1) return head1->data;
        //         temp = temp->next;
        //     }
        //     head1 = head1->next;
        // }
        // return -1;
        
        // O(m+n) O(m)
        // unordered_map<Node* , int> mp;
        
        // while(head1 != NULL) {
        //     mp[head1]++;
        //     head1 = head1->next;
        // }
        
        // while(head2 != NULL){
            
        //     if(mp[head2] > 0) return head2->data;
            
        //     head2 = head2->next;
        // }
        
        // 3-> two pointers
        while(curr1 != curr2)
        {
            if(curr1 == NULL) curr1 = head2;
            else curr1 = curr1->next;
            if(curr2 == NULL) curr2 = head1;
            else curr2 = curr2->next;
        }
        
        
        return curr1 == curr2 ? curr1->data : -1;
    }
};



//{ Driver Code Starts.


/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends