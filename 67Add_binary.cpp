class Solution {
public:
	string addBinary(string a, string b) {
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		string tmp;
		if(a.size()<b.size())
		{
			tmp = a;
			a = b;
			b.clear();
			b = tmp;
		}
		int i;
		bool flags=false;
		for(i=0;i<b.size();i++)
		{
			if(!flags)
			{
				if(b[i]=='1'&&a[i]=='0')
				{
					a[i]='1';
				}
				else if(b[i]=='1'&&a[i]=='1')
				{
					a[i]='0';
					flags = true;
				}
			}
			else
			{
				if(b[i]==a[i])
				{
					a[i] = '1';
					if(b[i]=='1')
						flags = true;
					else
						flags = false;
				}
				else
				{
					a[i] = '0';
					flags = true;
				}
			}
				
		}
		for(;i<a.size();i++)
		{
			if(flags)
			{
				if(a[i]=='1')
					a[i] = '0';
				else
				{
					a[i] = '1';
					flags = false;
				}
			}
			else break;
		}
		if(flags)
			a.push_back('1');
		reverse(a.begin(),a.end());
		return a;
	}
};