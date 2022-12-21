//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	Node* next;
	int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " ";
		head = head->next;
	}
	cout << endl;
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution{
    
    int listSize(Node* head)
    {
        Node* curr = head;
        int n = 0;
        while(curr != NULL)
        {
            n++;
            curr = curr->next;
        }
        return n;
    }
public:
    Node* sortList(Node* head)
    {
        // Your Code Here
        
        int n = listSize(head);
        // cout<<n<<" ";
        vector<int> temp(n);
        Node* curr = head;
        int i = 0;
        while(curr!=NULL)
        {
            // cout<<curr->data<<" ";
            temp[i++] = curr->data;
            curr = curr->next;
        }
        
       sort(temp.begin(), temp.end());
       
        curr = head;
       
       for(int i = 0; i < n; i++)
       {
        //   cout<<temp[i]<<" ";
           curr->data = temp[i];
           curr = curr->next;
       }
       
       return head;
        
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{

	int t = 0;
	int n = 0;
	cin >> t;
	while (t--)
	{
		Node* head = NULL;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// push(&head, a);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			push(&head, arr[i]);
		}
		// printList(head);
		
		Solution ob;
		head=ob.sortList(head);

		printList(head);

	}
	return 0;
}

// } Driver Code Ends