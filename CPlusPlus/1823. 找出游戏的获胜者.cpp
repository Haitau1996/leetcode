// 使用环形链表模拟， 记得是从 1 数数到 k-1, 然后删除下一个点
struct my_node {
	int val;
	my_node* prev;
	my_node* next;
	my_node(int val)
		: val(val)
		, prev(nullptr)
		, next(nullptr)
	{
	}
};
class Solution {
	using my_list = my_node*;
	using nodeptr = my_node*;

public:
	int findTheWinner(int n, int k)
	{
		if (k == 1)
			return n;
		for (int i = 1; i <= n; ++i) {
			add(i);
		}
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < k - 1; ++j) {
				head = head->next;
			}
			delete_next(head);
			head = head->next;
		}
		return head->val;
	}

private:
	my_list head { nullptr };
	void add(int value)
	{
		if (head == nullptr) {
			head = new my_node(value);
			head->prev = head;
			head->next = head;
			return;
		} else {
			nodeptr tail = head->prev;
			tail->next = new my_node(value);
			tail->next->next = head;
			tail->next->prev = tail;
			head->prev = tail->next;
		}
	}
	void delete_next(nodeptr curr)
	{
		nodeptr to_delete = curr->next;
		nodeptr next = curr->next->next;
		next->prev = curr;
		curr->next = next;
		delete to_delete;
	}
};
