class Solution {
	vector<TreeNode*> a;
	vector<TreeNode*> b;
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<int> tmp;
		vector<vector<int> >result;
		if(!root)
			return result;
		a.push_back(root);
		while(a.size())
		{
			tmp.clear();
			for(int i = 0;i<a.size();i++)
			{
				tmp.push_back(a[i]->val);
			}
			b.clear();
			for(int i = 0;i<a.size();i++)
			{
				if(a[i]->left)
					b.push_back(a[i]->left);
				if(a[i]->right)
					b.push_back(a[i]->right);
			}
			result.push_back(tmp);
			a = b;
		}
		return result;
	}
};