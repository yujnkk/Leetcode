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