/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    vector<int> result;
    vector<int>::iterator it;
public:
    BSTIterator(TreeNode *root) {
        inorder(root);
        it = result.begin();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(it<result.end())
        return true;
        return false;
    }

    /** @return the next smallest number */
    int next() {
        return *it++;
    }
    void inorder(TreeNode * root)
    {
        if(!root)
        return;
        inorder(root->left);
        result.push_back(root->val);
        inorder(root->right);
    }
    
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */