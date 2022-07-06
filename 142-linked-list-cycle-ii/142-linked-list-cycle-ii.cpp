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
    ListNode *detectCycle(ListNode *head) {
        
          if(head == NULL) return NULL;
        if(head->next == NULL) return NULL;
        
        
        ListNode* f = head;
        ListNode* s= head;
        while(f!=NULL && f->next != NULL)
        {
            s = s->next;
            f = f->next->next;
            if(s == f)
                break;
        }
        if(s!=f)
            return NULL;
        s = head;
         // if(!(f && f->next)) return NULL;
        while(s!= f)
        {
            s = s->next;
            f = f->next;
        }
        return s;
    }
};