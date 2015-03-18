class Solution {
public:
	int jump(int A[], int n) {
		vector<int> B;
		if(n==1)
			return 0;
		if(n<=2)
			return 1;
		B.resize(n,0);
		int i,j,tm;
		int flags;
		B[n-2] = 1;
		flags = n-2;
		for(i=n-3;i>=0;i--)
		{
			B[i] = B[i+1] + 1;			
			if(A[i]>=n-1-i)
			{
				B[i] = 1;
				flags = i;
				continue;

			}
			if(A[i]>=flags - i  )
			{
				B[i] = 2;
				continue;
			}
			tm = 99999;
			for(j=i+1;j<=i+A[i];j++)
			{
				tm = tm<B[j]?tm:B[j];

			}
			if(tm!=99999)
				B[i] = tm+1;

		}
		return B[0];
	}
};