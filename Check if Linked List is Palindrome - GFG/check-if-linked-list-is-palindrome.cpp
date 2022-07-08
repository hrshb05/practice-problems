// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* rev(struct Node* head)
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
        return p;
    }
    bool isPalindrome(Node *head)
    {
        
        Node* f = head;
        Node* s = head;
        while(f!=NULL && f->next != NULL)
        {
            s = s->next;
            f = f->next->next;
        }
        Node* r = rev(s);
        Node* a = head;
        while(r!=NULL )
        {
            if(a->data!=r->data)
                return false;
            r = r->next;
            a = a->next;
            // cout<<r->data<<"g ";
            // cout<<a->data<<"f ";
        }
        return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends