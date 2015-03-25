class Solution {
public:
	int divide(int div, int divs) {
		long long dividend = div;
		long long divisor =divs;
		if(divisor==1)
			return dividend;
		if(divisor==-1)
		{
			if(dividend==-2147483648)
				return 2147483647;
			return -dividend;
		}
		if(divisor==0)
			return 2147483647;
		bool flag = false;
		if(dividend>0&&divisor<0)
			flag = true;
		if(divisor>0&&dividend<0)
			flag = true;
		dividend = abs(dividend);		
		divisor = abs(divisor);
		if(dividend<divisor)
			return 0;
		if(divisor==dividend)
		{
			if(flag)
				return -1;
			return 1;
		}
		long long low = 1,high = 1;
		int result=0;
		long long tm = divisor;
		while(dividend>0)
		{	
			high = 1;
			tm = divisor;
			while(tm<=dividend)
			{
				high = high<<1;
				tm = tm<<1;
			}
			low = high>>1;
			tm = tm>>1;
			result+=low;
			dividend -=tm;
		}

		/*int i,j;
		for(i=low;i<high;i++)
		{
			tm+=divisor;
			if(tm>dividend)
				break;
		}*/
		if(flag)
			return -result;
		return result;
	}
};