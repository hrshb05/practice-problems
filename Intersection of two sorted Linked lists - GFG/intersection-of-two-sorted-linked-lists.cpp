// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* a, Node* b)
{
    // Your Code Here
    unordered_set<int>s;
    Node* k = NULL;
    Node* h = NULL;
    while(a!=NULL)
    {
        s.insert(a->data);
        a = a->next;
    }
    
    while(b!=NULL)
    {
        if(s.find(b->data)!=s.end())
        {
            if(k == NULL)
            {
                k = new Node(b->data);
                h =k;
            }
            else
            {
            k->next = b;
            k = k->next;
            }
            s.erase(b->data);
        }
        else
        {
            Node* t = b;
            delete t;
            
        }
        b = b->next;
        if(b == NULL)
            k->next = NULL;
    }
    return h;
}