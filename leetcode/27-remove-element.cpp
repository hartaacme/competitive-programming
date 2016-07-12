class Solution {
	public:
		int removeElement(vector<int>& nums, int val) {
			int curr = 0;
			int tot = nums.size();
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] != val) {
					swap(nums[curr], nums[i]);
					curr++;
				} else tot--;
			}
			return tot;
		}
};
