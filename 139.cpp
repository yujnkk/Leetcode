class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<int> flags;
		flags.push_back(0);
		int i;
		for(i=1;i<=s.size();i++)
		{
			for(int j=flags.size()-1;j>=0;j--)
			{
			if(wordDict.find(s.substr(flags[j],i-flags[j]))!=wordDict.end())
				{
					flags.push_back(i);
					break;
				}
			}
		}
		if(flags[flags.size()-1]==s.size())
			return true;
		return false;
    }
};