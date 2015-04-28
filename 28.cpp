class Solution {
public:
	int strStr(string haystack, string needle) {
		if(haystack.size()<needle.size())
			return -1;
		int len1,len2;
		len1 = haystack.size();
		len2 = needle.size();
		int i;
		for(i=0;i+len2<=len1;i++)
		{
			if(haystack.substr(i,len2)==needle)
				return i;		
		}
		return -1;

	}
};