class Solution {
public:
	bool isPalindrome(int x) {
	    if(x<0)
	    return false;
		int a,b;
		a = x;
		b = 0;
		while(x)
		{
			b=b*10+x%10;
			x/=10;
		}
		if(a==b)
			return true;
		return false;
	}
};