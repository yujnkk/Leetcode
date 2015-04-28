class Solution {
	int depth;
public:
	int minDepth(TreeNode *root) {
		depth = 99999999;
		if(root==NULL)
			return 0;
		if(!root->left&&!root->right)
			return 1;
		if(root->left)
			inordersearch(root->left,1);
		if(root->right)
			inordersearch(root->right,1);
		return depth;
	}
	void inordersearch(TreeNode * root,int dep)
	{
		if(!root->left&&!root->right)
		{
			depth = depth<(dep+1)?depth:(dep+1);
			return ;
		}
		if(root->left)
			inordersearch(root->left,dep+1);
		if(root->right)
			inordersearch(root->right,dep+1);
	}
};