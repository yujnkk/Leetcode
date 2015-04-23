class Solution {
public:
	int lengthOfLastWord(string s) {
		int length = 0;
		int i;
		for(i=s.size()-1;i>=0;i--)
		{
			if(s[i]==' ')
				continue;
			else break;
		}
		for(;i>=0;i--)
		{
			if(s[i]==' ')
				break;
			length++;

		}
		return length;
	}
};