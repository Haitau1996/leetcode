// 简单题， 就是用一个哈希表去重
// 我的做法是在一个函数中处理 name
// 更好的做法是遍历字母， 如果 + 和 @ 就 break, 遇到 . 就 contiune, 其他结果就加到 name 中
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
class MySolution {
public:
    int numUniqueEmails(vector<string>& emails)
    {
        istringstream ss {};
        unordered_set<string> buffer;
        for (const auto& email : emails) {
            ss = istringstream(email);
            string name;
            getline(ss, name, '@');
            name = handle(name);
            string host;
            getline(ss, host, ' ');
            buffer.insert(name + "@" + host);
        }
        return buffer.size();
    }

private:
    string handle(string& in)
    {
        auto new_end = remove(in.begin(), in.end(), '.');
        in.erase(new_end, in.end());
        new_end = find(in.begin(), in.end(), '+');
        in.erase(new_end, in.end());
        return in;
    }
};
class BetterSolution {
public:
    int numUniqueEmails(vector<string>& emails)
    {
        unordered_set<string> res {};
        for (const auto& email : emails) {
            string name {};
            for (const auto& c : email) {
                if (c == '+' || c == '@') {
                    break;
                } else if (c == '.') {
                    continue;
                } else {
                    name.push_back(c);
                }
            }
            res.insert(name + email.substr(email.find('@')));
        }
        return res.size();
    }
};
