#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs)
    {
        unordered_map<string, bool> type_buffer;
        unordered_map<string, int> num_log_index {};
        int num_index { 0 };
        for (const auto& elem : logs) {
            auto log_t = log_type(elem);
            type_buffer.emplace(elem, log_t);
            if (log_t) {
                num_log_index.emplace(elem, num_index);
                ++num_index;
            }
        }
        auto cmp = [this, &type_buffer, &num_log_index](const string& a, const string& b) {
            if (type_buffer[a] != type_buffer[b]) {
                if (type_buffer[a])
                    return false;
                else
                    return true;
            } else if (type_buffer[a]) {
                return num_log_index[a] < num_log_index[b];
            } else
                return str_cmp(a, b);
        };
        sort(logs.begin(), logs.end(), cmp);
        return logs;
    }

private:
    bool log_type(const string& s)
    {
        int cursor = 0;
        while (s[cursor] != ' ') {
            ++cursor;
        }
        ++cursor;
        return isdigit(s[cursor]);
    }
    bool str_cmp(const string& a, const string& b)
    {
        int cursora = 0;
        while (a[cursora] != ' ') {
            ++cursora;
        }
        string a_head = a.substr(0, cursora - 1);
        string a_cont = a.substr(cursora + 1);
        int cursorb = 0;
        while (b[cursorb] != ' ') {
            ++cursorb;
        }
        string b_head = b.substr(0, cursorb - 1);
        string b_cont = b.substr(cursorb + 1);
        if (a_cont != b_cont) {
            return a_cont < b_cont;
        } else
            return a_head < b_head;
    }
};
