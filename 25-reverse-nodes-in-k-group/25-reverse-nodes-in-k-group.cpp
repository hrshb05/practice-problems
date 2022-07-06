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
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* f = head;
         ListNode* pv = NULL;
        bool j = false;
        int g =0,t=0;
        ListNode* u =head;
        while(u!=NULL)
        {
            u = u->next;
            g++;
        }
        // cout<<g<<endl;
        ListNode* v;
        while(f!=NULL)
        {
           v = f;
            int c =0;
             ListNode* n = NULL;
             ListNode* p = NULL;
            
            while(c<k && f!=NULL )
            {
                // if(g<k)
                // {
                n = f->next;
                f->next = p;
                p = f;
                f = n;
                // }
                c++;
            }
            if(!j){
            head = p;
                j = true;
            }
            else
            {
                pv->next = p;
            }
            pv = v;
            
          
            g = g-k;
             if(g<k)
           {
                 pv->next = f;
              
                break;
           } 
        }
        return head;
    }
};