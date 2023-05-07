//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

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
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        int cnt=0;
        Node* ptr=head;
        while(ptr)
        {
            cnt++;
            ptr=ptr->next;
        }
        if(k==0 || k==cnt)
        return head;
        if(k>cnt)
        k-=cnt;
        ptr=head;
        for(int i=0;i<k-1;i++)
        {
            ptr=ptr->next;
        }
        Node* back=ptr->next;
        ptr->next=NULL;
        ptr=back;
        while(ptr)
        {
            if(ptr->next==NULL)
            {
                ptr->next=head;
                break;
            }
            ptr=ptr->next;
        }
        return back;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends