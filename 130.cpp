class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if(board.size()==NULL)
			return;
		vector<vector<int>> tmp;
		tmp.resize(board.size());
		for(int i=0;i<board.size();i++)
		{
			tmp[i].resize(board[0].size(),0);
		}
		for(int i=0;i<board[0].size();i++)
		{
			if(board[0][i]=='O')
			{
				breadfirstseach(board,tmp,0,i);
			}
			if(board[board.size()-1][i]=='O')
			{
				breadfirstseach(board,tmp,board.size()-1,i);
			}
		}
		for(int i=0;i<board.size();i++)
		{
			if(board[i][0]=='O')
			{
				breadfirstseach(board,tmp,i,0);
			}
			if(board[i][board[0].size()-1]=='O')
			{
				breadfirstseach(board,tmp,i,board[0].size()-1);
			}
		}
		for (int i = 0;i<board.size();i++)
		{
			for (int j = 0;j<board[0].size();j++)
			{
				if(board[i][j]=='O'&&tmp[i][j]==0)
					board[i][j] = 'X';
			}
		}
	}
	void breadfirstseach(vector<vector<char>>& board,vector<vector<int>>& tmp,int i,int j)
	{
		queue<pair<int,int>> q;
		q.push(make_pair(i,j));
		tmp[i][j] = 1;
		pair<int,int> ptm;
		while(!q.empty())
		{
			ptm = q.front();
			q.pop();
			if((ptm.first+1)<board.size()&&board[ptm.first+1][ptm.second]=='O'&&tmp[ptm.first+1][ptm.second]==0)
			{
				q.push(make_pair(ptm.first+1,ptm.second));
				tmp[ptm.first+1][ptm.second] = 1;
			}
			if((ptm.first-1)>=0&&board[ptm.first-1][ptm.second]=='O'&&tmp[ptm.first-1][ptm.second]==0)
			{
				q.push(make_pair(ptm.first-1,ptm.second));
				tmp[ptm.first-1][ptm.second] = 1;
			}
			if((ptm.second+1)<board[0].size()&&board[ptm.first][ptm.second+1]=='O'&&tmp[ptm.first][ptm.second+1]==0)
			{
				q.push(make_pair(ptm.first,ptm.second+1));
				tmp[ptm.first][ptm.second+1] = 1;
			}
			if((ptm.second-1)>=0&&board[ptm.first][ptm.second-1]=='O'&&tmp[ptm.first][ptm.second-1]==0)
			{
				q.push(make_pair(ptm.first,ptm.second-1));
				tmp[ptm.first][ptm.second-1] = 1;
			}
		}
	}
};