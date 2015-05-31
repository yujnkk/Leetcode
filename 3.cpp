class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char,int> flags;
		int begin,end,result;
		result = begin = end = 0;
		for(int i=0;i<s.size();i++)
		{
			end++;			
			if(++flags[s[i]]>1)
			{
				result = result>(end-begin-1)?result:(end-begin-1);
				for(int j = begin;j<=i;j++)
				{
					if(s[j]==s[i])
					{						
						begin = j + 1;
						flags[s[i]] = 1;
						break;
					}
					flags[s[j]] = 0;
				}
			}
		}
		result = result>(end-begin)?result:(end-begin);
		return result;
	}
};