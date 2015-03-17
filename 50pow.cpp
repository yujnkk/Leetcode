class Solution {
public:
	double pow(double x, int n) {
		if(n==0)
			return 1;
		if(n==1)
			return  x;
		if(n==-1) 
			return 1/x;
		if(n%2==0)
		{
		    double t;
		    t = pow(x,n/2);
			return t*t;
		}
		else
		{
		    double t;
		    t  = pow(x,n/2);
			if(n>0)
			return t*t*x;
			else
			return t*t/x;
		}

	}
};