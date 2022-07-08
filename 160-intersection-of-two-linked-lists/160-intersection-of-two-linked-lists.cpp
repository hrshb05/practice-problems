/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *n, ListNode *m) {
        int a = 0,b =0;
        ListNode* h = n;
        ListNode* g = m;
        while(h)
        {
            a++;
            h = h->next;
        }   
        while(g){
            
            b++;
            g = g->next;
        }
        if(b>a)
        {
            h = m;
            g = n;
        }
        else
        {
            h = n;
            g = m;
        }
        // cout<<abs(a-b)<<" "<<b;
        int x = abs(a-b);
        while(x>0 && h!=NULL)
        {
            x--;
           h = h->next;
            
        }  
        while(h&&g)
        {
            if(h== g)
            {
                if(h->val == g->val)
                    return h;
                // return h->next;
            }
                
            h = h->next;
            g = g->next;
        }
        return NULL;
    }
};