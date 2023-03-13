//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* merge(Node* l1, Node* l2)
{
    Node* dummy = new Node(0);
    
    Node* curr = dummy, *curr1 = l1, *curr2 = l2;
    
    while(curr1 != NULL && curr2 != NULL)
    {
        if(curr1->data <= curr2->data)
        {
            curr->bottom = curr1;
            curr = curr1;
            curr1 = curr1->bottom;
        }
        else{
            curr->bottom = curr2;
            curr = curr2;
            curr2 = curr2->bottom;
        }
    }
    
    while(curr1 != NULL)
    {
        curr->bottom = curr1;
        curr = curr1;
        curr1 = curr1->bottom;
    }
    
    while(curr2 != NULL)
    {
        curr->bottom = curr2;
        curr = curr2;
        curr2 = curr2->bottom;
    }
    
    return dummy->bottom;
    
}
Node *flatten(Node *root)
{
   // Your code here
   
   if(root == NULL || root->next == NULL)
        return root;
        
    root->next = flatten(root->next);
    
    root = merge(root, root->next);
    
    return root;
   
   
}

