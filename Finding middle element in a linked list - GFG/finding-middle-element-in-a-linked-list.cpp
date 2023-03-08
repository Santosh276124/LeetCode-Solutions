//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    Node* tortoiseMethod(Node* head)
    {
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast->next != NULL)
        {
            fast = fast->next;
            if(fast->next!=NULL)
                fast = fast->next;
            
            slow = slow->next;
                   
        }
        return slow;
    }
    int getLength(Node* head)
    {
        int n = 0;
        Node* curr = head;
        while(curr != NULL)
        {
            n++;
            curr = curr->next;
        }
        return n;
    }
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        if(head == NULL) return -1;
        if(head->next == NULL) return head->data;
        
        Node* mid = tortoiseMethod(head);
        
        int n = getLength(head);
        
        if(n % 2 == 1) return mid->data;
        
        else return mid->next->data;
        
    }
};


//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}

// } Driver Code Ends