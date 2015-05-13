class Solution {
	vector<vector<int>> result;
public:
	vector<vector<int>> combine(int n, int k) {
		int * B = new int[k+1];
		comb(n,B,k);
		return result;

	}
	void comb(int & n,int * B,int &size)
	{
		int k = 1;
		B[1] = 0;
		while(k>0)
		{
			B[k] = B[k] + 1;
			if(B[k]<=n)
				if(k == size)
				{
					vector<int> tmp(B+1,B+1+size);
					result.push_back(tmp);
				}
				else
				{
					k = k+1;
					B[k] = B[k-1];
				}
			else
				k = k-1;
		}
	}
};
