class Solution {
	private:
		int ugly[3] = {2, 3, 5};
	public:
		bool isUgly(int num) {
			if (num == 0) return false;
			int len = sizeof(ugly) / sizeof(int);
			for (int i = 0; i < len; i++) {
				while (num % ugly[i] == 0) num /= ugly[i];
			}
			return num == 1;
		}
};
