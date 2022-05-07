#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank)
    {
        if (start == end)
            return 0;
        unordered_map<string, unordered_set<string>> map;
        queue<string> curr;
        queue<string> next;
        unordered_set<string> checked {};
        for (int i = 0; i < bank.size(); ++i) {
            for (int j = i + 1; j < bank.size(); ++j) {
                if (check_path(bank[i], bank[j])) {
                    if (map.find(bank[i]) == map.end()) {
                        map.emplace(bank[i], unordered_set<string>());
                    }
                    map[bank[i]].insert(bank[j]);
                    if (map.find(bank[j]) == map.end()) {
                        map.emplace(bank[j], unordered_set<string>());
                    }
                    map[bank[j]].insert(bank[i]);
                }
            }
            if (check_path(start, bank[i])) {
                curr.push(bank[i]);
                checked.insert(bank[i]);
            }
        }
        int ret { 1 };

        while (!curr.empty()) {
            auto front = curr.front();
            curr.pop();
            if (front == end)
                return ret;
            for (const auto& elem : map[front]) {
                if (checked.find(elem) == checked.end()) {
                    next.push(elem);
                    checked.insert(elem);
                }
            }
            if (curr.empty()) {
                ++ret;
                swap(curr, next);
            }
        }
        return -1;
    }

private:
    bool check_path(const string& a, const string& b)
    {
        bool changed = false;
        for (int i = 0; i < 8; ++i) {
            if (a[i] == b[i])
                continue;
            else if (changed)
                return false;
            else
                changed = true;
        }
        return true;
    }
};
