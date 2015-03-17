class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int i,j,k;
		for(i = m-1;i>=0;i--)
		{
			A[i+n]=A[i];
		}
		i = 0;
		j = 0;
		k = 0;
		while(true)
		{
			if(k>m+n)
				break;			
			if(j==n)
				break;			
			if(A[i+n]<B[j]&&i!=m)
			{
				A[k] = A[i+n];
				i++;
			}
			else
			{
				A[k] = B[j];
				j++;
			}
			k++;
		}
		return;
	}
};