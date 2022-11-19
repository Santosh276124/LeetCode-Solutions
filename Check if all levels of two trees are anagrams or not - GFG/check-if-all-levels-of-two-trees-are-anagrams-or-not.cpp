//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
    // vector<int> PrintLevelOrder(Node* root)
    // {
    //           vector<int> ans;
       
    //           queue<Node*> q;
    //           q.push(root);
    //           Node* curr = NULL;
        
    //           while(!q.empty()){
                
    //             int len = q.size();
    //             for(int i = 0; i < len; i++)
    //             {
    //                 curr = q.front();
    //                 q.pop();
                    
    //                 ans.push_back(curr->data);
                    
    //                 if(curr->left) q.push(curr->left);
    //                 if(curr->right) q.push(curr->right);
    //             }
    //           }
            
    //         return ans;
    // }
    public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        
    //   vector<int> levelForOne = PrintLevelOrder(root1);
    //   vector<int> levelForTwo = PrintLevelOrder(root2);
       
    //   if(levelForTwo.size() != levelForOne.size()) return false;
         
    //     sort(levelForOne.begin(), levelForOne.end());
    //     sort(levelForTwo.begin(), levelForTwo.end());
        
    //     for(int i = 0; i < levelForOne.size(); i++)
    //     {
    //         if(levelForOne[i] != levelForTwo[i]) 
    //             return false;
    //     }
    //     return true;
    
    if(root1 == NULL && root2 == NULL) return true;
    if(root1== NULL && root2 != NULL) return false;
     if(root1!= NULL && root2 == NULL) return false;
    
    queue<Node*> q1;
    queue<Node*> q2;
    q1.push(root1);
    q2.push(root2);
    
    Node* curr1 = NULL;
    Node* curr2 = NULL;
    
    while(!q1.empty() || !q2.empty())
    {
        int len1 = q1.size();
        int len2 = q2.size();
        map<int,int> m;
        // vector<int> temp1;
        // vector<int> temp2;
        for(int i = 0; i < len1; i++)
        {
            curr1 = q1.front();
            q1.pop();
            // temp1.push_back(curr1->data);
            m[curr1->data]++;
            if(curr1->left) q1.push(curr1->left);
            if(curr1->right) q1.push(curr1->right);
        }
        
         for(int i = 0; i < len2; i++)
        {
            curr2 = q2.front();
            q2.pop();
            if(m.count(curr2->data))
            {
                m[curr2->data]--;
                if(m[curr2->data] == 0) m.erase(curr2->data);
            }
            else return false;
            // temp2.push_back(curr2->data);
            if(curr2->left) q2.push(curr2->left);
            if(curr2->right) q2.push(curr2->right);
        }
        
        if(m.size() != 0) return false;
        
        // sort(temp1.begin(), temp1.end());
        // sort(temp2.begin(), temp2.end());
        
        // if(temp1 != temp2) return false;
    }
    
    return true;
    
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends