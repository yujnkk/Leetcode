class Solution {
public:
	bool isPalindrome(string s) {
		string tmp;
		int i,j;
		if(s.size()==0)
			return true;
		for(i=0;i<s.size();i++)
		{
			if('A'<=s[i]&&s[i]<='Z')
				tmp.push_back(s[i]+32);
			if('a'<=s[i]&&s[i]<='z')
				tmp.push_back(s[i]);
			if('0'<=s[i]&&s[i]<='9')
				tmp.push_back(s[i]);
		}
		i=0;
		j=tmp.size()-1;
		while(i<=j)
		{
			if(tmp[i]!=tmp[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
};