class MinStack {
	stack<pair<int, int>> stk;
public:
    MinStack() { }
    
    void push(int x) {
		int mn = stk.empty() ? x : min(stk.top().second, x);
		stk.push(make_pair(x, mn));
    }
    
    void pop() {
		stk.pop();
    }
    
    int top() {
		return stk.top().first;
    }
    
    int getMin() {
		return stk.top().second;
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
