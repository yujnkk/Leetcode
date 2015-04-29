class Solution {
public:
	bool isIsomorphic(string s, string t) {
		map<char,int> sm,tm;
		for(int i=0;i<s.size();i++)
		{
			sm[s[i]]+=i+1;
			tm[t[i]]+=i+1;
			if(sm[s[i]]!=tm[t[i]])
				return false;
		}
		return true;
	}
};