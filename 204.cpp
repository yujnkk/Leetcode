class Solution {
public:
	int countPrimes(int n) {
	    n -=1;
		if(n<2)
			return 0;
		vector<int> in(n+1,1);
		int i,j;
		double s,p;
		s = sqrt((double)n);
		p = pow((double)i,2.);
		for(i=2;i<=s;i++)
		{
			if(in[i]==1)
				for(j=p;j<=n;j=j+i)
				{
					in[j]=0;
				}
		}
		int result = 0;
		for(i=2;i<=n;i++)
		{	
			if(in[i]==1)
				result++;
		}
		return result;
	}
};