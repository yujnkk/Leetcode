class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {		
		vector<map<int,int> > mat,col,row;
		map<int,int> tmp;
		if(board.size()!=board[0].size())
		{
			return false;
		}
		for (int i = 0;i<board.size();i++)
		{
			mat.push_back(tmp);
			col.push_back(tmp);
			row.push_back(tmp);
		}
		for(int i = 0;i<board.size();i++)
			for(int j = 0;j<board[0].size();j++)
			{
				if(board[i][j]=='.')
					continue;
				if(++col[i][board[i][j]-'0']==2)
					return false;
				if(++row[j][board[i][j]-'0']==2)
					return false;
				if(++mat[(i/3)*3+j/3][board[i][j]-'0']==2)
					return false;
			}
		return true;
	}
};