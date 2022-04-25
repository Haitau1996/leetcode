#include <string>

using namespace std;
class Solution {
public:
    string reverseStr(string s, int k)
    {
        int low = 0;
        int mid = 0;
        int high = 0;
        while (low < s.size() && mid < s.size() && high < s.size()) {
            mid = min(low + k - 1, (int)s.size() - 1);
            swap_in_range(s, low, mid);
            high = min(low + 2 * k - 1, (int)s.size() - 1);
            low = high + 1;
        }
        return s;
    }

private:
    void swap_in_range(string& s, int left, int right)
    {
        while (left < right) {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
};
