class Solution {
	vector<int> path;
	vector<vector<int> >result;
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		//int count = 0;	
		result.clear();
		depthfirst(root,0,sum);
		return result;
		
		
	}
	void depthfirst(TreeNode *root,int count,int sum)
	{

		if(!root)
		{		
			return;	
		}
		path.push_back(root->val);
		depthfirst(root->left,count+root->val,sum);
		depthfirst(root->right,count+root->val,sum);
		if(isleaf(root))
		{
			if(count+root->val==sum)
				result.push_back(path);			
		}
		path.pop_back();
	}
	bool isleaf(TreeNode *root)
	{
		if(!root->left&&!root->right)
			return true;
		else
			return false;
	}
};