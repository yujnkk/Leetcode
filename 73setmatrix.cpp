class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int i,j;
		for(i=0;i<matrix.size();i++)
			for(j=0;j<matrix[0].size();j++)
			{
				if(matrix[i][j] == 0)
					setz(matrix,i,j);
			}
			doz(matrix);
	}
	void setz(vector<vector<int> >&matrix,int i,int j)
	{
		int x,y;
		x = 0;
		y = 0;
		while(x<matrix.size())
		{
		    if(matrix[x][j]!=0)
			matrix[x][j] = -198357;
			x++;
		}
		while(y<matrix[0].size())
		{
		    if(matrix[i][y]!=0)
			matrix[i][y] = -198357;
			y++;
		}
	}
	void doz(vector<vector<int> >&matrix)
	{
		int i,j;
		for(i=0;i<matrix.size();i++)
			for(j=0;j<matrix[0].size();j++)
			{
				if(matrix[i][j]==-198357)
					matrix[i][j] = 0;
			}   
	}
};