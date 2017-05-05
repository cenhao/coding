class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		auto cmp = [&lists] (int a, int b) -> bool {
			return lists[a]->val > lists[b]->val;
		};
		priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
		ListNode *head = new ListNode(0);
		ListNode *rear = head;

		for (int i=0; i<lists.size(); ++i) {
			if (lists[i] != NULL) { pq.push(i); }
		}

		while (!pq.empty()) {
			int tmp = pq.top(); pq.pop();
			rear->next = lists[tmp];
			rear = rear->next;
			lists[tmp] = lists[tmp]->next;

			if (lists[tmp] != NULL) { pq.push(tmp); }
		}

		rear = head;
		head = head->next;
		delete rear;
		return head;
	}
};
