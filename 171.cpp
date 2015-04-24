class Solution {
public:
	string convertToTitle(int n) {
		string result;		
		while(n)
		{
			n-=1;			
			result.insert(result.begin(),n%26+65);
			n/=26;
		}
		return result;
	}
};