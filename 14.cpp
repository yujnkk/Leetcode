class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string result,tmp;
		result.clear();
		int i,j;
		if(strs.size()==0)
			return result;
		result = strs[0];
		for(i=1;i<strs.size();i++)
		{
			for(j=0;j<result.size();j++)
			{
				if(strs[i][j]!=result[j])
					break;
			}
			if(j==0)
			{
					result.clear();
					return result;
			}
			tmp.clear();
			tmp = strs[i].substr(0,j);
			result.clear();
			result = tmp;
		}
		return result;
	}
};