// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
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
    Node* h = head;
    Node* p = NULL;
    while(h != NULL)
    {
        Node* n = h->next;
        h->next = p;
        p = h;
        h = n;
    }
    head = p;
    }
    
    Node *compute(Node *head)
    {
        rev(head);
        Node* h = head;
    Node* s=h;
    int m = h->data;
        while(s->next!= NULL)
        {
            if((s->next->data)>=m)
            {
                 m = s->next->data;
                //  h = s;
                 s = s->next;
            }
            else
            s->next = s->next->next;
        
        }
        rev(head);
        return head;
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends