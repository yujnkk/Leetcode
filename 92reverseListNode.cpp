class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head)
        return NULL;
        int i = 1;
        ListNode *pre,*pre1,*cur,*cur1;
        pre = head;
        pre1 = NULL;
        while(i<m)
        {
            pre1 = pre;
            pre = pre->next;
			i++;
        }
        cur = pre;
        while(i<n)
        {
            cur = cur->next;
			i++;
        }
        cur1 = cur->next;//����Ҫ����������д���
        reverse(pre,cur);
		if(pre1!=NULL)
        {
			pre1->next = pre;		
			cur->next = cur1;
			return head;
		}
		else
		{
			cur->next = cur1;			
			return pre;
		}
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
	////////////////////////////////
	//Ҫ��ѭ���������Լ�״̬����������ʶ����Ҫ����ѭ����ʱ���ܶ���жϣ�����ǣ��϶����Լ�˼·��ƫ� 		
       
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