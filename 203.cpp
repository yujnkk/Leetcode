class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		while(head!=NULL&&head->val==val)
		{		
				head=head->next;
		}
		if(head==NULL||head->next==NULL)
			return head;
		ListNode * pre,*cur;
		pre = head;
		cur = head->next;
		while(cur!=NULL)
		{
			while(cur!=NULL&&cur->val==val)
			{
				cur = cur->next;
			}
			pre->next = cur;
			pre = cur;
			if(cur==NULL)
				break;
			cur = cur->next;
		}
		return head;

	}
};