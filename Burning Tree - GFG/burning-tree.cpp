//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    void findParent(Node* root, unordered_map<Node*, Node*>& parent)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int len = q.size();
            for(int i = 0; i < len; i++)
            {
                Node* front = q.front();
                q.pop();

                if(front->left){
                    parent[front->left] = front;
                    q.push(front->left);
                }
                if(front->right){
                    parent[front->right] = front;
                    q.push(front->right);
                }
            }
        }
    }
    
    Node* findTarget(Node* root, int target)
    {
        if(root == NULL) return NULL;
        
        if(root->data == target)
            return root;
            
        Node* l = findTarget(root->left, target);
        Node* r = findTarget(root->right, target);
        
        if(l == NULL && right == NULL) return NULL;
        if(l && r == NULL) return l;
        if(r && l == NULL) return r;
    }
    
    int minTime(Node* root, int target) 
    {
        
        // step 1 : find parent reference
        unordered_map<Node*, Node*> parent;
        findParent(root, parent);
        
        // step2 : find reference of target
        Node* tar = findTarget(root, target);
        
        // cout<<tar->data<<" ";
        int cnt = 0;
        
        queue<Node*> q;
        unordered_map<Node*, bool> vis;
        
        q.push(tar);
        vis[tar] = true;
        
        while(!q.empty())
        {
            
            int len = q.size();
            for(int i = 0; i < len; i++)
            {
                Node* front = q.front();
                q.pop();
                
                if(front->left && !vis[front->left]){
                    q.push(front->left);
                    vis[front->left] = true;
                }
                if(front->right && !vis[front->right]){
                    q.push(front->right);
                    vis[front->right] = true;
                }
                if(parent[front] && !vis[parent[front]]){
                    q.push(parent[front]);
                    vis[parent[front]] = true;
                }
            }
            
            cnt++;
        }
        
        return cnt-1;
        
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends