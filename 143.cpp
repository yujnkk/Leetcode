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
	void reorderList(ListNode* head) {
		if(!head)
			return;
		ListNode* a,*b,*tmp,*a1,*b1;
		a = head;
		b = head->next;
		if(b==NULL)
			return;
		while(b&&b->next)
		{
			a = a->next;
			b = b->next->next;
		}
		tmp = a->next;
		a->next = NULL;
		tmp = reverseList(tmp);
		a = head;
		b = tmp;
		while(b)
		{
			a1 = a->next;
			b1 = b->next;
			a->next = b;
			b->next = a1;
			a = a1;
			b = b1;
		}		
	}
	ListNode* reverseList(ListNode* head) {
		if(head==NULL)
			return head;
		ListNode * tail=head;
		while(tail->next)
		{
			tail = tail->next;
		}
		reverse(head,tail);
		tail->next = NULL;
		return head;
	}
	void reverse (ListNode *&head,ListNode *&tail)
	{
		ListNode * a,*b,*c;
		a = head;
		b = a->next;
		if(head==tail)
			return;
		if(b==tail)
		{
			b->next = a;
			a = head;
			head = tail;
			tail = a;
			return;
		}
		c = b->next; 		

		while(c!=tail)
		{
			b->next = a;
			a = b;
			b = c;
			c = c->next;
		}      		
		b->next = a;
		c->next = b;
		a = head;
		head = tail;
		tail = a;
	}
};