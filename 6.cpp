class Solution {
public:
	string convert(string s, int numRows) {
		vector<string> matrix;
		if(s.size()<=numRows||numRows==1)
			return s;		
		string tmp;
		tmp.clear();
		int i,j;
		for(i=0;i<numRows;i++)
		{
			matrix.push_back(tmp);
		}
		j = 0;
		i = 0;
		bool flags = true;
		while(i<s.size())
		{
			if(flags)
			{
				matrix[j].push_back(s[i]);
				j++;
				if(j==numRows)
				{
					j-=2;
					flags = false;
				}
			}
			else
			{
				matrix[j].push_back(s[i]);
				j--;
				if(j<0)
				{
					j+=2;
					flags = true;
				}
			}
			i++;
		}
		string result;
		for(i=0;i<numRows;i++)
		{
			result+=matrix[i];
		}
		return result;
	}
};