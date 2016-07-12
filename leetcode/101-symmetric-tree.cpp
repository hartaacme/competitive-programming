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
	private:
		bool isMirror(TreeNode *t1, TreeNode *t2) {
			if (t1 == NULL) return t2 == NULL;
			if (t2 == NULL) return t1 == NULL;
			if (t1->val != t2->val) return false;
			return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
		}

	public:
		bool isSymmetric(TreeNode* root) {
			if (root == NULL) return true;
			return isMirror(root->left, root->right);
		}
};
