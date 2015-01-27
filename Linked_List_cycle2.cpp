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
        ListNode * fast,*slow;
        fast = head;
        slow = fast;
        if(!head)
        return NULL;
        while(true)
        {
            slow = slow->next;
            if(!slow)
            return NULL;
            fast = fast->next;
            if(!fast)
            return NULL;
            fast = fast->next;
            if(!fast)
            return NULL;
            if(fast == slow)
            break;
        }
        fast = head;
        if(fast ==slow)
        return fast;
        while(true)
        {
            fast = fast->next;
            slow = slow->next;
            if(fast==slow)
            break;
        }
        return fast;
    }
};