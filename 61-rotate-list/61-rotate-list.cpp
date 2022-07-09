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
    ListNode* rotateRight(ListNode* head, int k) {
       
         if(head == NULL || k == 0)
            return head;
        int c =1;
        ListNode* h = head;
        while(h->next!=NULL)
        {
            c++;
            h = h->next;
        }
        h->next = head;
       
        k %= c;
        // if(k==0)
        // return head;
          ListNode* a;
        k = c-k;
        while(k>0)
        {
            k--;
            h = h->next;
        }
       a=h;
//         while(h->next!=NULL)
//             h = h->next;
//         h->next = head;
      
        head = a->next;
        a->next = NULL;
        return head;
        
    }
        
    
};