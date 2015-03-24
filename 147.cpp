class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if(!head)
			return head;
		if(!head->next)
			return head;
		ListNode * tou = new ListNode(-999999);
		tou->next = head;
		head = tou;
		ListNode * flags = head->next;
		ListNode * charujiedian;
		while((flags->next))
		{
			charujiedian = flags->next;
			flags->next = flags->next->next;
			charu(head,charujiedian,flags);		

		}
		head = head->next;
		return head;
	}
	void charu(ListNode * head,ListNode * cha,ListNode *&flags)
	{
		while(head!=flags)
		{
			if((cha->val)<=(head->next->val))
			{
				cha->next=head->next;
				head->next = cha;
				return;
			}
			else
				head = head->next;
		}
		cha->next=head->next;
		head->next = cha;
		flags = flags->next;
		return;

	}
};