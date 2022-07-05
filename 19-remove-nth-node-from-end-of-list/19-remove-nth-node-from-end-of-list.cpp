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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }
        int fl =0;
        ListNode* f = head;
        ListNode* s = head;
        for(int i =0;i<n;i++)
        {
           
            f = f->next;
        }
        ListNode* h = head;
        if(f == NULL )
                return head->next;
        while(f!= NULL)
        {
            h = s;
            s = s->next;
            f = f->next;
        }
        
 
        
        
            h->next = s->next;
            // s = s->next;
            delete s;
        
        
        return head;
        
    }
};