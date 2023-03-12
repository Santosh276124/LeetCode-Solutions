//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    void insertAtTail(Node* &tail, Node* curr)
    {
        tail->next = curr;
        tail = curr;
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        
        Node* zhead = new Node(-1);
        Node* ztail = zhead;
        
        Node* ohead = new Node(-1);
        Node* otail = ohead;
        
        Node* thead = new Node(-1);
        Node* ttail = thead;
        
        Node* curr = head;
        while(curr != NULL)
        {
            int val = curr->data;
            if(val == 0)
            {
                insertAtTail(ztail, curr);
            }
            else if(val == 1)
                insertAtTail(otail, curr);
                
            else if(val == 2)
                insertAtTail(ttail, curr);
                
            curr = curr->next;
        }
        
        // merge all three lists
        
        if(ohead->next != NULL)
        {
            ztail->next = ohead->next;
        }
        else{
            ztail->next = thead->next;
        }
        
        otail->next = thead->next;
        
        ttail->next = NULL;
        
        return zhead->next;
        
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends