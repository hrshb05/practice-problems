// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
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
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
  
    void rev(struct Node* &head)
    {
        Node* f = head;
        Node* p = NULL;
        while(f!=NULL)
        {
            Node* n = f->next;
            f->next = p;
            p = f;
            f = n;
        }
        head = p;
    }
    struct Node* addTwoLists(struct Node* i, struct Node* j)
    {
         rev(i);
         rev(j);
        Node* k;
        int sum =0,c=0;
        Node* r = NULL;
        Node* curr = NULL;
        while(i!=NULL || j!=NULL)
        {
            sum = c+(i?i->data:0) + (j?j->data:0);
            c = (sum>=10)?1:0;
            // sum %
            k = new Node(sum%10);
            if(r== NULL)
            r = k;
            else
            curr->next = k;
            curr = k;
            if(i!=NULL)
            i=i->next;
            if(j!=NULL)
            j = j->next;
            
        }
        if(c>0)
        {
            Node* h = new Node(c);
            curr->next = h;
            curr = h;
        }
        rev(r);
        
        return r;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends