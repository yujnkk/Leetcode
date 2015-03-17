class Solution {
	bool flags;
public:
	bool hasPathSum(TreeNode *root, int sum) {
		int count = 0;
		flags = false;
		if(!root)
			return false;
		depthfirst(root,0,sum);
		return flags;
	}
	void depthfirst(TreeNode *root,int count,int sum)
	{
		
		if(!root)
		{		
			return;	
		}
		depthfirst(root->left,count+root->val,sum);
		depthfirst(root->right,count+root->val,sum);
		if(isleaf(root))
		{
			if(count+root->val==sum)
				flags = true;
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