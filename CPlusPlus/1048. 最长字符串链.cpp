// 使用动态规划， dp[i] 表示以 words[i] 结尾的最长字符串链的长度
// 同时使用双指针， 对不同长度的字符串划分范围
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int longestStrChain(vector<string>& words)
    {
        auto cmp = [](const string& a, const string& b) {
            return a.size() < b.size();
        };
        int size = words.size();
        sort(words.begin(), words.end(), cmp);
        vector<int> dp(words.size(), 1);
        int low = 0;
        int mid = 0;
        int high = 0;
        while (high < size) {
            while (mid < size && words[mid].size() == words[low].size()) {
                ++mid;
            }
            high = mid;
            while (high < size && words[high].size() == words[mid].size()) {
                int local_max = 0;
                for (int i = low; i < mid; ++i) {
                    if (check(words[i], words[high]) && dp[i] > local_max) {
                        local_max = dp[i];
                    }
                }
                dp[high] = local_max + 1;
                ++high;
            }
            low = mid;
            mid = high;
        }
        return *max_element(dp.begin(), dp.end());
    }

private:
    bool check(const string& low, const string& high)
    {
        int diff = 0;
        int cursor = 0;
        while (cursor < low.size()) {
            if (low[cursor] == high[cursor + diff]) {
                ++cursor;
            } else if (diff)
                return false;
            else {
                ++diff;
            }
        }
        return true;
    }
};
