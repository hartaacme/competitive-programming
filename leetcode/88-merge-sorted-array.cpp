class Solution {
	public:
		void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
			int curr = m + n - 1;
			while (curr >= 0) {
				if (m - 1 < 0) {
					nums1[curr--] = nums2[n - 1];
					n--;
				} else if (n - 1 < 0) {
					nums1[curr--] = nums1[m - 1];
					m--;
				} else if (nums2[n - 1] >= nums1[m - 1]) {
					nums1[curr--] = nums2[n - 1];
					n--;
				} else {
					nums1[curr--] = nums1[m - 1];
					m--;
				}
			}
		}
};
