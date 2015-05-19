/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	bool flag;
	long long cur;
public:
	bool isValidBST(TreeNode* root) {
		cur = -2487878787878;
		flag = true;
		depthserach(root);
		return flag;
	}
	void depthserach(TreeNode * root)
	{
		if(!flag||!root)
			return;
		/*if(root->left&&root->left->val>=root->val)
			flag = false;
		if(root->right&&root->right->val<=root->val)
			flag = false;*/
		depthserach(root->left);
		if(cur>=root->val)
			flag = false;
		else
			cur = root->val;
		depthserach(root->right);
	}
};

