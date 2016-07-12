class Solution {
	public:
		int rob(vector<int>& nums) {
			int sz = nums.size();
			if (sz == 0) return 0;
			int dp[sz][2];
			memset(dp, 0, sizeof(dp));
			dp[0][0] = 0; dp[0][1] = nums[0];
			for (int i = 1; i < sz; i++) {
				dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
				dp[i][1] = dp[i - 1][0] + nums[i];
			}
			return max(dp[sz - 1][0], dp[sz - 1][1]);
		}
};
