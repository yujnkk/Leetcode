class Solution {
	vector<int> seri1;
	vector<int> seri2;
public:
    bool isSymmetric(TreeNode *root) {
        Depthfirst1(root);
		Depthfirst2(root);
		if(seri1.size()==0)
		return true;
		if(seri1.size()%2==0)
			return false;
		int i = seri1.size()/2;
		for(int j=0;j<=i;j++)
		{
			if(seri1[j]!=seri2[j])
				return false;
		}
		return true;
    }
	void Depthfirst1(TreeNode *root)
	{
		if(root==NULL)
		{	
		    seri1.push_back(666);
			return;
		}
		Depthfirst1(root->left);
		Depthfirst1(root->right);
		seri1.push_back(root->val);
	}
	void Depthfirst2(TreeNode *root)
	{
		if(root==NULL)
		{
		    seri2.push_back(666);
			return;
		}
		Depthfirst2(root->right);
		Depthfirst2(root->left);
		seri2.push_back(root->val);
	}
};