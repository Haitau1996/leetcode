// 简单的字典树应用
#include <sstream>
#include <string>
#include <vector>

using namespace std;
struct Trie {
	bool has_word;
	vector<Trie*> children;
	Trie()
		: has_word(false)
		, children(vector<Trie*>(26, nullptr))
	{
	}
};
class Solution {
public:
	string replaceWords(vector<string>& dictionary, string sentence)
	{
		root = new Trie();
		for (const auto& w : dictionary) {
			insert(w);
		}
		string res {};
		istringstream ss(sentence);
		string temp {};
		while (getline(ss, temp, ' ')) {
			auto r = lookup(temp);
			if (r.size() == 0) {
				res += temp;
			} else {
				res += r;
			}
			res.push_back(' ');
		}
		res.pop_back();
		return res;
	}

private:
	Trie* root { nullptr };
	void insert(const string& s)
	{
		Trie* cursor = root;
		for (const auto& c : s) {
			if (cursor->children[c - 'a'] == nullptr) {
				cursor->children[c - 'a'] = new Trie();
			}
			cursor = cursor->children[c - 'a'];
		}
		cursor->has_word = true;
	}
	string lookup(const string& in)
	{
		int i = 0;
		Trie* cursor = root;
		while (i < in.size()) {
			if (cursor == nullptr) {
				return string {};
			} else if (cursor->has_word) {
				break;
			} else {
				cursor = cursor->children[in[i++] - 'a'];
			}
		}
		return in.substr(0, i);
	}
};
