class Solution {
	public:
		void moveZeroes(vector<int>& nums) {
			int len = nums.size();
			int left = 0, curr = 0;
			while (left < len) {
				while (left < len && nums[left] == 0) left++;
				if (left < len) {
					swap(nums[left], nums[curr]);
					left++;
					curr++;
				}
			}
		}
};
