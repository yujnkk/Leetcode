class Solution {
public:
	int sqrt(int x) {
		int low,high,midd;
		low = 0;
		high = x;
		midd = (int)(low + high)/2;
		while(low<=high)
		{
			if(midd*midd==x)
				return (int)midd;
			else if(midd*midd > x||midd >= 46341)
			{				
				high = midd - 1;
				midd = (int)(low + high)/2;
			}
			else
			{				
				low = midd + 1;
				midd = (int)(low + high)/2;
			}
		}
		return midd;

	}
};