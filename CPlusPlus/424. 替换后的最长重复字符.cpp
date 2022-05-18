// 双指针， 没有什么别的
class Solution {
public:
    int characterReplacement(string s, int k)
    {
        vector<int> char_count(26, 0);
        int max_count { 0 };
        char curr_char = '\0';
        int low = 0;
        int high = 0;
        int res { 0 };
        while (high < s.size()) {
            while (high < s.size() && high - low - max_count <= k) {
                char_count[s[high] - 'A']++;
                if (char_count[s[high] - 'A'] > max_count) {
                    max_count = char_count[s[high] - 'A'];
                }
                ++high;
                if (high - low - max_count <= k && high - low > res) {
                    res = high - low;
                }
            }
            char_count[s[low++] - 'A']--;
            max_count = *max_element(char_count.begin(), char_count.end());
        }
        return res;
    }
};
