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
	public:
		bool isSymmetric(TreeNode* root) {
			if (root == NULL) return true;
			if (root->left == NULL) return root->right == NULL;
			if (root->right == NULL) return root->left == NULL;
			stack<TreeNode*> stk;
			stk.push(root->left);
			stk.push(root->right);
			while (!stk.empty()) {
				TreeNode* t1 = stk.top();
				stk.pop();
				TreeNode *t2 = stk.top();
				stk.pop();
				if (t1 == NULL) {
					if (t2 == NULL) continue;
					return false;
				}
				if (t2 == NULL) {
					if (t1 == NULL) continue;
					return false;
				}
				if (t1->val != t2->val) return false;
				stk.push(t1->left);
				stk.push(t2->right);
				stk.push(t1->right);
				stk.push(t2->left);
			}
			return true;
		}

};
