class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int pre=0,cur=1;
        if(n == 0)
        return 0;
        while(cur<n)
        {
            if(A[cur]==A[pre])
            {
                cur++;
            }
            else
            {
                pre++;
                A[pre] = A[cur];
            }
        }
        return pre+1;
    }
};