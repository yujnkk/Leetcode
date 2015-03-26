class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if(!l1)
			return l2;
		if(!l2)
			return l1;
		ListNode * t1,*t2;
		int t;
		//t1 = new ListNode(-999);
		//t2 = new ListNode(-999);
		//t1->next = l1;
		//t2->next = l2;
		//l1 = revs(t1);
		//l2 = revs(t2);
		t1 = l1;
		t2 = l2;
		bool flag = false;	
		do
		{
			if(!flag)
			{
				t = l1->val+l2->val;
				if(t>=10)
				{
					l1->val = t%10;	
					flag = true;
				}
				else
				{
					l1->val = t;
				}
			}
			else
			{
				t = l1->val+l2->val+1;
				flag = false;
				if(t>=10)
				{
					l1->val = t%10;	
					flag = true;					
				}
				else
				{
					l1->val = t;
				}
			}
			l1 = l1->next;
			l2 = l2->next;
			
		}while((l1)&&(l2));
		if((!l1)&&(l2))
		{	
			l1 = t1;
			while(l1->next)
			{
				l1 = l1->next;
			}
			t  = l2->val;
			l1->next = l2;
			l1 = l1->next;
			if(flag)
			{
				t +=1;
				flag = false;
			}
			if(t==10)
			{
				l1 ->val = 0;				
				flag = true;
			}
			else
			{
				l1->val = t;				
			}
			l1=l1->next;
		}	
		//*
		while(l1)
		{
			if(flag)
			{
				t = l1->val+1;
				flag = false;
				if(t==10)
				{
						l1->val = 0;
						flag = true;
				}
				else
				{
					l1->val = t;
				}
			}													
			l1 = l1->next;
		}
		if(flag)
		{	
			l1 = t1;
			while(l1->next)
				l1 =l1->next;
			l1->next = new ListNode(1);
			l1->next->next = NULL;
		}		
		return t1;
	}
	ListNode* revs(ListNode * head)
	{
		ListNode * p,*q,*e;
		e = head;
		p = head->next;
		q = head->next->next;
		while(q)
		{
			
			p->next = e;
			e = p;
			p = q;
			q = q->next;
		}
		p->next = e;
		return p;
	}
};