class Solution {
	vector<int> leafnum;
public:
	int sumNumbers(TreeNode *root) {
		int count = 0;
		leafnum.clear();
		if(!root)
			return 0;
		depthfirst(root,0);
		for(int i=0;i<leafnum.size();i++)
		{
			count+=leafnum[i];
		}
		return count;
	}
	void depthfirst(TreeNode *root,int count)
	{
		
		if(!root)
		{		
			return;	
		}
		depthfirst(root->left,count*10+root->val);
		depthfirst(root->right,count*10+root->val);
		if(isleaf(root))
		{
			leafnum.push_back(count*10+root->val);
		}

	}
	bool isleaf(TreeNode *root)
	{
		if(!root->left&&!root->right)
			return true;
		else
			return false;
	}
};