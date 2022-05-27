/*
 * 要特别注意， 没有说明只有小写字母， 就要考虑所有的 ascii
 * ascii 有 128 个元素， 如果记不住可以使用 unordered_map
 *
 */
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> hash(128, -1);
        int res { 0 };
        int sz = static_cast<int>(s.size());
        int low = 0;
        int high = 0;
        while (low < sz && high < sz) {
            if (hash[s[high]] < low) {
                hash[s[high++]] = high;
                res = max(res, high - low);
            } else {
                low = hash[s[high]] + 1;
            }
        }
        return res;
    }
};
