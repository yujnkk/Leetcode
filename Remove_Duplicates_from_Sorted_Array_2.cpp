class Solution {
public:
	  int removeDuplicates(int A[], int n) {
		  int pre = 0,cur = 0,count;
		  if(n == 0)
			  return 0;
		  while(cur < n)
		  {
			  A[pre] = A[cur];
			  count = 0;
			  while((A[pre]==A[cur])&&cur < n)
			  {
					cur++;
					count++;
			  }
			  if(count>=2)
			  {
					A[pre++] = A[cur - 1];
					A[pre++] = A[cur - 1];

			  }
			  else
			  {
					A[pre++] = A[cur - 1];
			  }
		  }	
		  return pre;
	  }
  };