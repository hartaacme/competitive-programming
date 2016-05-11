/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode* head1 = l1;
			if (!l1) return l2;
			if (!l2) return l1;
			int carry = 0;
			while (l2 || carry) {
				int s1 = 0, s2 = 0;
				if (l1) s1 = l1->val;
				if (l2) s2 = l2->val;
				l1->val = (s1 + s2 + carry);
				carry = l1->val / 10;
				l1->val = l1->val % 10;
				if (l2) {
					l2 = l2->next;
				}
				if (!l1->next) {
					if (l2 || carry) {
						l1->next = new ListNode(0);
					}
				}
				l1 = l1->next;
			}
			return head1;
		}
};
