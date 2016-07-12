#include <bits/stdc++.h>
using namespace std;

class Solution {
	private:
		bool match(char c1, char c2) {
			if (c1 == '(') return c2 == ')';
			if (c1 == '{') return c2 == '}';
			if (c1 == '[') return c2 == ']';
			return false;
		}

	public:
		bool isValid(string s) {
			int len = s.length();
			stack<char> stk;
			for (int i = 0; i < len; i++) {
				if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
					stk.push(s[i]);
				} else {
					if (stk.empty()) return false;
					char top = stk.top();
					stk.pop();
					if (!match(top, s[i])) return false;
				}
			}
			return stk.size() == 0;
		}
};
