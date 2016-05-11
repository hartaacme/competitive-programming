class Solution {
	public:
		pair<int, int> get_kth(vector<int> &nums1, vector<int> &nums2, int pos) {
			int lo1 = 0, hi1 = nums1.size() - 1, ans = -1, tot = 1000000000;
			while (lo1 <= hi1) {
				int mid1 = lo1 + (hi1 - lo1) / 2;
				int lo2 = 0, hi2 = nums2.size() - 1, ans2 = -1;
				while (lo2 <= hi2) {
					int mid2 = lo2 + (hi2 - lo2) / 2;
					if (nums2[mid2] <= nums1[mid1]) {
						ans2 = mid2;
						lo2 = mid2 + 1;
					} else {
						hi2 = mid2 - 1;
					}
				}
				if (mid1 + ans2 + 2 >= pos + 1) {
					ans = nums1[mid1];
					tot = mid1 + ans2;
					hi1 = mid1 - 1;
				} else {
					lo1 = mid1 + 1;
				}
			}
			return {ans, tot};
		}

		int get_precise_kth(vector<int> &nums1, vector<int> &nums2, int pos) {
			pair<int, int> ans1 = get_kth(nums1, nums2, pos);
			pair<int, int> ans2 = get_kth(nums2, nums1, pos);
			if (ans1.second < ans2.second) return ans1.first;
			return ans2.first;
		}

		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int m = nums1.size();
			int n = nums2.size();
			int tot = (m + n);
			if (tot % 2 == 1) {
				return get_precise_kth(nums1, nums2, tot / 2);
			} else {
				return (get_precise_kth(nums1, nums2, tot / 2 - 1) + get_precise_kth(nums1, nums2, tot / 2)) / 2.0;
			}
		}
};
