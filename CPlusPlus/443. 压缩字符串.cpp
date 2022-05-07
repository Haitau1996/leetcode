#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int compress(vector<char>& chars)
    {
        vector<char> next {};

        int left = 0;
        int right = 0;
        while (left < chars.size()) {
            while (right < chars.size() && chars[right] == chars[left]) {
                ++right;
            }
            if (right - left == 1) {
                next.push_back(chars[left]);
            } else {
                string temp = to_string(right - left);
                next.push_back(chars[left]);
                for (const auto& c : temp) {
                    next.push_back(c);
                }
            }
            left = right;
        }
        chars = next;
        return next.size();
    }
};
