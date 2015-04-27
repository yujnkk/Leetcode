class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if(!head)
			return head;
		ListNode * pre,* cur;
		pre = cur = head;
		int i=0;
		while(i<n)
		{
			cur = cur->next;
			i++;		
		}
		if(!cur)
			return pre->next;
		while((cur->next))
		{
			pre = pre->next;
			cur = cur->next;
		}
		pre->next = pre->next->next;
		return head;
	}
};