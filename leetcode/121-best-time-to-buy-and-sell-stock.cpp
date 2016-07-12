class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			int ans = 0, mini;
			if (prices.size() > 0) {
				mini = prices[0];
			}
			for (int i = 1; i < prices.size(); i++) {
				ans = max(prices[i] - mini, ans);
				mini = min(prices[i], mini);
			}
			return ans;
		}
};
