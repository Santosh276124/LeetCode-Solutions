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
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head)
    {
        if(head == NULL || head->next == NULL) return head;
        
        Node* curr = head;
        Node* prev = NULL;
        while(curr != NULL)
        {
            Node* fr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fr;
        }
        return prev;
        
    }
    Node* findSum(Node* head, Node* list2)
    {
        Node* curr = head;
        Node* curr2 = list2;
        int carry = 0;
        
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        
        while(curr != NULL || curr2 != NULL || carry != 0)
        {
            int sum = 0;
            
         
            if(curr != NULL){
                
                sum += curr->data;
                curr = curr->next;
            }
            if(curr2 != NULL)
            {
                sum += curr2->data;
                curr2 = curr2->next;
            }
            
            sum += carry;
            
            int digit = sum % 10;
            carry = sum/10;
            
            Node* temp1 = new Node(digit);
            
            temp->next = temp1;
            
            temp = temp1;
        
        }
        
        return dummy->next;
    }
    Node* addOne(Node *head) 
    {
        // step1
        Node* rhead = reverse(head);
        
        // step2
        Node* list2 = new Node(1);
        list2->next = NULL;
        
        Node* ans = findSum(rhead, list2);
        
        // step3
        Node* res = reverse(ans);
        
        return res;
        
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends