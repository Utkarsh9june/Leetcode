//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
    void markParent(Node* root,unordered_map<Node*,Node*> &parent)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node* cur=q.front();
                q.pop();
                
                if(cur->left)
                {
                    parent[cur->left]=cur;
                    q.push(cur->left);
                }
                if(cur->right)
                {
                    parent[cur->right]=cur;
                    q.push(cur->right);
                }
            }
        }
    }
public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        unordered_map<Node*,Node*> parent;
        markParent(root,parent);
        unordered_map<Node*,bool> vis;
        queue<Node*> q,t;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node* cur=q.front();
                q.pop();
                
                if(cur->data==target)
                {
                    t.push(cur);
                    vis[cur]=true;
                }
                
                if(cur->left)
                q.push(cur->left);
                if(cur->right)
                q.push(cur->right);
            }
        }
        int curlevel=0;
        while(!t.empty())
        {
            int size=t.size();
            if(curlevel++ == k)
            break;
            for(int i=0;i<size;i++)
            {
                Node* cur=t.front();
                t.pop();
                
                if(cur->left && !vis[cur->left])
                {
                    t.push(cur->left);
                    vis[cur->left]=true;
                }
                if(cur->right && !vis[cur->right])
                {
                    t.push(cur->right);
                    vis[cur->right]=true;
                }
                if(parent[cur]&&!vis[parent[cur]])
                {
                    t.push(parent[cur]);
                    vis[parent[cur]]=true;
                }
            }
        }
        vector<int> ans;
        while(!t.empty())
        {
            Node* cur=t.front();
            t.pop();
            ans.push_back(cur->data);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends