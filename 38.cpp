class Solution {
public:
	string countAndSay(int n) {
		string a,b;
		int i;
		char c;
		int count=0;
		n = n-1;
		a.push_back('1');
		if(n==0)
			return a;
		while(n--)
		{
			c = a[0];
			count=1;
			for(i=1;i<a.size();i++)
			{
				if(a[i]==c)
				{
					count++;				
				}
				else
				{
					b.push_back(count+48);
					b.push_back(c);
					count=1;
					c = a[i];
				}
			}
			b.push_back(count+48);
			b.push_back(c);
			a.clear();
			a = b;
			b.clear();			
		}
		return a;
	}
};