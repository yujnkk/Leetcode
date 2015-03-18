class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		list<int> tmp;
		ListNode *p = head;	
		if(!head)
		    return head;
		while(p)
		{			
			tmp.push_back(p->val);
			p=p->next;
		}
		reverse(tmp.begin(),tmp.end());
		list<int>::iterator it;
		it = tmp.begin();
		k = k%tmp.size();
		if(k<=tmp.size())
		{
			for(int i = 0;i<k;i++)
				it++;
			reverse(tmp.begin(),it);
			reverse(it,tmp.end());
		}
		p = head;
		for(it=tmp.begin();it!=tmp.end();it++)
		{
			p->val = *it;
			p=p->next;
		}
		return head;
	}
};