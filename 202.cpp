class Solution {
public:
	bool isHappy(int n) {
		map<int,int> m;
		int tmp;
		while(n!=1)
		{
			m[n]++;
			if(m[n]==2)
				return false;
			tmp = 0;
			while(n)
			{
				tmp += pow((n%10),2.0);
				n/=10;
			}
			n = tmp;
		}
		return true;

	}
};