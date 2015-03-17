class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> first,second;
		rowIndex++;
		first.push_back(1);
		if(rowIndex==1)
			return first;
		int i,j;
		for(i=1;i<rowIndex;i++)
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
			first = second;
			second.clear();
		}
		return first;
	}
};