class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> result;		
		int h = matrix.size();
		if(h==0)
			return result;
		int l = matrix[0].size();
		bianli(0,l,0,h,result,matrix);
		return result;
	}
	void bianli(int lrow,int hrow,int lcolumn,int hcolumn,vector<int>&result,vector<vector<int> > &matrix)
	{
		if(((hcolumn-lcolumn)<=0)||((hrow-lrow)<=0))
			return;
		int j=lrow,i=lcolumn;
		result.push_back(matrix[i][j]);
		while(++j<hrow)
		{
			result.push_back(matrix[i][j]);
		}
		j--;
		while(++i<hcolumn)
		{
			result.push_back(matrix[i][j]);
		}
		i--;
		while(--j>=lrow&&(hcolumn-lcolumn)>1)
		{
			result.push_back(matrix[i][j]);
		}
		j++;
		while(--i>lcolumn&&(hrow-lrow)>1)
		{
			result.push_back(matrix[i][j]);
		}
		bianli(lrow+1,hrow-1,lcolumn+1,hcolumn-1,result,matrix);
	}
};