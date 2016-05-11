#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int len = s.length(), ans = 0;
			int pos[128] = {0};
			int left = 0;
			for (int i = 0; i < len; i++) {
				left = max(pos[s[i]], left);
				ans = max(ans, i - left + 1);
				pos[s[i]] = i + 1;
			}
			return ans;
		}
};

int main() {
	return 0;
}
