class Solution {
public:
	int longestValidParentheses(string s) {
		if(s.size()==0)
			return 0;
		int result,begin =0;
		int i,tmp=0;
		int length = 0;
		for(i=0;i<s.size();i++)
		{
			if(s[i]=='(')
				tmp+=1;
			if(s[i]==')')
				tmp-=1;
			if(tmp<0)
			{
				length = length>(i-begin)?length:(i-begin); 
				begin = i+1;
				tmp = 0;
			}
		}
		if(tmp>0)
		{
			tmp = 0;
			int end = s.size()-1;
			for(i=s.size()-1;i>=begin;i--)
			{				
				if(s[i]=='(')
					tmp-=1;
				if(s[i]==')')
					tmp+=1;
				if(tmp<0)
				{
					length = length>(end - i)?length:(end - i);
					end = i-1;
					tmp = 0;
				}
			}			
			if(tmp<=0)
			{
				length = length>(end - i)?length:(end - i);
				end = i;
				tmp = 0;
			}			
			return length;
		}
		if(tmp==0)
		{
			length = length>(i-begin)?length:(i-begin);
			return length;
		}
		return length;
	}
};