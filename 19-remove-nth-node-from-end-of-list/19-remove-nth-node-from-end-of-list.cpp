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
        // if(head == NULL || head->next == NULL)
        // {
        //     return NULL;
        // }
        // int fl =0;
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i =0;i<n;i++)
        {
           
            fast = fast->next;
        }
        // ListNode* h = head;
        if(fast == NULL )
                return head->next;
           while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next; fast=fast->next;
        }
        slow->next = slow->next->next;

        return head;
    
        
    }
};