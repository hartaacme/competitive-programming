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
		ListNode* deleteDuplicates(ListNode* head) {
			if (head == NULL) return head;
			ListNode* curr = head;
			ListNode* next = curr->next;
			while (next) {
				if (curr->val != next->val) {
					curr->next = next;
					curr = curr->next;
				} else {
					next = next->next;
				}
			}
			return head;
		}
};
