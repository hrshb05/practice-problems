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
    ListNode* mergeTwoLists(ListNode* x, ListNode* y) {
       
        
        if(!x)
            return y;
        if(!y)
            return x;
        ListNode* z= NULL;
        if(x->val <= y->val)
        {
            z=x;
            x = x->next;
        }
        else
        {
            z = y;
            y = y->next;
        }
        ListNode* h = z;
        while(x!=NULL && y!=NULL)
        {
            if(x->val <= y->val)
            {
                h->next = x;
                x = x->next;
            }
            else
            {
                h->next = y;
                y = y->next;
                
            }
            h = h->next;
        }
        while(x)
        {
            h->next =x;
            x = x->next;
            h = h->next;
        }
        while(y)
        {
            h->next =y;
            y = y->next;
            h = h->next;
        }
        return z;
    }
};