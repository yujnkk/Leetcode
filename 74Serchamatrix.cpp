class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int i,j;
		i = matrix.size();
		j = matrix[0].size();
		int low,high,midd;
		low = 1;
		high = i*j;
		midd = (low + high)/2;
		j = (midd%matrix[0].size()+matrix[0].size()-1)%matrix[0].size();
		i = midd/matrix[0].size();
		if(midd%matrix[0].size()==0)
			i = i-1;
		while(low <= high)
		{
			if(matrix[i][j]==target)
				return true;
			if(matrix[i][j]>target)
			{
				high = midd - 1;
				midd = (low + high)/2;
				j = (midd%matrix[0].size()+matrix[0].size()-1)%matrix[0].size();
				i = midd/matrix[0].size();
				if(midd%matrix[0].size()==0)
					i = i-1;
			}
			else
			{
				low = midd + 1;
				midd = (low + high)/2;
				j = (midd%matrix[0].size()+matrix[0].size()-1)%matrix[0].size();
				i = midd/matrix[0].size();
				if(midd%matrix[0].size()==0)
					i = i-1;
			}
		}
		return false;
	}
};