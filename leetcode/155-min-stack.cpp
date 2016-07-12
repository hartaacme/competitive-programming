class MinStack {
	public:
		/** initialize your data structure here. */
		stack<pair<int, int> > stk;
		MinStack() {
		}

		void push(int x) {
			int mini;
			if (stk.size() == 0) mini = x;
			else {
				pair<int, int> top = stk.top();
				mini = min(x, top.second);
			}
			stk.push(make_pair(x, mini));
		}

		void pop() {
			stk.pop();
		}

		int top() {
			pair<int, int> top = stk.top();
			return top.first;
		}

		int getMin() {
			pair<int, int> top = stk.top();
			return top.second;
		}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
