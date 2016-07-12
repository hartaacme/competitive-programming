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
		map<TreeNode*, int> mp;

	public:
		bool isBalanced(TreeNode* root) {
			if (root == NULL) {
				mp[root] = 0;
				return true;
			}
			if (!isBalanced(root->left)) return false;
			if (!isBalanced(root->right)) return false;
			int leftHeight = mp[root->left];
			int rightHeight = mp[root->right];
			if (abs(leftHeight - rightHeight) > 1) return false;
			mp[root] = 1 + max(leftHeight, rightHeight);
			return true;
		}
};
