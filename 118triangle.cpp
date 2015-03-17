class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<int> first,second;
		vector<vector<int> > result;
		if(numRows==0)
			return result;
		first.push_back(1);
		result.push_back(first);
		if(numRows==1)
			return result;
		int i,j;
		for(i=1;i<numRows;i++)
		{
			for(j=0;j<=i;j++)
			{
				if(j==0||j==i)
				{	
					second.push_back(1);
					continue;
				}
				second.push_back(first[j]+first[j-1]);
			}
			result.push_back(second);
			first = second;
			second.clear();
		}
		return result;
	}
};