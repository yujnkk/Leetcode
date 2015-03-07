class Solution {
public:
	int search(int A[], int n, int target) {
		int low,high,midd;
		int max,min;
		min = A[0]<A[n-1]?A[0]:A[n-1];
		max = A[0]>A[n-1]?A[0]:A[n-1];
		low = 0;
		high = n - 1;	
		while(low <= high)
		{
			midd = (low + high)/2;
			if(target == A[midd])
				return midd;
			if(min<target)
			{
				if(A[midd]<min)
				{
					if(A[0] == max)
					high = midd - 1;
					else
					{
						low = midd + 1;
					}
				}
				else
				{
					if(target>A[midd])
					{
						low = midd + 1;
					}
					else
					{
						high = midd - 1;
					}
				}
			}
			else
			{
				if(A[midd]>min)
				{
					if(A[0] == min)
						high = midd - 1;
					else
					{
						low = midd + 1;
					}
				}
				else
				{
					if(target>A[midd])
					{
						low = midd + 1;
					}
					else
					{
						high = midd - 1;
					}
				}
			}		
		}
		return -1;
	}
};