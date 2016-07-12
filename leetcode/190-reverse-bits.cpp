class Solution {
	public:
		uint32_t reverseBits(uint32_t n) {
			uint32_t res = 0;
			int curr = 31;
			while (n) {
				if (n % 2) res += 1 << curr;
				curr--;
				n /= 2;
			}
			return res;
		}
};
