#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    string longestWord(vector<string>& words)
    {
        unordered_set<string> st(words.begin(), words.end());
        auto cmp = [](const string& a, const string& b) {
            if (a.size() != b.size())
                return a.size() > b.size();
            else
                return a < b;
        };
        auto vaild = [&st](const string& a) -> bool {
            for (int i = 1; i < a.size(); ++i) {
                if (st.find(a.substr(0, i)) == st.end())
                    return false;
            }
            return true;
        };
        sort(words.begin(), words.end(), cmp);
        for (const auto& elem : words) {
            if (vaild(elem))
                return elem;
        }
        return string {};
    }
};
