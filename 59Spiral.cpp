class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > matrix;
		vector<int> temp;
		int count = 0;
		temp.resize(n,0);
		int i;
		for(i=0;i<n;i++)
			matrix.push_back(temp);
		bianli(0,n,0,n,count,matrix);
		return matrix;					
	}
	void bianli(int lrow,int hrow,int lcolumn,int hcolumn,int count,vector<vector<int> > &matrix)
	{
		if(((hcolumn-lcolumn)<=0)||((hrow-lrow)<=0))
			return;
		int j=lrow,i=lcolumn;
		count++;
		matrix[i][j] = count;
		while(++j<hrow)
		{
			matrix[i][j] = ++count;
		}
		j--;
		while(++i<hcolumn)
		{
			matrix[i][j] = ++count;
		}
		i--;
		while(--j>=lrow&&(hcolumn-lcolumn)>1)
		{
			matrix[i][j] = ++count;
		}
		j++;
		while(--i>lcolumn&&(hrow-lrow)>1)
		{
			matrix[i][j] = ++count;
		}
		bianli(lrow+1,hrow-1,lcolumn+1,hcolumn-1,count,matrix);
	}
};
