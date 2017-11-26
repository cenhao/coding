class Solution {
public:
	unordered_map<string, stack<int>> vm;
	void proc_left_value(int state, int sv, int &val) {
		val = sv;
	}

	void proc_right_value(int state, int sv, string &lst_name, unordered_set<string> &lm, int &val) {
		if (state == 1) {
			if (lst_name == "*") {
				val = sv;
				return;
			}
			auto sit = vm.find(lst_name);
			if (sit == vm.end()) {
				sit = vm.insert(make_pair(lst_name, stack<int>())).first;
			}
			auto it = lm.find(lst_name);
			if (it == lm.end()) {
				sit->second.push(sv);
				lm.insert(lst_name);
			} else {
				sit->second.top() = sv;
			}

			lst_name = "*";
		} else {
			if (lst_name == "*") {
				val = state == 3 ? (val + sv) : (val * sv);
			} else {
				if (state == 3) {
					val = (vm[lst_name].top() + sv);
				} else {
					val = (vm[lst_name].top() * sv);
				}
			}
		}
	}

	int process(const string &exp, int pos, int &val) {
		unordered_set<string> lm;
		int state = 0; // 0 unknown, 1 let assign, 2 let eval, 3 add, 4 mul
		int len = exp.length();
		bool left = true;
		string lst_name = "*";
		for (int i=pos; i<len; ++i) {
			if (exp[i] == ' ') {
				continue;
			} else if (exp[i] == '(') {
				int sv;
				i = process(exp, i+1, sv) - 1;
				if (left) {
					proc_left_value(state, sv, val);
				} else {
					proc_right_value(state, sv, lst_name, lm, val);
				}
				left = !left;
			} else if (exp[i] == ')') {
				for (auto &n : lm) { vm[n].pop(); }
				return i + 1;
			} else if (state == 0) {
				if (exp[i] == 'l') {
					state = 1;
					i += 3;
				} else if (exp[i] == 'a') {
					state = 3;
					i += 3;
				} else if (exp[i] == 'm') {
					state = 4;
					i += 4;
				}
			} else  {
				string tmp;
				while (i < len && exp[i] != ' ' && exp[i] != '(' && exp[i] != ')') { tmp += exp[i++]; }
				if (exp[i] != ' ') { --i; }

				int sv;
				if (tmp[0] == '-' || (tmp[0] >= '0' && tmp[0] <= '9')) {
					sv = stoi(tmp);
				} else {
					if (left) { lst_name = tmp; }
					if (vm.find(tmp) != vm.end()) {
						sv = vm[tmp].top();
					}
				}
				if (left) {
					proc_left_value(state, sv, val);
				} else {
					proc_right_value(state, sv, lst_name, lm, val);
				}
				left = !left;
			}
		}

		return -1;
	}

	int evaluate(string expression) {
		int val;
		process(expression, 0, val);
		return val;
	}
};
