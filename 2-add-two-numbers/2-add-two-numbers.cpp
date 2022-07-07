/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    void rev(ListNode* &head)
    {
        ListNode* h = head;
        ListNode* p = NULL;
        while(h!=NULL)
        {
            ListNode* n = h->next;
            h->next = p;
            p = h;
            h = n;
        }
        head = p;
    }
    
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        
        // rev(a);
        // rev(b);
        int s =0,c=0;
        ListNode* r = NULL;
        ListNode* curr = NULL;
        ListNode* k;
        while(a||b)
        {
            s = c+(a?a->val:0)+(b?b->val:0);
            c = (s>=10)?1:0;
            s = s%10;
            k = new ListNode(s);
            if(r==NULL)
                r = k;
            else
                curr->next = k;
            curr = k;
            if(a)
                a= a->next;
            if(b)
                b = b->next;
        }
        if(c>0)
        {
            ListNode* g = new ListNode(c);
            curr->next = g;
            curr = g;
        }
        // rev(r);
        return r;
        
    }
};