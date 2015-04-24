class Solution {
public:
	bool isValid(string s) {		
		stack<char> st;
		int i;
		if(s.empty())
			return true;
		for(i=0;i<s.size();i++)
		{
			if(s[i]=='(')
				s[i]=1;
			else if (s[i]==')')
			{
				s[i]=-1;
			}
			else if (s[i]=='[')
			{
				s[i]=2;
			}
			else if(s[i]==']')
			{
				s[i]=-2;
			}
			else if(s[i]=='{')
			{
				s[i]=3;
			}
			else
				s[i]=-3;
		}
		st.push(s[0]);
		for(i=1;i<s.size();i++)
		{
			if(!st.empty())
			{
				if(st.top() < 0)
				return false;			
				if(st.top()+s[i]==0)
					st.pop();
				else
					st.push(s[i]);
			}
			else
				st.push(s[i]);
		}
		if(st.empty())
			return true;
		return false;
	}
};