class Solution {
	int ccc;
	string result;
public:
	string longestPalindrome(string s) {
		if(s.size()<2)
			return s;
		if(s.size()==2)
		{
			if(s[0]==s[1])
				return s;
			else
				return s.substr(0,1);
		}
		ccc = 0;
		for(int i=1;i<s.size();i++)
			judge(s,i);
		return result;
	}
	void judge(string s,int l)
	{	
		int i,j,count;
		bool flag = false;
		if(l+ccc/2>=s.size()||l-ccc/2<0)
			return;
		if(s[l]==s[l-1])
		{
			i = l-1;
			j = l;
			count = 0;
			if(l+1<s.size()&&s[l-1]==s[l+1])
				flag = true;
		}
		else 
		{
			i = l-1;
			j = l+1;
			count = 1;
		}
		while(i>=0&&j<=s.size()-1&&s[i]==s[j])
		{
			i--;
			j++;
			count+=2;
		}
		if(count>ccc)
		{
			result = s.substr(i+1,count);
			ccc = count;
		}
		if(flag)
		{
			i = l - 1;
			j = l + 1;
			count = 1;
			while(i>=0&&j<=s.size()-1&&s[i]==s[j])
			{
				i--;
				j++;
				count+=2;
			}
			if(count>ccc)
			{
				result = s.substr(i+1,count);
				ccc = count;
			}
		}
	}
};