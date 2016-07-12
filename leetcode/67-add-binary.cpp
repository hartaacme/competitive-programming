class Solution {
	public:
		string addBinary(string a, string b) {
			int lenA = a.length();
			int lenB = b.length();
			if (lenA == 0) return b;
			if (lenB == 0) return a;
			string res = "";
			int carry = 0, vA = 0, vB = 0;
			while (lenA || lenB) {
				if (lenA) vA = a[--lenA] - '0';
				else vA = 0;
				if (lenB) vB = b[--lenB] - '0';
				else vB = 0;
				int tot = vA + vB + carry;
				res = (char)(tot % 2 + '0') + res;
				carry = tot / 2;
			}
			if (carry) res = (char)(carry + '0') + res;
			return res;
		}
};
