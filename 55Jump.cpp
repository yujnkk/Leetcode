class Solution {
	bool flags;
public:
	bool canJump(int A[], int n) {
		int i,count;
		flags = true;
		if(n==0)
			return false;
		if(n==1)
			return true;
		for(i=n-2;i>=0;i--)
		{
			if(A[i]==0)
			{
				flags = false;
				count = 0;
				while(true)
				{
					i--;
					count++;
					if(i<0)
						break;
					if(A[i]>count)
					{
						flags = true;
						break;
					}
				}
			}
		}
		return flags;
	}
};