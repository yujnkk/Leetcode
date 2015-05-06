class Solution {
	int result;
public:
	int totalNQueens(int n) {
		vector<int> X;
		X.resize(n+1,0);
		result = 0;
		Nqueens(n,X);
		return result;
	}
	bool place(int k, vector<int>& X)
	{
		int i;
		i=1;
		while(i<k)
		{
			if((X[i]==X[k])||(abs(X[i]-X[k])==abs(i-k)))
				return false;
			i++;
		}
		return true;
	}
	void Nqueens(int n,vector<int>& X)
	{
		int k;
		X[1]=0;k=1;
		while(k>0)
		{
			X[k]=X[k]+1; 
			while((X[k]<=n)&&(!place(k, X)))
				X[k]=X[k]+1;                    
			if(X[k]<=n)   
				if(k==n)   
				{
					result++;					
				}
				else    
				{
					k=k+1;
					X[k]=0;
				}
			else
				k=k-1;  
		}
	}
};