// 字典树 + DFS

#include <string>
#include <vector>

using namespace std;
struct Trie {
	int _val;
	vector<Trie*> children;
	Trie()
		: _val(0)
		, children(vector<Trie*>(26, nullptr))
	{
	}
};
class MapSum {
	using TPtr = Trie*;

public:
	MapSum()
	{
		root = new Trie();
	}

	void insert(string key, int val)
	{
		TPtr cursor = root;
		for (const auto c : key) {
			if (cursor->children[c - 'a'] == nullptr) {
				cursor->children[c - 'a'] = new Trie();
			}
			cursor = cursor->children[c - 'a'];
		}
		cursor->_val = val;
	}

	int sum(string prefix)
	{
		int res = 0;
		TPtr cursor = root;
		for (const auto c : prefix) {
			if (cursor == nullptr)
				return 0;
			cursor = cursor->children[c - 'a'];
		}
		return dfs(cursor);
	}

private:
	TPtr root;
	int dfs(TPtr curr)
	{
		int res = 0;
		if (curr == nullptr)
			return res;
		for (auto p : curr->children)
			res += dfs(p);
		res += curr->_val;
		return res;
	}
};
