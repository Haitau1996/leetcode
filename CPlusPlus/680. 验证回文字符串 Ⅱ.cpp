#include <string>

using namespace std;
class Solution {
public:
    bool validPalindrome(string s)
    {
        int low = 0;
        int high = s.size() - 1;
        while (low < high) {
            if (s[low] == s[high]) {
                ++low;
                --high;
            } else
                return isPalin(s, low + 1, high) || isPalin(s, low, high - 1);
        }
        return true;
    }

private:
    bool isPalin(const string& s, int low, int high)
    {
        while (low < high) {
            if (s[low] != s[high])
                return false;
            ++low;
            --high;
        }
        return true;
    }
};
