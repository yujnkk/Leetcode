class Solution {
public:
	void rotate(int nums[], int n, int k) {
		if(n==0||n==1)
			return;
		k = k%n;
		revs(nums,1,n);
		revs(nums,1,k);
		revs(nums,k+1,n);		
	}
	void revs(int nums[],int low,int high)
	{
		int i,j,t;
		i = low - 1;
		j = high -1;
		while(i<j)
		{
			t = nums[i];
			nums[i] = nums[j];
			nums[j] = t;
			i++;
			j--;
		}
	}
};