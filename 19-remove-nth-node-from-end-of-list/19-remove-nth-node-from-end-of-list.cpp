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
        ListNode * slow = head;
        ListNode * fast = head;
        int count = n;
        
        while(count > 0)
        {
            fast = fast->next; count--;
        }
        
        if(fast == NULL) return head->next; // edge case handled
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next; fast=fast->next;
        }
        slow->next = slow->next->next;

        return head;
    
    }
};